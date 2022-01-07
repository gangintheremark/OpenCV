#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

void main() {
	Mat image = imread("example2.png", IMREAD_GRAYSCALE);
	Mat erosion, dilation, binary;

	threshold(image, binary, 0, 255, THRESH_BINARY); //이진영상

	erode(binary, erosion, cv::Mat());
	dilate(binary, dilation, cv::Mat());

	imshow("binary image", binary);
	imshow("erosion image", erosion);  // 침식 
	imshow("dilation image", dilation); // 팽창 

	waitKey(0);

} 