# This program is for the pre-processing process.

import os

dir_path = "D:/学习/面向C编译大模型的大规模循环构造技术研究/benchmarks/crawled_codes/论文中的for循环代码/"
#new_path = "D:/学习/面向C编译大模型的大规模循环构造技术研究/benchmarks/crawled_codes/论文中的for循环代码_f1/"

###### Medium Bracklet Extractor ######
def m_bracklet_extractor(my_str,i):
    # "(" fount, start extraction
    m_str = "["
    s_count = 1
    i += 1
    rep = 0
    while i < len(my_str) and s_count > 0:
        if my_str[i] == "[":
            s_count += 1
            m_str += my_str[i]
        elif my_str[i] == "]":
            s_count -= 1
            m_str += my_str[i]
        elif my_str[i] == ",":
            m_str = m_str + "]["
            rep += 1
        else:
            m_str += my_str[i]
        
        i += 1

    return m_str,i,rep
###### End of Medium Bracklet Extractor ######

folder_list = []
if os.path.exists(dir_path):
    files = os.listdir(dir_path)
    for file in files:
        loc = dir_path + file + "/" + "right" + "/"
        folder_list.append(loc)

#error_files = []
for folder in folder_list:
    if os.path.exists(folder):
        cfiles = os.walk(folder)
        filenames = []
        for x in cfiles:
            filenames.extend(x[2])
        for filename in filenames:
            thisloc = folder + filename
#            try:
            with open(thisloc,encoding="utf-8") as tf:
                loop_code = tf.read()
            
            ### "," replacement with "][" in medium bracklets
            j = 0
            while j < len(loop_code):
                if loop_code[j] == "[":
                    k = j
                    m_extraction = m_bracklet_extractor(loop_code,j)
                    m_str = m_extraction[0]
                    j = m_extraction[1]
                    loop_code = loop_code[0:k] + m_str + loop_code[j:]
                    j += m_extraction[2]
                j += 1
            

            loop_code = "#include <stdio.h>\n#include <math.h>\n\nint main(){\n#pragma scop\n" + loop_code + "\n#pragma endscop\n\nreturn 0;\n}"
#            loop_code = loop_code.strip("int main(){\n#pragma scopint main(){\n#pragma scop")
#            loop_code = loop_code.strip("#pragma endscop\n\nreturn 0;\n}\n#pragma endscop\n\nreturn 0;\n}")
            print("The code stored in %s is:" %thisloc)
            print(loop_code)
            tf = open(thisloc,"wt",encoding="utf-8")
            tf.write(loop_code)
            tf.close()
#            except:
#                error_files.append(thisloc)
#                continue