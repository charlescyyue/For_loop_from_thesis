### Algorithm Description ###
'''
Given a pdf file, we can take out the text in a page in the format of a list of lines.

We locate the For Loop by identifying the "for" statement, and then
check whether the character after "for" is "(" (ignore the space " "). If it is, then
this is very likely to be the start of a For Loop.

After locating and extracting the loop title of the For Loop, we start to specify and extract the loop body.
We use the one-to-one correspondence of "{" and "}" to specify the start and end of for loop.

There are two cases in judging whether a line should be in a loop.
One is no "{" has been detected before, and the other is "{" has been detected.
In the first case, the loop will always end with a ";",
while in the second case the loop will end with "}".

The loops will be stored in a directory whose name is
the same as the name of the pdf file the loop is from.
They are separated into two directories in the directory:
"right" and "wrong".
If the whole For Loop is extracted successfully,
the loop will be stored in "right".
If the loop title was extracted successfully but error occurred
when extracting the loop body, the loop will be stored in "wrong".

Programmed by Chongying Yue, 2023/7/19
'''

import pdfplumber
import os


############################################
######### Definitions of functions #########
############################################

###### Small Bracklet Extractor ######
def s_bracklet_extractor(my_str,i):
    # "(" fount, start extraction
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

    return s_str,s_count
###### End of Small Bracklet Extractor ######



###### For Loop Title Extractor ######
def for_statement_extractor(line,i):
    k = j = line.find('for') # j is The pointer for 'line'
    if j < 0:
        return
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
    s_count = s_extraction[1]

    if s_count > 0: # The extracted bracklet content is incomplete
        if s_str.endswith(";"): # In this case the statement doesn't end in this line. Extract recursively by adding the next line to this line to make it complete.
            thisline = text[i].strip()
            j = thisline.find("//")
            if j >= 0:
                newline = thisline[0:j]
            else:
                newline = thisline
            newline = newline.strip()
            i += 1
            line += (" " + newline)

            for_statement_extraction = for_statement_extractor(line,i)
            if for_statement_extraction == None:
                return
            loop_text = for_statement_extraction[0]
            i = for_statement_extraction[1]
            return loop_text,i
        else:
            return
    if s_str.count(";") != 2: # The extracted content cannot be in For Loop
        return
    # Examination complete, the extracted content can be in For Loop
    loop_text = line[k:]
    #print("for_statement_extractor: loop_text is",loop_text)

    return loop_text,i
###### End of For Loop Title Extractor ######



###### If Statement Extractor ######
def if_statement_extractor(line,i):
    k = j = line.find('if')
    if j < 0:
        return
    j += 2

    # check if 'if' is followed by small bracklet
    while line[j] == ' ':
        j += 1 # ignore the space " "
        if j >= len(line): # Only space after "if"
            break

    if j >= len(line): # only space after "if"
        return
    if line[j] != "(": # this 'if' is not closely followed by a small bracklet
        return
    # Now this 'if' is closely followed by a small bracklet

    # extract the content in the small bracklet
    s_extraction = s_bracklet_extractor(line,j)
    s_str = s_extraction[0]
    s_count = s_extraction[1]

    if s_count > 0: # The extracted bracklet content is incomplete
        thisline = text[i].strip()
        j = thisline.find("//")
        if j >= 0:
            newline = thisline[0:j]
        else:
            newline = thisline
        newline = newline.strip()
        i += 1
        line += (" " + newline)

        if_extraction = if_statement_extractor(line,i)
        if if_extraction == None:
            return
        loop_text = if_extraction[0]
        i = if_extraction[1]
        return loop_text,i
    if s_str.count(";") != 0: # The extracted content cannot be in If statement
        return
    # Examination complete, the extracted content can be in If statement
    loop_text = line[k:]

    return loop_text,i
###### End of If Statement Extractor ######



###### Big Bracklet Counter ######
def b_b_counter(line,b_count):
    for char in line:
        if char == "{":
            b_count += 1
        elif char == "}":
            b_count -= 1
    return b_count
###### End of Big Bracklet Counter ######



