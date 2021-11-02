#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

//기본 명암대비 스트레치 기법을 이용한 영상 만들기 
void Stretching(Mat image, Mat& result) {
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

		for (int i = 0; i < image.rows; i++) {
			for (int j = 0; j < image.cols; j++) 
				result.at<uchar>(i, j) = (uchar)(image.at<uchar>(i, j) - lowvalue) * index;	 // 명암대비 스트레치 공식 이용 
		}	
}
void main() {
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result = image.clone();

	Stretching(image, result);

	imshow("Original image", image);
	imshow("result image", result);

	waitKey(0);
