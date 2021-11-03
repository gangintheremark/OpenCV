#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

// 유사연산자 기법
void main() {
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result = Mat(image.size(), CV_8U, Scalar(0));

	int mask_size = 3;
	Point m(mask_size / 2, mask_size / 2);

	for (int i = m.y; i < image.rows - m.y; i++) {  // 입력 행렬 반복 
		for (int j = m.x; j < image.cols - m.x; j++) {
			float max = 0;
			for (int u = 0; u < mask_size; u++) {  // 마스크 원소 순회 
				for (int v = 0; v < mask_size; v++) { 
					int y = i + u - m.y;
					int x = j + v - m.x;

					float diff = abs(image.at<uchar>(i, j) - image.at<uchar>(y, x));
					if (diff > max)
						max = diff;
				}
			}
			result.at<uchar>(i, j) = max;
		}
	}
	imshow("Original image", image);
	imshow("Result image", result);

	waitKey(0);
}
