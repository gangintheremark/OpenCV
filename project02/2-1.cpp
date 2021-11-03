#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

//엠보싱 필터
void main()
{
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result;
	
	float mask[] = { -1,-1,0,-1,0,1,0,1,1 };

	Mat emboss(3, 3, CV_32FC1, mask); 

	filter2D(image, result, -1, emboss, Point(-1, -1), 128);

	imshow("Original image", image);
	imshow("Result image", result);

	waitKey(0);
}
