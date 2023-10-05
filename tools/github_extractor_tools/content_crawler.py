### content_crawler.py ###
### Programmed by Chongying Yue and Libin Wang.
### Supported by Cai et. al.
### Programmed and tested on 07/13/2023.
### Fill the main website of a github repository into 'url' (line 127), and the location to store the code into 'loc' in get_code_from_url (line 126),
### this program will crawl C codes from the github repository and store them in the location specified by 'loc'. Note that the location folder should be created beforehand.
### The files are named by the repo branch of the files followed by the original file name.

import requests
from bs4 import BeautifulSoup
import os
import json



def get_code_from_url(url): # url is the url of a github website containing code.

    #define a header to avoid error
    user_agent = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.0.7) Gecko/2009021910 Firefox/3.0.7'
    header={'User-Agent':user_agent,}

    #building up a crawler using GET
    content = requests.get(url=url, headers=header).text # get website source code and store in content
    content = json.loads(content)
    my_code = content['payload']['blob']['rawLines']

    ''' ### The original version
    soup = BeautifulSoup(content,'lxml') # analyze the source code
    res = soup.find_all(name = 'table', attrs={'class':"highlight tab-size js-file-line-container js-code-nav-container js-tagsearch-file"}) # locate and get - first time
    my_info = res[0].find_all(name='tr') # locate and get rows

    #store the text into my_code to get a complete code
    my_code = []
    for line in my_info:
        words = line.find_all(name='td') # locate and get content in one row
        for word in words:
            my_code.append(word.text)
        my_code.append("\n")
    '''

    my_code = "\n".join(my_code)
    #print("The code is: \n"+my_code)

    # store the code into files
    benchname = url.split("/")[4]
    prefix = url.split("/")[6:-1]
    filename = url.split("/")[-1]
    prefix.append(filename)
    filename = "_".join(prefix)
    this_loc = loc + benchname + "\\"
    if not os.path.isdir(this_loc):
        os.mkdir(this_loc)
    this_loc = this_loc + filename
    print("code is stored at",this_loc)
    with open(this_loc,'wt',encoding='utf-8') as myfile:
        myfile.write(my_code)




def get_website_from_url(url): # url is the url of a github content website
    print("Getting urls from given url......")

    #define a header to avoid error
    user_agent = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.0.7) Gecko/2009021910 Firefox/3.0.7'
    header={'User-Agent':user_agent,}

    #building up a crawler using GET
    content = requests.get(url=url, headers=header).text # get website source code and store in content
    try:
        content = json.loads(content)
        res = content['payload']['tree']['items']
        #soup = BeautifulSoup(content,'lxml') # analyze the source code
        #print(soup,"\n")
        #res = soup.find_all(name = 'a', attrs={'class':'Link--primary'}) # locate and get all urls

        print("Urls got. Analyzing urls......")

        for x in res:
            thisurl = x['path']
            content_type = x['contentType']
            url_list = url.split("/")[0:7]

            if content_type == 'file':
                url_list[5] = 'blob'
                url_list.append(thisurl)
                thisurl = "/".join(url_list)
                if thisurl.endswith(".c"):
                    print("blob url is:",thisurl)
                    get_code_from_url(thisurl)
                else:
                    print("Not .c file.")
                    continue

            elif content_type == 'directory':
                url_list.append(thisurl)
                thisurl = "/".join(url_list)
                if url.split("/")[-2] == thisurl[-1]: # got the ".."
                    continue
                print("tree url is:",thisurl)
                get_website_from_url(thisurl)
    
    except:
        soup = BeautifulSoup(content,'lxml') # analyze the source code
        #print(soup,"\n")
        res = soup.find_all(name = 'a', attrs={'class':'js-navigation-open Link--primary'}) # locate and get all urls

        for x in res:
            thisurl = x.attrs['href']
            thisurl = "https://github.com" + thisurl
            thisurl_list = thisurl.split("/")
            if thisurl_list[5] == 'blob':
                if thisurl.endswith(".c"):
                    print("c blob url is:",thisurl)
                    get_code_from_url(thisurl)
                else:
                    continue
            elif thisurl_list[5] == 'tree':
                if url.split("/")[-2] == thisurl_list[-1]:
                    continue
                print("tree url is:",thisurl)
                get_website_from_url(thisurl)



loc = "D:\\学习\\面向C编译大模型的大规模循环构造技术研究\\benchmarks\\crawled_codes\\"
url= "https://github.com/shoaibkamil/stencilprobe"
get_website_from_url(url)