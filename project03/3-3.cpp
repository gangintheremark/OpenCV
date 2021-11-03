#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

/*로버츠, 프리윗, 소벨 기법*/

// 로버츠 
void Robets(Mat& image, Mat& result, uchar thresh) {
	Mat maskX = (Mat_<double>(3, 3) << 1, 0, 0, 0, 1, 0, 0, 0, 0);  
	Mat maskY = (Mat_<double>(3,3) << 0, 0, -1, 0, 1, 0, 0, 0, 0); 
	
	int offset = 3 / 2;

	for (int i = offset; i < image.rows - offset; ++i) {
		for (int j = offset; j < image.cols - offset; ++j) {
			double sumX = 0;
			double sumY = 0;

			for (int u = -offset; u <= offset; ++u) {
				for (int v = -offset; v <= offset; ++v) {
					sumX += image.at<uchar>(i + u, j + v) * maskX.at < double > (offset + u, offset + v);
					sumY += image.at<uchar>(i + u, j + v) * maskY.at<double>(offset + u, offset + v);
				}
			}
			double magnitude = sqrt(pow(sumY, 2) + pow(sumX, 2));

			result.at<uchar>(i - offset, j - offset) = ((magnitude > thresh) ? 0 : 255);
		}
    }
}

// 프리윗
void Prewitt(Mat& image, Mat& result, uchar thresh) {
	Mat maskX = (Mat_<double>(3, 3) << 1, 0, -1, 1, 0, -1, 1, 0, -1);
	Mat maskY = (Mat_<double>(3, 3) << 1, 1, 1, 0, 0, 0, -1, -1, -1);

	int offset = 3 / 2;

	for (int i = offset; i < image.rows - offset; ++i) {
		for (int j = offset; j < image.cols - offset; ++j) {
			double sumX = 0;
			double sumY = 0;

			for (int u = -offset; u <= offset; ++u) {
				for (int v = -offset; v <= offset; ++v) {
					sumX += image.at<uchar>(i + u, j + v) * maskX.at < double >(offset + u, offset + v);
					sumY += image.at<uchar>(i + u, j + v) * maskY.at<double>(offset + u, offset + v);
				}
			}
			double magnitude = sqrt(pow(sumY, 2) + pow(sumX, 2));

			result.at<uchar>(i - offset, j - offset) = ((magnitude > thresh) ? 0 : 255);
		}}}

void main() {
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat Robets_image = Mat(image.size(), CV_8U, Scalar(0));
	Mat Prewitt_image = Mat(image.size(), CV_8U, Scalar(0));
	Mat Sobel_image = Mat(image.size(), CV_8U, Scalar(0));

	Robets(image, Robets_image, 255);
	Prewitt(image, Prewitt_image, 70);

    //소벨 
	Mat sobelX, sobelY;
	Sobel(image, sobelX, CV_8U, 1, 0);
	Sobel(image, sobelY, CV_8U, 0, 1);

	Sobel_image = abs(sobelX) + abs(sobelY);

	imshow("Original image", image);
	imshow("Robets image", Robets_image);
	imshow("Prewitt image", Prewitt_image);
	imshow("Sobel image", Sobel_image);
	waitKey(0);
}
