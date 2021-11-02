#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// 엔드 인 기법을 이용한 영상 만들기 
void end_in(Mat image, Mat& result) {
	int lowvalue = 255, highvalue = 0;

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			if (lowvalue > image.at<uchar>(i, j))
				lowvalue = image.at<uchar>(i, j);
			if (highvalue < image.at<uchar>(i, j))
				highvalue = image.at<uchar>(i, j);
		}

	}
	float index = 255 / (float)(highvalue - lowvalue);

    // 앤드인 공식 이용 

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			if (lowvalue >= image.at<uchar>(i, j))
				result.at<uchar>(i, j) = 0;

			else if (lowvalue <= image.at<uchar>(i, j) && highvalue >= image.at<uchar>(i, j))
				result.at<uchar>(i, j) = (uchar)(image.at<uchar>(i, j) - lowvalue) * index;

			else if (highvalue <= image.at<uchar>(i, j))
				result.at<uchar>(i, j) = 255;
		}
	}
}
void main()
{
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result = image.clone();

	end_in(image, result);

	imshow("Original image", image);
	imshow("result image", result);

	waitKey(0);
}
