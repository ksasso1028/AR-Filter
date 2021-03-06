// ArFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <vector>
#include <iostream>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include"detectAndShow.h"
#include "prepCascade.h"
#include "detectDNN.h"
using namespace cv;

//LOAD MODELS
#define CAFFE

const std::string caffeConfig = "c:/models/deploy.prototxt";
const std::string caffeWeight = "c:/models/res10_300x300_ssd_iter_140000_fp16.caffemodel";

const std::string tensorflowConfig = "./opencv_face_detector.pbtxt";
const std::string tensorflowWeight = "./opencv_face_detector_uint8.pb";
//LOAD FRAME INTO A BLOB.
//DNN implementation, retreive net model.
#ifdef CAFFE
cv::dnn::Net net = cv::dnn::readNetFromCaffe(caffeConfig, caffeWeight);
#else
cv::dnn::Net net = cv::dnn::readNetFromTensorflow(tensorflowWeight, tensorflowConfig);
#endif
		int main()
		{
			
			//cREATE CAM OBJECT AND OPEN FIRST CAM READY.
			int camera = 0;
			int api = cv::CAP_FFMPEG;
			VideoCapture cam;
			cam.open(camera);
			int height, width;
			
			//filter mat
			

			height = cam.get(CV_CAP_PROP_FRAME_HEIGHT);
			width = cam.get(CV_CAP_PROP_FRAME_WIDTH);
			std::cout << height << std::endl;
			std::cout << width << std::endl;


			if (!cam.isOpened()) {
				std::cout << "Cam could not be opened" << std::endl;
			}
			
			//imshow("wino", png1);
			
			while (1) {
				Mat frame;
				Mat detect;
				frame.convertTo(frame, CV_16SC1);
				cam>>frame;
				std::cout << frame.type();
				
				Mat f;
				f = imread("C:/face/face.png", IMREAD_UNCHANGED);
				if (f.empty())
					//std::cout << "empty";
				std::cout << f.channels();
				
				resize(f, f, Size(frame.cols*.75, frame.rows*.75), 0, 0, CV_INTER_LINEAR);
				
				
				//cv::resize(frame, png, cv::Sze());
				//detect = prepCascade(frame);//converts image to grey normalizes image
				//HAAR CASCADE + LBP METHOD
				//detectAndShow(frame, detect);//Detects cascade in grey image and draws filter in color image
				
				//ADD CONVOLUTION TO IMAGE TO SMOOTh aND SHARP To CREAT FILTER
				
				//DNN detection
				detectDNN(net, frame,f);
				imshow("AR-FILTER", frame);

				//add Key event function
				if (waitKey(1) >= 0) break;
			}
			cam.release();
			destroyAllWindows();
			return 0;


		}
	