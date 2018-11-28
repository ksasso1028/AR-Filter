// ArFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include"detectAndShow.h"
#include "prepCascade.h"
#include <opencv2/photo.hpp>
;
int main()
{
	//cREATE CAM OBJECT AND OPEN FIRST CAM READY.
	int camera = 0;
	int api = cv::CAP_FFMPEG;
	cv::VideoCapture cam;
	cam.open(camera);
	int height,width;
	height = cam.get(CV_CAP_PROP_FRAME_HEIGHT);
	width = cam.get(CV_CAP_PROP_FRAME_WIDTH);
	std::cout << height<< std::endl;
	std::cout << width << std::endl;


	if (!cam.isOpened()) {
		std::cout << "Cam could not be opened" << std::endl;
	}

	int a = 0;
	
	while (1) {
		cv::Mat frame;
		cv::Mat detect;
	

		a++;
		
		cam.read(frame);
		detect = prepCascade(frame);//converts image to grey normalizes image
		
			detectAndShow(frame, detect);//Detects cascade in grey image and draws filter in color image
		cv::Mat other(frame.size(), CV_8UC1);
			//cv::fastNlMeansDenoisingColored(frame,frame,3,3,3);

		imshow("AR-FILTER", frame);

	
		//add Key event function
		if (cv::waitKey(1) >= 0) break;
	}
		cam.release();
		cv::destroyAllWindows();
		return 0;
	

}