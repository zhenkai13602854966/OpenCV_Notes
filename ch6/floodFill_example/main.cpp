/*************************************************************************
	> File Name: main.cpp
	> Author: zhenkai
	> Mail: 996.icu.cn@gmail.com 
	> Created Time: 五  9/ 6 21:39:00 2019
 ************************************************************************/

#include<opencv2/core/core.hpp>
#include<opencv2/imgprco/imgproc.hpp>
#include<opencv2.highgui/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat g_srcImage, g_dstImage, g_grayImage, g_maskImage;
int g_nFillMode = 1; // 漫水填充模式
int g_nLowDifference = 20, g_nUpDifference = 20;	//负差最大值，正差最大值 
int g_nConnectivity = 4;		// 表示floodFill函数标示符低八位的连通知
int g_bIsColor = true;    // 是否为彩色  
