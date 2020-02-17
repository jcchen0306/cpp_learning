# selenium browser driver configuration
#https://sites.google.com/a/chromium.org/chromedriver/home

# tutorial
#https://blog.csdn.net/u011541946/category_6788788_1.html

# browser login info
#http://www.xinshangmeng.com/xsm2/?Version=2019121400

# add worksheet to existing xlsx file
#pip install openpyxl==3.0.1

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.wait import WebDriverWait  
from selenium.webdriver.support import expected_conditions as EC  
from selenium.webdriver.common.by import By  
import time
import pandas as pd
import numpy as np
from os.path import exists
from openpyxl import load_workbook





username = '----'
password = '----'
url = 'http://www.xinshangmeng.com/xsm2/?Version=2019121400'
browser = webdriver.Chrome('D:\my_code\pynb\cigarette_order\chromedriver_win32\chromedriver.exe')
browser.get('http://www.xinshangmeng.com/xsm2/?Version=2019121400')
#browser.maximize_window()
username_input_box = browser.find_element_by_id('username')
password_input_box = browser.find_element_by_id('password')
login_button = browser.find_element_by_id('btn-login')

username_input_box.send_keys(username)
password_input_box.send_keys(password)
login_button.click()

#网页中有js弹窗，需要等待一段时间，等待js代码加载完毕
#选择不修改密码
WebDriverWait(browser,20,0.5).until(EC.presence_of_element_located((By.ID, 'nextModify')))
nextModifyButton = browser.find_element_by_id('nextModify')
nextModifyButton.click()

#系统通知消息窗口关闭
WebDriverWait(browser,20,0.5).until(EC.presence_of_element_located((By.CLASS_NAME, 'btn-close')))
systemMsgCloseButton = browser.find_element_by_class_name('btn-close')
systemMsgCloseButton.click()

#开始点烟订单
orderButton = browser.find_element_by_class_name('nav-order')
orderButton.click()





#烟草品牌企业下拉框点击
optionIndex=0
WebDriverWait(browser,20,0.5).until(EC.presence_of_element_located((By.ID, 'mfrSearch')))
cigaretteSearchSource = browser.find_element_by_id('mfrSearch')
cigaretteSearchSource.find_element_by_xpath('.//option[@value="0"]').click()
#遍历整个表格的每一行
rowIndex=1
rowNum =0
rowName = 'sort_'+ str(rowIndex)

while True:
    try:
        rowObject = browser.find_element_by_id(rowName)
        rowNum=rowNum+1
        rowIndex=rowIndex+1
        rowName = 'sort_'+ str(rowIndex)
        rowObject.find_element_by_xpath(".//span[@class='cgt-col-req-qty']/span/input").send_keys('1')
        #rowObject.find_element_by_xpath(".//span[@class='cgt-col-req-qty']/span/em[@class='adda']").click()
        #rowObject.find_element_by_xpath(".//span[@class='cgt-col-req-qty']/span/em[2]").click()
        if rowNum%10==0:
            print(rowNum)
    except:
        break
print('row number: '+str(rowNum))
#点击用量排序按钮
avaliableSortButton = browser.find_element_by_xpath("*//span[@id='kyl-btn']")
avaliableSortButton.click()#第一次点击，升序
avaliableSortButton.click()#再点击一次，降序

#界面滑动到订单
js2 = "window.scrollTo(0,0)"
browser.execute_script(js2)
time.sleep(5)




#存储数据到表格
#列名: 商品名，可用量，批发价，指导价，商品编码
#通过list构建字典

today = time.strftime("%Y%m%d",time.localtime(time.time()))
today_file_name='订烟可用量-'+today+'.xlsx'
writer_today = pd.ExcelWriter(today_file_name, engine='xlsxwriter')

columns_header=['商品名', '可用量', '批发价', '指导价', '商品编码']

productInd=[]
productName=[]
avaliableNum=[]
batchPrice=[]
salePrice=[]
productId=[]

