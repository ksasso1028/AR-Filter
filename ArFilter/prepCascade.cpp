#include "pch.h"
#include "prepCascade.h"

//CONVERT FRAME TO BLACK AND WHITE
//HISTOGRAM EQUALIZATION
//SLIGHT EDGE DETECTION
cv::Mat prepCascade(cv::Mat input) {
	double scale = 5;

	
	cv::Mat grey(input.size(), CV_8UC1);
	cv::Mat smallimg;
	cv::cvtColor(input,grey, cv::COLOR_BGR2GRAY);
	

	cv::resize(grey, smallimg,cv::Size(),(1/scale),(1/scale));

	
	cv::equalizeHist(smallimg, smallimg);
	
	return smallimg;
}
