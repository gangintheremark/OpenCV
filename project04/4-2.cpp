#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// RGB => HIS
void main() {
	Mat image = imread("rainbow.png", IMREAD_COLOR);
	Mat HSV;

	cvtColor(image, HSV, COLOR_BGR2HSV);

	Mat yellow_mask, yellow_img;  // 노란색(특정 색) 검출

	Scalar lower_yellow = Scalar(20, 20, 100);
	Scalar upper_yellow = Scalar(32, 255, 255);

	inRange(HSV, lower_yellow, upper_yellow, yellow_mask);
	bitwise_and(image, image, yellow_img, yellow_mask);

	imshow("Original", image);
	imshow("yellow_image", yellow_img);
	imshow("yellow_mask", yellow_mask);
	waitKey(0);
}
