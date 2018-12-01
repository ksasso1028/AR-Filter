#include"pch.h"
#include "detectAndShow.h"


void detectAndShow(cv::Mat &in,cv::Mat &grey){
	static cv::Scalar colors[]{
	cv::Scalar(0, 0, 255),//Color used to draw box
	cv::Scalar(0,128,255)
	};
	double scale = 5;
	std::vector<cv::Rect> objects;//Where results will be stored.
	std::vector<cv::Rect> objects1;
	cv::CascadeClassifier cascade("C:/open/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml");
	//cv::CascadeClassifier cascade1("C:/open/opencv/sources/data/haarcascades/haarcascade_profileface.xml");
	cascade.detectMultiScale(grey, objects);//Detect objects in grey image
	//cascade1.detectMultiScale(grey, objects1);

	//For loop to go through detected objects an draw rectangle.
	

		//Will use this forloop to draw custom image over ROI, (coordinates of object)
		for (std::vector<cv::Rect>::iterator r = objects.begin(); r != objects.end(); ++r) {
			cv::Rect draw = *r;
			draw.x=(draw.x*scale);
			draw.y = (draw.y*scale);
			draw.width= (draw.width*scale);
			draw.height = (draw.height*scale);
			cv::rectangle(in, draw, colors[1]);

		}
		for (std::vector<cv::Rect>::iterator r1 = objects1.begin(); r1 != objects1.end(); ++r1) {
			cv::Rect draw1 = *r1;
			draw1.x = (draw1.x*scale);
			draw1.y = (draw1.y*scale);
			draw1.width = (draw1.width*scale);
			draw1.height = (draw1.height*scale);
			cv::rectangle(in, draw1, colors[1]);

		}
	}
