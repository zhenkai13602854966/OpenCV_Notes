/*************************************************************************
	> File Name: main.cpp
	> Author: zhenkai
	> Mail: 996.icu.cn@gmail.com 
	> Created Time: 五  9/ 6 17:03:59 2019
 ************************************************************************/

#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("../../../Image/1.jpg");

	namedWindow("SrcImage");
	namedWindow("DstImage");

	imshow("SrcImage", srcImage);

	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat dstImage;
	dilate(srcImage, dstImage, element);

	imshow("DstImage", dstImage);
	waitKey(0);
	return 0;
}
