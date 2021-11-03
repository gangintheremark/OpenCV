#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// RGB -> CMY 
void main() {
	Mat image = imread("flower.png", IMREAD_COLOR);
	CV_Assert(image.data);

	Scalar white(255, 255, 255);
	Mat CMY_img = white - image; 
	Mat CMY_arr[3];
	split(CMY_img, CMY_arr);

	imshow("Original", image);
	imshow("yellow", CMY_arr[0]);
	imshow("magenta", CMY_arr[1]);
	imshow("Cyan", CMY_arr[2]);

	waitKey(0);
}
