#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// 가우시안 잡음 생성 후 LPF 사용하여 잡음 제거 
void main()
{
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat noise_image;
	Mat result;

	Mat noise(image.size(), CV_32SC1);
	randn(noise, 0, 20);

	add(image, noise, noise_image, Mat(), CV_8U); 

	medianBlur(noise_image, result, 5);
	 

	imshow("Original image", image);
	imshow("Noise image", noise_image);
	imshow("Result image", result);

	waitKey(0);
}
