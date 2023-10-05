
from paddleocr import PaddleOCR
import datetime
import os
import fitz  # fitz就是pip install PyMuPDF


def pyMuPDF_fitz(pdfPath, imagePath):
    startTime_pdf2img = datetime.datetime.now()  # 开始时间

    print("imagePath=" + imagePath)
    pdfDoc = fitz.open(pdfPath)
    for pg in range(pdfDoc.page_count):
        page = pdfDoc[pg]
        rotate = int(0)
        # 此处若是不做设置，默认图片大小为：792X612, dpi=96
        zoom_x = 4.5  # (1.33333333-->1056x816)   (2-->1584x1224)
        zoom_y = 4.5
        mat = fitz.Matrix(zoom_x, zoom_y).prerotate(rotate)
        pix = page.get_pixmap(matrix=mat, alpha=False)

        if not os.path.exists(imagePath):  # 判断存放图片的文件夹是否存在
            os.makedirs(imagePath)  # 若图片文件夹不存在就创建

        pix.save(imagePath + '/' + 'images_%s.png' % pg)  # 将图片写入指定的文件夹内

    endTime_pdf2img = datetime.datetime.now()  # 结束时间
    print('pdf2img时间=', (endTime_pdf2img - startTime_pdf2img).seconds)


if __name__ == "__main__":
    # 1、PDF地址
    pdfPath = '/Users/wanglibin/Desktop/2000-Unroll-and-jam for imperfectly-nested loops in DSP applications.pdf'
    pdfDoc = fitz.open(pdfPath)
    # 2、需要储存图片的目录
    imagePath = '/Users/wanglibin/Desktop/picture'
    pyMuPDF_fitz(pdfPath, imagePath)

ocr = PaddleOCR(use_angle_cls=True, lang='en')


def extraction(res):
    list = res.copy()
    str_1 = ""
    str_2 = "------------------------------------"
    for num in range(len(res)):
        res[num][1][0].strip()
        if res[num][0][3][0] < res[num - 1][0][2][0] and res[num][0][3][1] > res[num - 1][0][2][1]:
            str_1 = str_1 + '\n' + res[num][1][0]
            list.remove(res[num])
    file_name = pdfPath[0:-4]+".txt"
    with open(file_name, 'a', encoding='utf-8') as f:
        f.write(str_1)
        f.write("\n"+str_2)
    f.close()
    return list


for pg in range(pdfDoc.page_count): # 由转化的pdf本身的页码数决定，第一页为0
    img_path = '/Users/wanglibin/Desktop/picture/images_%s.png' % pg   # 地址需要根据实际情况进行修改
    file_name = pdfPath[0:-4]+".txt"
    str = "The new page is: %s" % pg
    with open(file_name, 'a', encoding='utf-8') as f:
        f.write('\n'+'--------------'+str+'--------------'+'\n')
    f.close()
    result = ocr.ocr(img_path, cls=True)  # 只需运行一次即可下载模型并将其加载到内存中（使用pycharm）
    for idx in range(len(result)):
        res = result[idx]
        list_1 = extraction(res)
        if list_1 != []:
            list_2 = extraction(list_1)
            if list_2 != []:
                extraction(list_2)








