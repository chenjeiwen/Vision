// test1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

#define WINDOW_NAME "�����Ի��ʵ����"

//ȫ�ֱ�������
const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

//�����洢ͼ��ı���
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_srcImage;

//��Ӧ�������Ļص�����
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
		printf("��ȡ��һ��ͼ������ȷ��Ŀ¼");
		return -1;
	}
	if (!g_srcImage2.data)
	{
		printf("��ȡ�ڶ���ͼ������ȷ��Ŀ¼");
		return -1;
	}

	g_nAlphaValueSlider = 70;
	namedWindow(WINDOW_NAME, 1);
	char TrackbarName[50];
	sprintf_s(TrackbarName, "͸��ֵ %d", g_nMaxAlphaValue);

	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
	on_Trackbar(g_nAlphaValueSlider, 0);

	cout << getTrackbarPos(TrackbarName, WINDOW_NAME) << endl;*/

	//Mat image = imread("E://MyCsharp//image//lena512color.tiff");
	//namedWindow("��ֵ�˲���ԭͼ��");
	//namedWindow("��ֵ�˲���Ч��ͼ0��");
	//namedWindow("��ֵ�˲���Ч��ͼ��");

	//imshow("��ֵ�˲���ԭͼ��", image);

	//Mat out0;
	//Mat out;
	//
	//GaussianBlur(image, out0, Size(3, 3), 0,0);
	//imshow("��ֵ�˲���Ч��ͼ0��", out0);
	//
	////bilateralFilter(out0, out, 3, 3*2, 3/2);
	//Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	//dilate(image, out, element);

	//imshow("��ֵ�˲���Ч��ͼ��", out);
	/*Mat srcImage = imread("E://MyCsharp//image//wen.jpg",0);
	imshow("Origin", srcImage);

	Mat dstImage = Mat::zeros(srcImage.rows, srcImage.cols, CV_8UC3);

	srcImage = srcImage > 120;
	imshow("ȡ��ֵ���ԭʼͼ", srcImage);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(srcImage, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

	int index = 0;
	for (; index >= 0; index = hierarchy[index][0])
	{
		Scalar  color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dstImage, contours, index, color, -1, 8, hierarchy);
		
	}
	imshow("����ͼ", dstImage);*/
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

