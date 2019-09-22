/*************************************************************************
	> File Name: main.cpp
	> Author: zhenkai
	> Mail: 996.icu.cn@gmail.com 
	> Created Time: 日  9/22 15:56:54 2019
 ************************************************************************/

/*最小二乘法多项式曲线拟合，是常见的曲线拟合方法，有着广泛的应用，这里在借鉴最小二乘多项式曲线拟合原理与实现的原理的基础上，介绍如何在OpenCV来实现基于最小二乘的多项式曲线拟合。*/

#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

bool polynomial_curve_fit (vector<Point> &key_point, int n, Mat &A){
	// number of points
	int N = key_point.size();
	
	// 构造矩阵X
	Mat X = Mat::zeros(n+1, n+1, CV_64FC1);
	for (int i = 0; i < n+1; i++){
		for (int j = 0; j < n+1; j++){
			for (int k = 0; k < N; k++){
				X.at<double>(i, j) = X.at<double>(i, j) + pow(key_point[k].x, i + j);
			}
		}
	}

	// 构造矩阵Y
	Mat Y = Mat::zeros(n+1, 1, CV_64FC1);
	for (int i = 0; i < n+1; i++){
		for (int k = 0; k < N; k++){
			Y.at<double>(i, 0) = Y.at<double>(i, 0) + pow(key_point[k].x, i) * key_point[k].y;
		}
	}

	A = Mat::zeros(n + 1, 1, CV_64FC1);
	solve(X, Y, A, DECOMP_LU);
	return true;
}

int main()
{
	Mat image = Mat::zeros(480, 640, CV_8UC3);
	image.setTo(Scalar(248, 248, 255));
	vector<Point>points;
	points.push_back(Point(100., 58.));
	points.push_back(Point(150., 70.));
	points.push_back(Point(200., 90.));
	points.push_back(Point(252., 140.));
	points.push_back(Point(300., 220.));
	points.push_back(Point(350., 400.));
	
	for (int i = 0; i < points.size(); i++){
		circle(image, points[i], 1, Scalar(0, 0, 255), 2, 8, 0);
	}

	polylines(image, points, false, Scalar(0, 255, 0), 1, 8, 0);

	Mat A;
	polynomial_curve_fit(points, 3, A);
	cout << "A=" << A << endl;
	
	vector<Point>points_fitted;
	for (int x = 0; x < 400; x++){
		double y = A.at<double>(0, 0) + A.at<double>(1, 0) * x + A.at<double>(2, 0) * pow(x, 2) + A.at<double>(3, 0) * pow(x, 3);
		points_fitted.push_back(Point(x, y));
	}
	
	polylines(image, points_fitted, false, Scalar(255, 0, 0), 1, 8, 0);
	imshow("image", image);
	waitKey(0);
	return 0;
}


