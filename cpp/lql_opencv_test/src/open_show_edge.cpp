//所有文本，特别是包含中文字符的文本文件，都用utf-8编码

#include <opencv2/opencv.hpp>
#include<iostream>

//这个程序是用来打开摄像头，获取和显示摄像头图像，然后提取边缘


using namespace cv;
using namespace std;

int main()
{
    VideoCapture capture(0);  //声明一个摄像头捕捉的对象，用来获取摄像头图像

    Mat frame;  //定义3个图像类的对象。用来保存图像数据。
    Mat edge;
    Mat gray;

    for(;;)
    {
        capture >> frame;  //调用摄像头捕捉对象capture，使用他的方法 >>, 将摄像头捕捉对象中抓取到的一帧图像，保存到图像对象frame中。
        cvtColor(frame, gray, COLOR_BGR2GRAY);  //将彩色图像frame转换成黑白图像并保存到gray中。
        Canny(gray,edge, 30, 50, 3);   //图像的边缘，是通过相邻像素亮度的差距，来判断是否是边缘。所以更简单的是用黑白图形来判断。彩色的是3个通道，不方便判断。

        imshow("raw img", frame);  //这里是显示图像。前面一个参数是窗口的名字，后面是图像对象，图像对象内部有图片数据。
        imshow("gray",gray);
        imshow("edge",edge);

        if (waitKey(30) >= 0)   //waitKey(30)的功能是，让程序停在waitkey这个函数中30ms的时间，超过30ms且没有键盘上任何键被按下，就返回-1;在30ms内，哪个键被按下，就返回那个键对应的值。
            break;
    }
    return 0;

}
