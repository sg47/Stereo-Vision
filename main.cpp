#include <iostream>
#include <opencv2\opencv.hpp>
#include "stdafx.h"
#include "CameraDS.h"

void main()
{
	int cam_count;
	//������ȡ����ͷ��Ŀ
	cam_count = CCameraDS::CameraCount();
	printf("%d", cam_count);

	CCameraDS camera1;
	CCameraDS camera2;

	cvNamedWindow("Camera1");
	cvNamedWindow("Camera2");

	if (!camera1.OpenCamera(1, false, 320, 240)) //����������ѡ�񴰿ڣ��ô����ƶ�ͼ���͸�
	{
		printf("Can not open camera./n");
		return;
	}

	if (!camera2.OpenCamera(2, false, 320, 240)) //����������ѡ�񴰿ڣ��ô����ƶ�ͼ���͸�
	{
		printf("Can not open camera./n");
		return;
	}
	IplImage *pFrame1, *pFrame2;


	while (1)
	{
		pFrame1 = camera1.QueryFrame();
		pFrame2 = camera2.QueryFrame();

		cvShowImage("Camera1", pFrame1);
		cvShowImage("Camera2", pFrame2);
		if (cvWaitKey(30) == 27)
		{
			break;
		}
	}
}