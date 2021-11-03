#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// RGB -> YCbCr
void main() {
	Mat image = imread("flower.png", IMREAD_COLOR);

	Mat RGB_separated(image.rows, image.cols * 3, CV_8UC3);
	Mat YCBCR_img(image.rows, image.cols * 3, CV_8UC3);

	int Y, Cb, Cr, Red, Green, Blue;

	for (int i = 1; i < image.rows; i++) {
		for (int j = 1; j < image.cols; j++) {
			RGB_separated.at<Vec3b>(i, j)[0] = image.at<Vec3b>(i, j)[0];
			RGB_separated.at<Vec3b>(i, j)[1] = 0;
			RGB_separated.at<Vec3b>(i, j)[2] = 0;

			RGB_separated.at<Vec3b>(i, j + image.cols)[0] = 0;
			RGB_separated.at<Vec3b>(i, j + image.cols)[1] = image.at<Vec3b>(i, j)[1];
			RGB_separated.at<Vec3b>(i, j + image.cols)[2] = 0;

			RGB_separated.at<Vec3b>(i, j + image.cols * 2)[0] = 0;
			RGB_separated.at<Vec3b>(i, j + image.cols * 2)[1] = 0;
			RGB_separated.at<Vec3b>(i, j + image.cols * 2)[2] = image.at<Vec3b>(i, j)[2];;

			Red = (int)image.at<Vec3b>(i, j)[2];
			Green = (int)image.at<Vec3b>(i, j)[1];
			Blue = (int)image.at<Vec3b>(i, j)[0];

			Red &= 0xff, Green &= 0xff, Blue &= 0xff;

			Y = 0.299 * Red + 0.587 * Green + 0.114 * Blue;
			Cb = 0.564 * (Blue - Y);
			Cr = 0.713 * (Red - Y);

			Y = (int)((Y > 0) ? Y : 0); Y = (int)((Y < 255) ? Y : 255);
			Cb = (int)((Cb > 0) ? Cb : 0); Cb = (int)((Cb < 255) ? Y : 255);
			Cr = (int)((Cr > 0) ? Cr : 0); Cr = (int)((Cr < 255) ? Cr : 255);

			YCBCR_img.at<Vec3b>(i, j)[0] = Y;
			YCBCR_img.at<Vec3b>(i, j)[1] = Y;
			YCBCR_img.at<Vec3b>(i, j)[2] = Y;

			YCBCR_img.at<Vec3b>(i, j + image.cols)[0] = Cb;
			YCBCR_img.at<Vec3b>(i, j + image.cols)[1] = Cb;
			YCBCR_img.at<Vec3b>(i, j + image.cols)[2] = Cb;

			YCBCR_img.at<Vec3b>(i, j + image.cols * 2)[0] = Cr;
			YCBCR_img.at<Vec3b>(i, j + image.cols * 2)[1] = Cr;
			YCBCR_img.at<Vec3b>(i, j + image.cols * 2)[2] = Cr;
		}
	}
	imshow("image", image);
	imshow("rgbSepeartedimg", RGB_separated);
	imshow("ycbcrimg", YCBCR_img);
	waitKey();
