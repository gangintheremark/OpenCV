#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// 차 연산자 기법
void main() {
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result = Mat(image.size(), CV_8U, Scalar(0));

	int mask_size = 3;
	Point m(mask_size / 2, mask_size / 2); 
	int mask_length = mask_size * mask_size; 

	for (int i = m.y; i < image.rows - m.y; i++) { 
		for (int j = m.x; j < image.cols - m.x; j++) {
			
			vector<uchar> mask(mask_length, 0);

			for (int u = 0, k = 0; u < mask_size; u++) { 
				for (int v = 0; v < mask_size; v++) {
					int y = i + u - m.y;
					int x = j + v - m.x;
					mask[k] = image.at<uchar>(y, x);
			}       }
			float max = 0;
			for (int k = 0; k < mask_length / 2; k++) {
				int start = mask[k];
				int end = mask[mask_length - k - 1]; 
					
				float diff = abs(start - end);
				if (diff > max)
					max = diff;
			}
			result.at<uchar>(i, j) = max;
	}	}
	imshow("Original image", image);
	imshow("Result image", result);
	waitKey(0);
}