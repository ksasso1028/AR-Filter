#pragma once
#ifndef detectDNN_h
#define detectDNN_h
#include <opencv2/dnn/dnn.hpp>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

void detectDNN(cv::dnn::Net net, cv::Mat &frame, cv::Mat png);


#endif 


