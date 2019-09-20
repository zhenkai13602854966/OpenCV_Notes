/*************************************************************************
	> File Name: main.cpp
	> Author: zhenkai
	> Mail: 996.icu.cn@gmail.com 
	> Created Time: 五  9/ 6 21:08:23 2019
 ************************************************************************/

#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
	Mat srcImage, dstImage;
	
	srcImage = imread("../1.jpg");
	Rect ccomp;
	floodFill(srcImage, Point(50, 300), Scalar(155, 255, 55), &ccomp, Scalar(20, 20, 20), Scalar(20, 20, 20));
	imshow("SrcImage", srcImage);
	waitKey(0);
	return 0;
}

