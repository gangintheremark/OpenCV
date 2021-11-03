#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// 가우시안 스무딩 필터
void main() {
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result;

	GaussianBlur(image, result, Size(), 3); 

	imshow("Original image", image);
	imshow("Result image", result);
		
    waitKey(0);
}

