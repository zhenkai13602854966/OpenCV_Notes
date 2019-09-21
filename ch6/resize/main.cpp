/*************************************************************************
	> File Name: main.cpp
	> Author: zhenkai
	> Mail: 996.icu.cn@gmail.com 
	> Created Time: 五  9/20 09:38:16 2019
 ************************************************************************/

#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
	Mat srcImage = imread("../../../Image/1.jpg");
	Mat tmpImage, dstImage1, dstImage2;

	tmpImage = srcImage;

	imshow("SrcImage", srcImage);

	resize(tmpImage, dstImage1, Size(tmpImage.cols / 2, tmpImage.rows / 2), (0, 0), (0, 0), 3);
	resize(tmpImage, dstImage2, Size(tmpImage.cols * 2, tmpImage.rows * 2), (0, 0), (0, 0), 3);

	imshow("1/2 DstImage", dstImage1);
	imshow("2*DstImage", dstImage2);
	waitKey(0);
	return 0;
}
