#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// 블러링 필터
void main() {
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result;

	blur(image, result, Size(5, 5)); // 3x3 은 Size(3,3)

	imshow("Original image", image);
	imshow("Result image", result);

	waitKey(0);
}
