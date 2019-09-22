/*************************************************************************
	> File Name: main.cpp
	> Author: zhenkai
	> Mail: 996.icu.cn@gmail.com 
	> Created Time: 日  9/22 14:08:39 2019
 ************************************************************************/

/*访问图像中的像素与图像亮度对比度调整
 *访问图像常用的三种方式：1、使用指针访问；2、使用迭代器访问；3、使用动态地址访问
 *
 */

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat image_bright1(Mat src);
Mat image_bright2(Mat src);
Mat image_bright3(Mat src);


int main()
{
	int c;
	Mat srcImage = imread("../../../Image/1.jpg");
	Mat dstImage1, dstImage2, dstImage3;

	namedWindow("srcImage", 0);
	namedWindow("dstImage1", 0);
	namedWindow("dstImage2", 0);
	namedWindow("dstImage3", 0);

	double time1 = static_cast<double>(getTickCount());
	dstImage1 = image_bright1(srcImage);

	double time2 = static_cast<double>(getTickCount());
	dstImage2 = image_bright2(srcImage);

	double time3 = static_cast<double>(getTickCount());
	dstImage3 = image_bright3(srcImage);

	double time4 = static_cast<double>(getTickCount());

	time1 = (time2 - time1) / getTickFrequency();
	time2 = (time3 - time2) / getTickFrequency();
	time3 = (time4 - time3) / getTickFrequency();
	
	cout << "指针访问像素时间(S)：" << time1 << endl;
	cout << "迭代器访问像素时间(S)：" << time2 << endl;
	cout << "动态地址访问像素时间(S)：" << time3 << endl;

	while(1)
	{
		imshow("原图", srcImage);//显示图像 
		imshow("指针访问像素", dstImage1);//显示图像 
		imshow("迭代器访问像素", dstImage2);//显示图像 
		imshow("动态地址访问像素", dstImage3);//显示图像 
		c = waitKey();
		if (c == 27 || char(c) == 'q' || char(c) == 'Q')//按Q键或者ESC键退出程序 
			break;
	}
	return 0;
}

//使用指针访问像素

Mat image_bright1(Mat src){
	Mat dst;
	int channels = src.channels();
	dst = src.clone();

	for (int i = 0; i < src.rows; i++){
		uchar* p_data1 = src.ptr(i);
		uchar* p_data2 = dst.ptr(i);
		for (int k = 0; k < src.cols * channels; k++){
			p_data2[k] = saturate_cast<uchar>(p_data1[k] + 50);  //输出图像像素=原图像像素+50
		}
	}
	return dst;
}

//使用迭代器访问像素

Mat image_bright2(Mat src){
	Mat dst;
	dst = src.clone();

	Mat_<Vec3b>::iterator it = src.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = src.end<Vec3b>();
	Mat_<Vec3b>::iterator it2 = dst.begin<Vec3b>();

	for (; it != itend; ++it, ++it2){
		for (int i = 0; i < 3; i++){
			(*it2)[i] = saturate_cast<uchar>(2 * (*it)[i]);
		}
	}
	return dst;
}

//使用动态地址访问像素

Mat image_bright3(Mat src){
	Mat dst;
	int channels = src.channels();
	dst = src.clone();

	for (int i = 0; i < src.rows; i++){
		for (int j = 0; j < src.cols; j++){
			for (int k = 0; k < channels; k++){
				dst.at<Vec3b>(i, j)[k] = saturate_cast<uchar>(2 * src.at<Vec3b>(i, j)[k] + 50);
			}
		}
	}
	return dst;

}
