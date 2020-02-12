#include <opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){
    VideoCapture capture(0);
    Mat frame;
    Mat edge;
    Mat gray;
    while (1)
    {
        capture >> frame;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        Canny(gray,edge, 3, 9, 3);

        imshow("raw img", frame);
        imshow("edge",edge);

        if (waitKey(30) >= 0)
            break;
    }
    return 0;
}
