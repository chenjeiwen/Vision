// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

#define WINDOW_NAME "【线性混合实例】"

//全局变量声明
const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

//声明存储图像的变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_srcImage;

//响应滑动条的回调函数
static void on_Trackbar(int, void*)
{
 	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
	g_dBetaValue = (1.0 - g_dAlphaValue);
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_srcImage);
	imshow(WINDOW_NAME, g_srcImage);
}

int main()
{
	/*g_srcImage1 = imread("E://MyCsharp//image//2dcode.jpg", 0);
	g_srcImage2 = imread("E://MyCsharp//image//2dcode.jpg", 0);
	if (!g_srcImage1.data)
	{
		printf("读取第一幅图错误，请确定目录");
		return -1;
	}
	if (!g_srcImage2.data)
	{
		printf("读取第二幅图错误，请确定目录");
		return -1;
	}

	g_nAlphaValueSlider = 70;
	namedWindow(WINDOW_NAME, 1);
	char TrackbarName[50];
	sprintf_s(TrackbarName, "透明值 %d", g_nMaxAlphaValue);

	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
	on_Trackbar(g_nAlphaValueSlider, 0);

	cout << getTrackbarPos(TrackbarName, WINDOW_NAME) << endl;*/

	//Mat image = imread("E://MyCsharp//image//lena512color.tiff");
	//namedWindow("均值滤波【原图】");
	//namedWindow("均值滤波【效果图0】");
	//namedWindow("均值滤波【效果图】");

	//imshow("均值滤波【原图】", image);

	//Mat out0;
	//Mat out;
	//
	//GaussianBlur(image, out0, Size(3, 3), 0,0);
	//imshow("均值滤波【效果图0】", out0);
	//
	////bilateralFilter(out0, out, 3, 3*2, 3/2);
	//Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	//dilate(image, out, element);

	//imshow("均值滤波【效果图】", out);
	/*Mat srcImage = imread("E://MyCsharp//image//wen.jpg",0);
	imshow("Origin", srcImage);

	Mat dstImage = Mat::zeros(srcImage.rows, srcImage.cols, CV_8UC3);

	srcImage = srcImage > 120;
	imshow("取阈值后的原始图", srcImage);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(srcImage, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

	int index = 0;
	for (; index >= 0; index = hierarchy[index][0])
	{
		Scalar  color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dstImage, contours, index, color, -1, 8, hierarchy);
		
	}
	imshow("轮廓图", dstImage);*/
	/*Mat srcImage = imread("E://MyCsharp//image//beautygirl.jpg", 1);
	imshow("origin", srcImage);

	Mat srcImage1 = srcImage.clone();
	Mat imageMask = Mat(srcImage.size(), CV_8UC1, Scalar::all(0));
	Mat Kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imageMask, imageMask, Kernel);
	Mat inpaintedImage;

	inpaint(srcImage1, imageMask, inpaintedImage, 1, INPAINT_TELEA);
	imshow("new", inpaintedImage);

	waitKey(0);*/
	VideoCapture capture("E://MyCsharp//image//ABB.mp4");
	if (!capture.isOpened())
	{
		cout << "error" << endl;
		return 1;
	}

	double rate = capture.get(CV_CAP_PROP_FPS);

	bool stop(false);
	Mat frame;
	namedWindow("Extracted Frame");

	int delay = 1000 / rate;

	//while (!stop)
	//{
	//	if (!capture.read(frame))
	//	{
	//		break;
	//	}
	//	imshow("Extracted Frame", frame);

	//	if (waitKey(delay) >= 0)
	//	{
	//		stop = true;
	//	}
	//	
	//}

	capture.set(CV_CAP_PROP_POS_FRAMES, rate - 1);
	capture.read(frame);
	imshow("Extracted Frame", frame);


	capture.release();
	waitKey(0);
    return 0;
}

