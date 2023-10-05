# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

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
    # 2、需要储存图片的目录
    imagePath = '/Users/wanglibin/Desktop/picture'
    pyMuPDF_fitz(pdfPath, imagePath)


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
