#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

//라플라시안 기법
void main() {
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result = Mat(image.size(), CV_8U, Scalar(0));
	
	Laplacian(image, result, CV_8U, 3, (1.0), (0, 0), 4);

	imshow("Original image", image);
	imshow("Result image", result);
	waitKey(0);
}
