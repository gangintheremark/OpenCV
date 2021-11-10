#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

/* 2D DFT를 이용한 2차원 주파수 변환 및 역변환 */
void displayDFT(Mat &src)
{
    Mat image_array[2] = {Mat::zeros(src.size(), CV_32F), Mat::zeros(src.size(), CV_32F)};

    // DFT 결과 영상을 2개 영상으로 분리
    split(src, image_array);
    Mat mag_image;

    // 푸리에 변환 계수들의 절대값 계산
    magnitude(image_array[0], image_array[1], mag_image);

    // 푸리에 변환 계수들이 상당히 커 로그 스케일로 변환
    // 0 값이 나오지 않도록 1 더함
    mag_image += Scalar::all(1);
    log(mag_image, mag_image);

    // 정규화
    normalize(mag_image, mag_image, 0, 1, NORM_MINMAX);
    imshow("DFT image", mag_image);
}
void main()
{
    Mat image = imread("flower.png", IMREAD_GRAYSCALE);
    Mat img_float, dft_img, inversedft, inversedft_img;

    image.convertTo(img_float, CV_32F);

    dft(img_float, dft_img, 16, 0);

    idft(dft_img, inversedft, DFT_SCALE | DFT_REAL_OUTPUT);
    inversedft.convertTo(inversedft_img, CV_8U);

    imshow("Original", image);
    displayDFT(dft_img);
    imshow("역변환 image", inversedft_img);

    waitKey(0);
}