###### Loop Text Storer ######
def Loop_text_storer(store_path,filename,page_num,loop_num,loop_text,wrong_code):
    loc = store_path + filename[0:-4] + "/"
    if not os.path.isdir(loc):
        os.mkdir(loc)
    if wrong_code == 0:
        loc = loc + "right" + "/"
    else:
        loc = loc + "wrong" + "/"
    if not os.path.isdir(loc):
        os.mkdir(loc)
    loc = loc  + "P%iN%i" %(page_num+1,loop_num) + ".c"
    with open(loc,'wt',encoding='utf-8') as myfile:
        myfile.write(loop_text)
    print("code stored at",loc)
###### End of Loop Text Storer ######


###################################################
######### End of definitions of functions #########
###################################################



#############################################
########## Directory Specification ##########
#############################################

dir_path = "D:/学习/面向C编译大模型的大规模循环构造技术研究/含代码论文/" # Fill the location of the directory where pdfs are stored here
store_path = "D:/学习/面向C编译大模型的大规模循环构造技术研究/benchmarks/crawled_codes/论文中的for循环代码_test/" # Fill the location of the directory where to store the loops here

f = os.walk(dir_path)
filenames = []
for x in f:
    filenames.extend(x[2])
for i in filenames:
    if not i.endswith(".pdf"):
        filenames.remove(i)

###################################################
########## End of Diretory Specification ##########
###################################################

#filename = "Oil and Water Can Mix - An Integration of Polyhedral and AST-Based Transformations.pdf"

