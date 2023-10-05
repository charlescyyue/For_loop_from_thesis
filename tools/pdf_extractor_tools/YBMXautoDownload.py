import base64
import requests
from time import sleep

import pandas as pd
import glob
import os
import pyautogui
import PySimpleGUI
from PIL import Image
import pytesseract


# print(pyautogui.position())


# pyautogui.moveTo(557, 1063)
# pyautogui.click()
# sleep(5)
# pyautogui.moveTo(308, 14)
# pyautogui.click()
# sleep(5)
# pyautogui.moveTo(137, 85)
# pyautogui.click()
# sleep(5)
# pyautogui.moveTo(1236, 450)
# pyautogui.doubleClick()
# pyautogui.typewrite('13348951550')
#
# pyautogui.moveTo(1245, 501)
# pyautogui.click()
# pyautogui.screenshot(imageFilename=r"C:\Users\user\Desktop\majingtmp\image.PNG")
# im = Image.open("C:\\Users\\user\\Desktop\\majingtmp\\image.PNG")  # 截取全屏
# img = im.crop((1406, 564, 1483, 600))
# img.save('C:\\Users\\user\\Desktop\\majingtmp\\fetch_date.png')  # 这里就是截取到的验证码图片

# 百度AI开放平台鉴权函数
def get_access_token():
    url = 'https://aip.baidubce.com/oauth/2.0/token'
    data = {
        'grant_type': 'client_credentials',  # 固定值
        'client_id': 'aMC6G5EP31EGQXGqXqp1Q7pd',  # 在开放平台注册后所建应用的API Key
        'client_secret': 'ip249mOCYNwgaGwetbqTlj6HyMa0Pi1r'  # 所建应用的Secret Key
    }
    headers = {
        'Content-Type': 'application/json',
        'Accept': 'application/json'
    }
    res = requests.post(url, data=data, headers=headers)
    res = res.json()
    # print(res)
    access_token = res['access_token']
    return access_token


# fileIMGbeforeHandels = glob.glob('E:\\社保_方长会\\执行程序\\图像识别\\需要识别图片\\*.*')
# if fileIMGbeforeHandels:
#     for fileIMGbeforeHandel in fileIMGbeforeHandels:
#         im = Image.open(fileIMGbeforeHandel)  # 整个图片
#         img = im.crop((732, 814, 1205, 875))  # 只需要图片一部分
#         filename = os.path.basename(fileIMGbeforeHandel)
#         img.save('E:\\社保_方长会\\执行程序\\图像识别\\图像处理后\\' + filename)

general_word_url = "https://aip.baidubce.com/rest/2.0/ocr/v1/accurate_basic"
#获取执行路径
# path = os.getcwd()
# 二进制方式打开图片文件
for pg in range(10,11):      # 由转化的pdf本身的页码数决定，第一页为0
    files = glob.glob('/Users/wanglibin/Desktop/picture/images_%s.png'%pg)
    if files:
        for file in files:
            f = open(file, 'rb')
            img = base64.b64encode(f.read())
            # print(img)
            params = {"image": img, "language_type": "CHN_ENG"}
            access_token = get_access_token()
            request_url = general_word_url + "?access_token=" + access_token
            # print(request_url)
            headers = {'content-type': 'application/x-www-form-urlencoded'}
            response = requests.post(request_url, data=params, headers=headers)
            # print(response.json())
            res = response.json()
            if response:
                res = response.json()["words_result"]
                # print(res)
                file_name = "/Users/wanglibin/Desktop/picture/%s.txt" % pg # txt文档保存的文件夹
                with open(file_name, 'a', encoding='utf-8') as f:
                    for j in res:
                        print(j["words"])
                        # f.write(file)
                        f.write(j["words"] + "\n")
                        # f.write("\n")


# pytesseract.pytesseract.tesseract_cmd = 'D:\\Program Files\\Tesseract-OCR\\tesseract.exe'
# testdata_dir_config = '--tessdata-dir "D:\\Program Files\\Tesseract-OCR\\tessdata"'
# image = Image.open('C:\\Users\\user\\Desktop\\mjtmp\\1.png')
# # image = Image.open('C:\\Users\\user\\Desktop\\mjtmp\\image.PNG')
# # image = Image.open('E:\\mj\\私人\\身份证正面.JPG')
#
# # 将图片转化为灰度图像
# image = image.convert('L')
# # 二值化
# threshold = 127
# table = []
# for i in range(256):
#     if i < threshold:
#         table.append(0)
#     else:
#         table.append(1)
# image = image.point(table, '1')
# textCode = pytesseract.image_to_string(image, config=testdata_dir_config, lang='chi_sim')
# print(textCode)
