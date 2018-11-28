#pragma once
#ifndef detectAndShow_h
#define detectAndShow_h

#include<iostream>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include<vector>


//add variables here that i will use in function
//PNG SHOULD BE PRE  LOADED
//before adding more functions need to optimize runtime.
void detectAndShow(cv::Mat &in,cv::Mat &grey);

 
#endif