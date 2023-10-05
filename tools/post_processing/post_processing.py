### This program is designed for the operation on
### loop codes after generating declarations using psyche-c.
### Also called post-processing.（后处理阶段）


###### libraries and initializations ######
import os


dir_path = "D:/学习/面向C编译大模型的大规模循环构造技术研究/crawling_tools/psychec_results/psychec_result_wqr_/fine_loops_op/fine_loops/"
new_path = "D:/学习/面向C编译大模型的大规模循环构造技术研究/crawling_tools/psychec_results/psychec_result_wqr_/finale_loops/"

if not os.path.exists(new_path):
    os.mkdir(new_path)

# recorded function names and their numbers of parameters in <math.h> to do function mapping in the function replacement step
func_table_math_h = (("acos",1),("asin",1),("atan",1),("atan2",2),("cos",1),("cosh",1),("sin",1),("sinh",1),("tan",1),("tanh",1),("exp",1),("frexp",2),("ldexp",2),("log",1),("log10",1),("modf",2),("pow",2),("powf",2),("sqrt",1),("ceil",1),("fabs",1),("floor",1),("fmod",2),("cabs",1),("poly",3),("hypot",2))
math_func_names = []
math_func_par_nums = []
for func in func_table_math_h:
    math_func_names.append(func[0])
    math_func_par_nums.append(func[1])
math_func_names = tuple(math_func_names)
math_func_par_nums = tuple(math_func_par_nums)

# dataset_size names to be inferred in marco definition generation step
dataset_size_names = ("DATASET_XS","DATASET_S","DATASET_M","DATASET_L","DATASET_XL","DATASET_XXL","DATASET_XXXL")


###### function definitions ######

def s_bracklet_extractor(my_str,i):
    # "(" found, start extraction
    s_str = "("
    s_count = 1
    i += 1
    while i < len(my_str) and s_count > 0:
        if my_str[i] == "(":
            s_count += 1
        elif my_str[i] == ")":
            s_count -= 1
        
        s_str += my_str[i]
        i += 1

    return s_str,i


def comment_eliminator(my_str): # eliminate comments with the format of "/*...*/"
    i = my_str.find("/*") # start of comment
    while i > 0:
        j = my_str.find("*/") + 2 # end of comment
        if j >= len(my_str):
            my_str = my_str[0:i]
        else:
            my_str = my_str[0:i] + my_str[j:]
        i = my_str.find("/*")
    return my_str


# take in the string, function name, replace all the function references
# with the constant 42 and return the new string
def func_extractor(my_str,func):
    new_str = ""
    while my_str.find(func) > 0:
        k = my_str.find(func)
        j = k + len(func)

        new_str += my_str[0:k] + "42"

        while my_str[j] == " ":
            j += 1
        s_bracklet_extraction = s_bracklet_extractor(my_str,j)
        j = s_bracklet_extraction[1]
        my_str = my_str[j:]
    new_str += my_str
    return new_str


def for_cond_extractor(line):
    j = line.find('for') # j is The pointer for 'line'
    j += 3

    if j >= len(line): # nothing after "for"
        return

    # check if "for" is followed by small bracklet
    while line[j] == " ":
        j += 1 # ignore the space " "
        if j >= len(line): # Only space after "for"
            return

    if line[j] != "(": # this 'for' is not closely followed by a small bracklet
        return
    # Now this 'for' is closely followed by a small bracklet

    # extract the content in the small bracklet
    s_extraction = s_bracklet_extractor(line,j)
    s_str = s_extraction[0]
    s_str_list =s_str.split(";")

    return s_str_list[1] # the loop condition


def loop_text_storer(loc,filename,text,bound_code,pragma_code):
    if not os.path.exists(loc):
        os.mkdir(loc)
    
    if bound_code == 0: # the loop boundary variable marco definition is generated successfully, so saved in "bounded" file
        if pragma_code == 0:
            loc = loc + "bounded" + "/"
        else:
            loc = loc + "pragma_error" + "/"
    else: # the loop boundary variable marco definition is not generated, so saved in "unbounded" file
        loc = loc + "unbounded" + "/"

    if not os.path.exists(loc):
        os.mkdir(loc)
    
    loc += filename + ".c"
    with open(loc,'wt',encoding='utf-8') as myfile:
        myfile.write(text)
    print("code stored at",loc)
    

###### END of function definitions ######



###### directory initialization ######

