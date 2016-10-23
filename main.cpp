
//  main.cpp
//  Camera_Capture
//
//  Created by zhoufan on 15/5/24.
//  Copyright (c) 2015年 zhoufan. All rights reserved.
//


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
    Mat image1=imread("/Users/mac/tupian/hololens.jpg");
    Mat dst,edge,gray;
    dst.create(image1.size(),image1.type());
    cvtColor(image1, gray, COLOR_BGR2GRAY);
    blur(gray, edge, Size(3,3));
    Canny(edge, edge, 3, 3);
    dst=Scalar::all(0);
    image1.copyTo(dst,edge);
    imshow("lee", dst);
    imwrite("/Users/mac/tupian/hololens1.jpg", dst);
    waitKey(0);
    return 0;
}
