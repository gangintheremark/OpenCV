#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// 샤프닝 필터
void main()
{
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result;

	float data[] = {      
		-1, -1, -1,
		-1, 9, -1,
		-1, -1, -1
	};

	Mat filter(3, 3, CV_32FC1, data);
	// CV_32FC 영상의 깊이 

	filter2D(image, result, -1, filter, Point(-1, -1), 4);

	imshow("Original image", image);
	imshow("Result image", result);

	waitKey(0);
}