folder_list = []
new_folder_list = []
if os.path.exists(dir_path):
    files = os.listdir(dir_path)
    for file in files:
        loc = dir_path + file + "/"
        new_loc = new_path + file + "/"
        folder_list.append(loc)
        new_folder_list.append(new_loc)

###### END of directory initialization ######



###### header file reader ######

# getting names of passed files by scanning the header files
for i in range(len(folder_list)):#len(folder_list)

    the_old_path = folder_list[i]
    print("old path is:",the_old_path)
    the_new_path = new_folder_list[i]
    print("new path is:",the_new_path)

    if os.path.exists(the_old_path):
        cfiles = os.walk(the_old_path)
        filenames = []
        for x in cfiles:
            filenames.extend(x[2])
        finale_files = []
        for filename in filenames:
            if filename.endswith("_gen.h"):
                filename = filename[0:-6]
                finale_files.append(filename)
        print(finale_files,"\n") # all files whose header file is successfully generated

# loop through single files
        for finale_name in finale_files:
            the_orig_C_file = the_old_path + finale_name + ".c"
            the_C_file = the_old_path + finale_name + "_fixed.c"
            the_h_file = the_old_path + finale_name + "_gen.h"

# getting variable table and function table from header file
            with open(the_h_file,"rt",encoding="utf-8") as h:
                h_code = h.readlines() # content in the header file
            var_and_func_index = h_code.index("/* Variables and functions */\n") # var_and_func_index is the index of the start of the generated variables and functions.
            dec_gen = h_code[var_and_func_index:-1] # dec_gen is the list of the generated declarations
#            print(dec_gen)
            variable_list = []
            func_list = [] # list of (function_name, num_parameter)
            func_index = [] # index of function declaration to be used in the function declaration deletion process
            for dec in dec_gen[1:]: # loop through each generated declaration
                dec_index = dec_gen.index(dec)
                dec = dec.strip()
                if " /*<<< orphan*/ " in dec:
                    dec = dec.replace(" /*<<< orphan*/ ","")
                dec_l = dec.split(" ")
                if dec_l[2] == ";": # a variable
                    variable_list.append((dec_l[1],dec_l[0]))
                elif "(" in dec_l[2]: # a function
                    comma_num = dec_l[2].count(",")
                    if comma_num == 0:
                        if dec_l[2] == "()":
                            num_parameter = 0
                        else:
                            num_parameter = 1
                    elif comma_num > 0:
                        num_parameter = comma_num + 1
                    func_list.append((dec_l[1],num_parameter))
                    func_index.append(dec_index)

#            print("variable list is:",variable_list)
#            print(func_list)


###### goto label removal ######
            with open(the_C_file,"rt",encoding="utf-8") as c:
                c_code = c.readlines()
            #print(c_code,"\n")
            for line_index in range(len(c_code)):
                line = c_code[line_index].strip()
                colon_index = line.find(":")
                if colon_index < 0:
                    c_code[line_index] = line
                    continue
                else:
                    if (" " not in line[0:colon_index]) and ("?" not in line[0:colon_index]):
                        c_code[line_index] = line[colon_index+1:]
                    else:
                        continue
            #print(c_code)



###### function replacement ######
# note that some functions have other variables in its citations, especially some with 
# loop boundary definitions. Those should be treated in another way?
            other_func_list = [] # in relation to "matched functions"
            dec_gen_new = []
            
            if len(func_list) == 0:
                pass
            else:
                for func_name in func_list:
                    if func_name[0] in math_func_names: # check if the extracted function name is in math.h
                        if func_name[1] == math_func_par_nums[math_func_names.index(func_name[0])]: # check if the number of parameters can meet
                            pass # mapping success, no further operation needed
                        else:
                            other_func_list.append(func_name[0])
                    else:
                        other_func_list.append(func_name[0])
            
            if len(other_func_list) > 0:
                for func_name in other_func_list:
                    for line_index in range(len(c_code)):
                        line = c_code[line_index].strip()
                        if func_name in line:
                            c_code[line_index] = func_extractor(line,func_name)
#            print(c_code)

