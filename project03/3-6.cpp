#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// DOG 연산자
void main()
{
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat g1, g2, result;

	GaussianBlur(image, g1, Size(1,1), 0);
	GaussianBlur(image, g2, Size(3,3), 0);

	result = g1 - g2;
	imshow("Original image", image);
	imshow("Result image", result);
	waitKey(0);
}