tableObject = browser.find_element_by_xpath("*//li[@id='sortspan']/ul[@id='newul']")
i=0
while True:
    i=i+1
    try:
        idenStr = ".//li["+str(i)+"]"
        if int(tableObject.find_element_by_xpath(idenStr+"/span[@class='cgt-col-qtl-lmt']").text)>0:
            productInd.append(i)
            productName.append(tableObject.find_element_by_xpath(idenStr).get_attribute('title'))
            avaliableNum.append(tableObject.find_element_by_xpath(idenStr+"/span[@class='cgt-col-qtl-lmt']").text)
            batchPrice.append(tableObject.find_element_by_xpath(idenStr+"/span[@class='cgt-col-price']").text)
            salePrice.append(tableObject.find_element_by_xpath(idenStr+"/span[@class='cgt-col-guide-price']").text)
            productId.append(tableObject.find_element_by_xpath(idenStr+"/span[@class='cgt-col-short-code']").text)
            if i%10 == 0:
                print(i)
        else:
            break
    except:
        break

    
data = {columns_header[0]:productName,
        columns_header[1]:avaliableNum,
        columns_header[2]:batchPrice,
        columns_header[3]:salePrice,
        columns_header[4]:productId
}


dataFrame = pd.DataFrame(data,index=productInd)
dataFrame.to_excel(excel_writer=writer_today,sheet_name='可用量')
writer_today.save()
writer_today.close()
#订单提交后，网页响应变了，重新编程，获取网页表格数据



#追加实际订单到以上表格
#刷出了可用量后，需求量都是1，都会进入到采购单中，所以再点一次“卷烟订货"按钮，更新下网页，就可以取消所有的需求量设定，却保留了可用量设定
#手动提交订单后，跳转到订单结果网页，开始读取订单信息
today = time.strftime("%Y%m%d",time.localtime(time.time()))
year = time.strftime("%Y",time.localtime(time.time()))
everyday_file_name = year+'年度订烟统计.xlsx'
if exists(everyday_file_name):
    book = load_workbook(everyday_file_name)
    writer_everyday = pd.ExcelWriter(everyday_file_name,engine = 'openpyxl')
    writer_everyday.book = book
else:
    writer_everyday = pd.ExcelWriter(everyday_file_name,engine='xlsxwriter')

order_columns_header=['商品名', '订货量','批发价', '指导价', '单品总金额','单品批零价','商品编码']

order_productInd=[]

order_productName=[]
order_orderNum=[]
order_batchPrice=[]
order_salePrice=[]
order_singlePriceTotal=[]
order_singlePriceMargin=[]
order_productId=[]

orderTableObject = browser.find_element_by_xpath("*//table[@id='cgt']/tbody")
i=0
while True:
    i=i+1
    try:
        idenStr = ".//tr["+str(i)+"]"
        order_productName.append(orderTableObject.find_element_by_xpath(idenStr+"/td[3]/a").text)
        order_orderNum.append(int(orderTableObject.find_element_by_xpath(idenStr+"/td[8]").text))
        order_batchPrice.append(float(orderTableObject.find_element_by_xpath(idenStr+"/td[5]").text))
        order_salePrice.append(float(orderTableObject.find_element_by_xpath(idenStr+"/td[6]").text))
        order_singlePriceTotal.append(float(orderTableObject.find_element_by_xpath(idenStr+"/td[9]").text))
        order_singlePriceMargin.append(float(orderTableObject.find_element_by_xpath(idenStr+"/td[10]").text))
        order_productId.append(orderTableObject.find_element_by_xpath(idenStr+"/td[2]").text)
        order_productInd.append(i)
        if i%10 == 0:
            print(i)
    except:
        break


order_data = {order_columns_header[0]:order_productName,
              order_columns_header[1]:order_orderNum,
              order_columns_header[2]:order_batchPrice,
              order_columns_header[3]:order_salePrice,
              order_columns_header[4]:order_singlePriceTotal,
              order_columns_header[5]:order_singlePriceMargin,
              order_columns_header[6]:order_productId,
}

pd_order = pd.DataFrame(order_data,index=order_productInd)
pd_order.to_excel(excel_writer=writer_everyday,sheet_name='订购'+today)

writer_everyday.save()
writer_everyday.close()