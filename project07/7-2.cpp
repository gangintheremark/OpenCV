#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

void main() {
	Mat image = imread("road.png", IMREAD_GRAYSCALE);
	Mat binary;

	threshold(image, binary, 0, 255, THRESH_BINARY | THRESH_OTSU); //이진영상

	Mat open, close;

	morphologyEx(binary, open, MORPH_OPEN, cv::Mat());
	morphologyEx(binary, close, MORPH_CLOSE, cv::Mat());

	imshow("Original image", image);
	imshow("Binary image", binary);
	imshow("open image", open);  // 열림
	imshow("close image", close); // 닫힘 

	waitKey(0);

}
