// ArFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
int main()
{
	//cREATE CAM OBJECT AND OPEN FIRST CAM READY.
	VideoCapture cam(0);
	if (!cam.isOpened()) {
		std::cout << "Cam could not be opened" << std::endl;
	}
	
	while (1) {
		Mat frame;
		cam >> frame;
		//NEED TO PROCESS FRAME HERE WITH CASCADES
		//THEN ADD SECOND IMAGE TO OVERLAY
		imshow("AR-FILTER", frame);
		if (waitKey(30)>= 0) break;
		
		
		
	}

	
	cam.release();
	destroyAllWindows();
	return 0;
}

