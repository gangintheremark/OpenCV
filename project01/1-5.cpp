#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;
// 히스토그램 평활화
void main()
{

	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result;

	int histo[256] = {
		0,
	};

	for (int i = 0; i < image.rows; i++)
	{ // 히스토그램 생성
		for (int j = 0; j < image.cols; j++)
		{
			int value = image.at<uchar>(i, j);
			histo[value] += 1;
		}
	}

	int cumulative_histo[256] = {
		0,
	};
	int sum = 0;

	for (int i = 1; i < 256; i++)
	{ // 누적 히스토그램
		sum += histo[i];
		cumulative_histo[i] = sum;
	}

	float normalized_cumulative_histo[256] = {
		0.0,
	}; // 정규화된 누적 히스토그램
	int image_size = image.rows * image.cols;

	for (int i = 0; i < 256; i++)
		normalized_cumulative_histo[i] = cumulative_histo[i] / (float)image_size;

	result = Mat(image.rows, image.cols, CV_8UC1);
	int result_histo[256] = {
		0,
	};

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			result.at<uchar>(i, j) = normalized_cumulative_histo[image.at<uchar>(i, j)] * 255;
			result_histo[result.at<uchar>(i, j)] += 1;
		}
	}

	imshow("Original image", image);
	imshow("result image", result);

	waitKey(0);
}
