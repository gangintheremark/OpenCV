#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

void main() {
	Mat sample(50, 2, CV_32F);
	Mat dst(256, 256, CV_8UC3);
	Mat labels(50, 1, CV_8UC1);

	for (int y = 0; y < sample.rows; y++) {
		sample.at<float>(y, 0) = (rand() % 255);
		sample.at<float>(y, 1) = (rand() % 255);
	}
	for (int y = 0; y < sample.rows; y++) {
		float x1 = sample.at<float>(y, 0);
		float x2 = sample.at<float>(y, 1);
		circle(dst, Point(x1, x2), 3, Scalar(255, 0, 0));
	}

	Mat result, center;

	result = Mat::zeros(Size(256, 256), CV_8UC3);
	
	kmeans(sample, 2, labels, TermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 10000, 0.0001), 3, KMEANS_PP_CENTERS, center);

	for (int y = 0; y < sample.rows; y++) {
		float x1 = sample.at<float>(y, 0);
		float x2 = sample.at<float>(y, 1);
		int cluster_idx = labels.at<int>(y, 0);
		if (cluster_idx == 0)
			circle(result, Point(x1, x2), 3, Scalar(255, 0, 0));
		else
			circle(result, Point(x1, x2), 3, Scalar(255, 255, 0));
	}
	imshow("dst image", dst);
	imshow("result image", result);

	waitKey(0);
}
