#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

Mat histogram, histogram2;  
Mat look_up;
Mat image, image2; 
Mat Equalization_histogram, Equalization_histogram2;	
Mat tmp, tmp2;

// 1단계. 히스토그램 생성
void CalcHistogram(Mat image, Mat& histogram, int bins, int range_max = 256) {

	histogram = Mat(bins, 1, CV_32F, Scalar(0));
	float gap = (float)range_max / bins;

	// 영상을 순회하면서 화소를 처리
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			auto workPixel = image.at<uchar>(i, j);
			int temp = (int)(workPixel / gap);
			histogram.at<float>(temp)++;
		}
	}
}

// 누적 히스토그램 정규화 
void Normalized_Cumulative_histogram(Mat histogram, Mat& histogramSum) {

	histogramSum = Mat(histogram.rows, 1, CV_32F, Scalar(0));
 
	float sum = 0;
	for (int i = 0; i < histogram.rows; i++) {
		sum += histogram.at<float>(i);
		histogramSum.at<float>(i) = sum;
	}

	// 정규화
	for (int i = 0; i < histogramSum.rows; i++)
		histogramSum.at<float>(i) = histogramSum.at<float>(i) / sum * 255.0;
}

// 2단계,3단계 : 입력 영상과 원하는 히스토그램의 평활화 
void HistogramEqualizing() {

	// 히스토그램 생성
	CalcHistogram(image, histogram, 256);
	CalcHistogram(image2, histogram2, 256);

	// 누적 빈도 수 계산 및 정규화
	Normalized_Cumulative_histogram(histogram, Equalization_histogram);
	Normalized_Cumulative_histogram(histogram2, Equalization_histogram2);

	// 정규화된 누적 빈도 수를 기반으로 기존의 화소를 변환
	// 화소값 제어
	tmp = Mat(image.size(), image.type());

	for (int i = 0; i < image.rows; i++)
		for (int j = 0; j < image.cols; j++)
			tmp.at <uchar>(i, j) = (uchar)Equalization_histogram.at<float>(image.at<uchar>(i, j));

	tmp2 = Mat(image2.size(), image2.type());

	for (int i = 0; i < image2.rows; i++)
		for (int j = 0; j < image2.cols; j++)
			tmp2.at <uchar>(i, j) = (uchar)Equalization_histogram2.at<float>(image2.at<uchar>(i, j));

}

// 4단계. 역평활화
void Specification()
{
	// 히스토그램 생성
	CalcHistogram(tmp2, look_up, 256);

	int image_1 = 254;
	int image_2 = 255;

	while (image_1 >= 0) {	
		for (int i = Equalization_histogram2.at<float>(image_1); i <= Equalization_histogram2.at<float>(image_2); i++)
			look_up.at<float>(i) = image_2;

		image_2 = image_1--;
	}

	// 룩업-테이블 매핑 작업

	// 정규화된 누적 빈도 수를 기반으로 기존의 화소를 변환
	// 화소값 제어
	Mat result = Mat(tmp.size(), tmp.type());

	for (int i = 0; i < tmp.rows; i++)
		for (int j = 0; j < tmp.cols; j++)
			result.at <uchar>(i, j) = (uchar)look_up.at <float>(tmp.at<uchar>(i, j));

	// 명세화 결과 출력
	imshow("Original", image);
	imshow("Result", result);

	waitKey();
}
int main()
{
	image = imread("flower.png", IMREAD_GRAYSCALE);
	CalcHistogram(image, histogram, 256);

	image2 = imread("want.png", IMREAD_GRAYSCALE);
	CalcHistogram(image2, histogram2, 256);

	HistogramEqualizing();	
	Specification();	
}
