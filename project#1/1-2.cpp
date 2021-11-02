#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// 반전 영상 만들기 
void main() {
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result = image.clone();
	
	result = 255 - result;

	imshow("Original image", image);
	imshow("result image", result);

	waitKey(0);
}
