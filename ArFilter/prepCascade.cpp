#include "pch.h"
#include "prepCascade.h"

//CONVERT FRAME TO BLACK AND WHITE
//HISTOGRAM EQUALIZATION
//SLIGHT EDGE DETECTION
cv::Mat prepCascade(cv::Mat input) {
	cv::Mat grey(input.size(), CV_8UC1);
	cv::cvtColor(input,grey, cv::COLOR_BGR2GRAY);
	cv::equalizeHist(grey, grey);
	return grey;
}
