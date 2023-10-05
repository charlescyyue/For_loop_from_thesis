# 从github网站爬取C语言代码
#### content crawler使用说明
- 环境配置：需要安装requests、bs4、os、json四个库

- 首先在第127行url处，写入想要爬取的github库的网址
    如`"https://github.com/begeekmyfriend/leetcode/tree/master"`

- 然后在第126行loc处，写入想要将爬取的代码存储的文件夹地址

- 然后直接运行即可

#### 运行结果
- 代码会在loc指定的文件夹中生成以github库名为名的文件夹，爬取的代码将存储在此文件夹中
- 代码文件命名为folderA_folderB_..._filename.c，其中folderA、folderB等是github库的子文件夹

#### 其它功能
content crawler不仅可以爬取以.c为结尾的代码，只需要稍作修改，即可爬取任意后缀的代码。操作方法为：
在第88行、第92行和第113行中，将".c"改成想要的后缀（如".h"）即可