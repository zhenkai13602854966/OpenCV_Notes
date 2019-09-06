/*************************************************************************
	> File Name: main.cpp
	> Author: zhenkai
	> Mail: 996.icu.cn@gmail.com 
	> Created Time: 五  9/ 6 20:45:57 2019
 ************************************************************************/

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
	Mat srcImage, dstImage, element;

	srcImage = imread("../../../Image/1.jpg");

	element = getStructuringElement(MORPH_RECT, Size(15, 15));
	morphologyEx(srcImage, dstImage, MORPH_GRADIENT, element);

	imshow("SrcImage", srcImage);
	imshow("DstImage", dstImage);

	waitKey(0);
	return 0;
}