###### loop boundary variable extraction ######
            
            bound_var_list = []
            other_var_list = []

            for line in c_code:
                # delete comments
                if line.find("//") > 0:
                    line = line[0:line.find("//")] # delete the end comment
                line = comment_eliminator(line) # delete the middle comment (in one line)
                # note that c_code is not changed
                if "for" in line:
                    cond_str = for_cond_extractor(line)
                    if cond_str == None: # not a for loop
                        continue
                    for var_tuple in variable_list: # loop through variable_tuples in variable_list
                        if var_tuple in other_var_list: # the variable has been identified as an other variable, so no further detection needed
                            continue
                        var = var_tuple[0]
                        if var == "i" or var == "m" or var == "n" or var == "p" or var == "q":
                            other_var_list.append(var_tuple)
                            continue
                        elif var in cond_str:
                            var_count = line.count(var)
                            if var_count == 1: # boundary variable identified
                                if var not in bound_var_list:
                                    bound_var_list.append(var) ################################### Under Construction
                            else:
                                other_var_list.append(var_tuple)
            # if the var is not in bound_var_list, then put it into other_var_list.
            # There is a possibility that a variable was neither identified as other_var nor identified as bound_var, so a clean-up is necessary.
            for var_tuple in variable_list:
                if var_tuple[0] in bound_var_list:
                    continue
                elif var_tuple not in other_var_list:
                    other_var_list.append(var_tuple)

#            print(bound_var_list)
#            print("other_var_list is:",other_var_list)

###### pointer variable printing ######
            pointer_var_list = []
            for var_tuple in other_var_list:
                star_count = var_tuple[1].count("*")
                if star_count > 0:
                    pointer_var_list.append(var_tuple[0])
#            print(pointer_var_list,"\n")

            pointer_str = ""
            for pointer_var in pointer_var_list:
                pointer_str += 'printf("The value of %s is %%p", %s);\n'%(pointer_var,pointer_var)
#            print(pointer_str)

###### other variable declaration generation ######
            other_var_str = ""
            for other_var in other_var_list:
                other_var_str += "%s %s;\n"%(other_var[1],other_var[0])
#            print("other_var_str is:",other_var_str)

###### marco definition string generation ######
            boundary_code = 0
            if len(bound_var_list) == 0: 
                boundary_code = 1
                dataset_str = "/*Marco definition generation failed.*/\n"
#                print("Boundary variable marco definition generation failed.")
            else:
                dataset_size_str = "# if !defined(DATASET_XS) && !defined(DATASET_S) && !defined(DATASET_M) && !defined(DATASET_L) && !defined(DATASET_XL) && !defined(DATASET_XXL) && !defined(DATASET_XXXL)\n# define DATASET_M\n# endif\n\n"
                
                bound_def_str = "#if "
                for bound_var in bound_var_list:
                    bound_def_str += "!defined(%s)"%bound_var
                    if bound_var_list.index(bound_var) < len(bound_var_list)-1:
                        bound_def_str += " && "
                bound_def_str += "\n"
                
                data_str = ""
                for power in range(4,17,2):
                    num = 2**power
                    data_str += "# ifdef %s\n" %dataset_size_names[int(power/2-2)]
                    for bound_var in bound_var_list:
                        data_str += "# define %s %i\n"%(bound_var,num)
                    data_str += "#endif\n\n"
                
                dataset_str = dataset_size_str + bound_def_str + data_str + "#endif\n\n"
#                print(dataset_str) # marco definition
            


###### piecing parts of a loop file together ######
            date_str = "/*generated in September 2023*/\n\n"
            inclusion_str = "#include <stdio.h>\n#include <math.h>\n\n" # inclusion
            initialization_str = "".join(h_code[:var_and_func_index]) + "\n" # initialization generated in .h file
            dataset_str += "\n" # marco definition
            main_func_head = "int main(){\n" # head of main function structure
            other_var_str += "\n" # normal variable declarations

            pragma_code = 0
            for line_index in range(len(c_code)):
                if "endscop" in c_code[line_index]:
                    pragma_end = line_index
                elif "scop" in c_code[line_index]:
                    pragma_start = line_index
            if pragma_end == len(c_code):
                c_code = c_code[pragma_start:] + ["\n/*This file might have problem with its pragma scop area!*/\n"]
                pragma_code = 1
            else:
                c_code = c_code[pragma_start:pragma_end+1]
            c_code = "\n".join(c_code)
            c_code += "\n" # loop body

            pointer_str += "\n" # printing pointers
            main_func_end = "return 0;\n}"

            finale_file_text = date_str + inclusion_str + initialization_str + dataset_str + main_func_head + other_var_str  + c_code  + pointer_str + main_func_end
#            print(finale_file_text)
            loop_text_storer(the_new_path,finale_name,finale_file_text,boundary_code,pragma_code)

print("Post operation success.")