#######################################
######## Start of main program ########
#######################################
non_files = []
all_loop_num = 0
numbers = ["0","1","2","3","4","5","6","7","8","9"]
for filename in filenames:
    pdf_path = dir_path + filename
    this_loop_num = 0
    non_count = 0
    with pdfplumber.open(pdf_path) as pdf_file:
        print("Storing loops from",filename)
        print("This file has",len(pdf_file.pages),"pages.")
        
        for page_num in range(59,60): # len(pdf_file.pages)
            print("Page",(page_num+1))

            ###### Page Text Extraction ######
            print("Extracting page text......")
            the_page = pdf_file.pages[page_num]
            page_text = the_page.extract_words(x_tolerance=6,keep_blank_chars=False,use_text_flow=True)
            text = []
            if len(page_text) == 0:
                continue
            #print(page_text)
            y0 = page_text[0]['doctop']
            for word in page_text:
                y1 = word['doctop']
                diff_y = y1-y0
                tol_y = 1.8
                if diff_y > tol_y or diff_y < -tol_y:
                    text.append("\n")
                text.append(word['text'])
                y0 = y1
                #print(word['text'],"    ",word['top'],"    ",word['doctop'])

            text = " ".join(text)
            text = text.split("\n")
            print("Page text extraction success.\n")
            print(text)
            ###### End of Page Text Extraction ######

            
            ###### For Loop Extraction ######
            loop_num = 0
            i = 0
            while i < len(text)-1: # i is the pointer for "text"
                # Initialization
                i_now = i
                loop_text = ''
                thisline = text[i].strip()
                j = thisline.find("//")
                comment = ""
                if j >= 0:
                    line = thisline[0:j]
                    comment = thisline[j:]
                else:
                    line = thisline
                if line == "":
                    i += 1
                    continue
                while line[0] in numbers: # avoid numbers at the beginning of a line
                    line = line[1:]
                    if len(line) == 0:
                        break
                if len(line) == 0:
                    i += 1
                    continue
                line = line.strip()
                wrong_code = 0

                
                ###### For Loop Title Identification and Extraction ######
                # scan "for" expression of For Loop
                for_statement_extraction = for_statement_extractor(line,i)
                if for_statement_extraction == None: # Not a regular for statement
                    i += 1
                    continue
                else:
                    loop_text = for_statement_extraction[0] + comment + "\n"
                    i = for_statement_extraction[1]
                    loop_num += 1
                    print("For Loop title identified and extracted.\n")
                ###### End of For Loop Title Identification and Extraction ######


                ###### Set up the b_bracklet counter ######
                if line.endswith("{"):
                    b_count = 1
                else:
                    b_count = 0
                i += 1
                ###### End of Setting up the b_bracklet counter ######


                ###### Loop Body Identification and Extraction ######
                print("Identifying Loop body......")
                if b_count == 0: # No "{" identified YET
                    while i < len(text) and b_count == 0: # loop ends with ";"
                        thisline = text[i].strip()
                        j = thisline.find("//")
                        comment = ""
                        if j >= 0:
                            line = thisline[0:j]
                            comment = thisline[j:]
                        else:
                            line = thisline
                        if line == "":
                            i += 1
                            continue
                        while line[0] in numbers:
                            line = line[1:]
                            if len(line) == 0:
                                wrong_code = 1
                                break
                        if len(line) == 0:
                            i += 1
                            continue
                        line = line.strip()
                        i += 1
                        if "for" in line:
                            for_statement_extraction = for_statement_extractor(line,i)
                            if for_statement_extraction == None:
                                wrong_code = 1
                                break
                            loop_text += (for_statement_extraction[0] + comment + "\n")
                            i = for_statement_extraction[1]
                            b_count = b_b_counter(for_statement_extraction[0],b_count)
                            continue
                        elif 'if' in line:
                            if_extraction = if_statement_extractor(line,i)
                            if if_extraction == None:
                                if "=" in line:
                                    while not line.endswith(";") and i < len(text):
                                        loop_text = loop_text + line + " "
                                        b_count = b_b_counter(line,b_count)
                                        thisline = text[i].strip()
                                        j = thisline.find("//")
                                        comment = ""
                                        if j >= 0:
                                            line = thisline[0:j]
                                            comment = thisline[j:]
                                        else:
                                            line = thisline
                                        if line == "":
                                            i += 1
                                            continue
                                        while line[0] in numbers:
                                            line = line[1:]
                                            if len(line) == 0:
                                                wrong_code = 1
                                                break
                                        line = line.strip()
                                        i += 1
                                    loop_text = loop_text + line + comment + "\n"
                                    break
                                else:
                                    wrong_code = 1
                                    break
                            else:
                                loop_text += (if_extraction[0] + comment + "\n")
                                i = if_extraction[1]
                                b_count = b_b_counter(if_extraction[0],b_count)
                                continue
                        elif "=" in line:
                            while not (line.endswith(";") or line.endswith("}")) and i < len(text):
                                loop_text = loop_text + line + " "
                                b_count = b_b_counter(line,b_count)
                                thisline = text[i].strip()
                                j = thisline.find("//")
                                comment = ""
                                if j >= 0:
                                    line = thisline[0:j]
                                    comment = thisline[j:]
                                else:
                                    line = thisline
                                if line == "":
                                    i += 1
                                    continue
                                while line[0] in numbers:
                                    line = line[1:]
                                    if len(line) == 0:
                                        wrong_code = 1
                                        break
                                line = line.strip()
                                i += 1
                            if not (line.endswith(";") or line.endswith("}")):
                                wrong_code = 1
                                break
                            loop_text = loop_text + line + comment + "\n"
                            break
                        elif 'else' in line:
                            loop_text = loop_text + line + comment + "\n"
                        elif '#' in line:
                            loop_text = loop_text + line + comment + "\n"
                        elif '{' in line:
                            loop_text = loop_text + line + comment + "\n"
                        elif '}' in line:
                            if line == "}":
                                loop_text = loop_text + line + comment + "\n"
                            else:
                                j = line.find("}")
                                loop_text = loop_text + line[0:j] + line[j] + comment + "\n"
                        elif line == "":
                            loop_text += "\n"
                        b_count = b_b_counter(line,b_count)



                    if wrong_code == 1: # Not a regular For Loop body
                        Loop_text_storer(store_path,filename,page_num,loop_num,loop_text,wrong_code)
                        print("Loop body extraction failed.\n")
                        continue


                # "{" identified
                while i < len(text) and b_count > 0: # loop ends with "}"
                    thisline = text[i].strip()
                    j = thisline.find("//")
                    comment = ""
                    if j >= 0:
                        line = thisline[0:j]
                        comment = thisline[j:]
                    else:
                        line = thisline
                    if line == "":
                        i += 1
                        continue
                    while line[0] in numbers:
                        line = line[1:]
                        if len(line) == 0:
                            wrong_code = 1
                            break
                    if len(line) == 0:
                        i += 1
                        continue
                    line = line.strip()
                    i += 1
                    if "for" in line:
                        for_statement_extraction = for_statement_extractor(line,i)
                        if for_statement_extraction == None:
                            wrong_code = 1
                            break
                        loop_text += (for_statement_extraction[0] + comment + "\n")
                        i = for_statement_extraction[1]
                        b_count = b_b_counter(for_statement_extraction[0],b_count)
                        continue
                    elif 'if' in line:
                        if_extraction = if_statement_extractor(line,i)
                        if if_extraction == None:
                            if "=" in line:
                                while not line.endswith(";") and i < len(text):
                                    loop_text = loop_text + line + " "
                                    b_count = b_b_counter(line,b_count)
                                    thisline = text[i].strip()
                                    j = thisline.find("//")
                                    comment = ""
                                    if j >= 0:
                                        line = thisline[0:j]
                                        comment = thisline[j:]
                                    else:
                                        line = thisline
                                    if line == "":
                                        i += 1
                                        continue
                                    while line[0] in numbers:
                                        line = line[1:]
                                        if len(line) == 0:
                                            wrong_code = 1
                                            break
                                    line = line.strip()
                                    i += 1
                                loop_text = loop_text + line + comment + "\n"
                            else:
                                wrong_code = 1
                                break
                        else:
                            loop_text += (if_extraction[0] + comment + "\n")
                            i = if_extraction[1]
                            b_count = b_b_counter(if_extraction[0],b_count)
                            continue
                    elif "=" in line:
                        while not (line.endswith(";") or line.endswith("}")) and i < len(text):
                            loop_text = loop_text + line + " "
                            b_count = b_b_counter(line,b_count)
                            thisline = text[i].strip()
                            j = thisline.find("//")
                            comment = ""
                            if j >= 0:
                                line = thisline[0:j]
                                comment = thisline[j:]
                            else:
                                line = thisline
                            if line == "":
                                i += 1
                                continue
                            while line[0] in numbers:
                                line = line[1:]
                                if len(line) == 0:
                                    wrong_code = 1
                                    break
                            line = line.strip()
                            i += 1
                        if not (line.endswith(";") or line.endswith("}")):
                            wrong_code = 1
                            break
                        loop_text = loop_text + line + comment + "\n"
                    elif 'else' in line:
                        loop_text = loop_text + line + comment + "\n"
                    elif '#' in line:
                        loop_text = loop_text + line + comment + "\n"
                    elif '{' in line:
                        loop_text = loop_text + line + comment + "\n"
                    elif '}' in line:
                        if line == "}":
                            loop_text = loop_text + line + comment + "\n"
                        else:
                            j = line.find("}")
                            loop_text = loop_text + line[0:j] + line[j] + comment + "\n"
                    elif line == "":
                        loop_text += "\n"
                    b_count = b_b_counter(line,b_count)
                

                if wrong_code == 1:
                    Loop_text_storer(store_path,filename,page_num,loop_num,loop_text,wrong_code)
                    print("Loop body extraction failed.\n")
                    continue
                ###### End of Loop Body Identification and Extraction ######

                
                ###### Change wrong characters ######
                loop_text = loop_text.replace("∗","*")
                loop_text = loop_text.replace("−","-")
                

                ###### Store the extracted loop ######
                Loop_text_storer(store_path,filename,page_num,loop_num,loop_text,wrong_code)
                print("Loop body extraction success.\n")
                if i == i_now:
                    i += 1
            
            all_loop_num += loop_num
            this_loop_num += loop_num
    if this_loop_num == 0:
        non_files.append(filename)

print(non_files)

print("Number of loops stored in",store_path,"from the given PDFs in",dir_path,"is %d." %all_loop_num)

#####################################
######## End of main program ########
#####################################