#include "pch.h"
#include "detectDNN.h"
#include <iostream>

void detectDNN(cv::dnn::Net net, cv::Mat &frame, cv::Mat png) {

	const size_t inWidth = 150;
	const size_t inHeight = 150;
	const double inScaleFactor = 1.0;
	const float confidenceThreshold = 0.4;
	const cv::Scalar meanVal(50, 109.0, 102.0);
	int frameHeight = frame.rows;
	int frameWidth = frame.cols;

	//LOAD FRAME INTO A BLOB.
#ifdef CAFFE
	cv::Mat inputBlob = cv::dnn::blobFromImage(frame, inScaleFactor, cv::Size(inWidth, inHeight), meanVal, false, false);
#else
	cv::Mat inputBlob = cv::dnn::blobFromImage(frame, inScaleFactor, cv::Size(inWidth, inHeight), meanVal, true, false);
#endif

	//LOAD BLOB INTO DETECTION NET
	net.setInput(inputBlob, "data");
	cv::Mat detection = net.forward("detection_out");

	//LOAD DETECTION MAT INTO ANOTHER MAT THAT IS 4D
	cv::Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

	for (int i = 0; i < detectionMat.rows; i++)
	{
		float confidence = detectionMat.at<float>(i, 2);

		if (confidence > confidenceThreshold)
		{
			//RETRIEVE DETECTION POINTS
			int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frameWidth);
			int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frameHeight);
			int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frameWidth);
			int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frameHeight);
			//CREATE RECTANGLE WITH POINTS
			//cv::rectangle(frame, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(255, 0, 0), 2, 4);
			cv::Rect ROI(cv::Point(x1, y1), cv::Point(x2, y2));

			//std::cout << png.channels() << std::endl;
			cv::Mat mas;
			std::vector<cv::Mat> rgb;
			cv::split(png, rgb);
			if (png.channels() == 4) {
				split(png, rgb);
				cv::Mat cs[3] = { rgb[0],rgb[1],rgb[2] };
				cv::merge(cs, 3, png);
				mas = rgb[3];


				//copyTo(g(cv::Rect(0, 0, f.cols, f.rows)), mas);

				//cv::Mat g=cv::Mat(png,ROI);

				double centerX = ROI.x + .5*(ROI.width - 1);
				double centery = ROI.y + .5*(ROI.height - 1);
			}
				cv::resize(png, png, cv::Size(ROI.width, ROI.height));
				cv::resize(mas, mas, cv::Size(ROI.width, ROI.height));
				png.copyTo(frame(cv::Rect(cv::Point(x1-15, y1+30 ), cv::Point(x2-15, y2+30))), mas);
				//cv::imshow("yea",png  );
		//png.copyTo(frame);
			//std::cout << ROI.area();
			}
		}
	}

