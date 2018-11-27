#include"pch.h"
#include "detectAndShow.h"


void detectAndShow(cv::Mat &in,cv::Mat &grey){
	static cv::Scalar colors[]{
	cv::Scalar(0, 0, 255),//Color used to draw box
	cv::Scalar(0,128,255)
	};
	double scale = 1.1;
	std::vector<cv::Rect> objects;//Where results will be stored.
	cv::CascadeClassifier cascade;
	cascade.load("C:/open/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml");
	cascade.detectMultiScale(grey, objects);//Detect objects in grey image

	//For loop to go through detected objects and draw rectangle.
	
		for (std::vector<cv::Rect>::iterator r = objects.begin(); r != objects.end(); ++r) {
			cv::Rect draw=*r;
			cv::rectangle(in, draw, colors[1]);

		}
	}
