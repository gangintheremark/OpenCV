#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

/* 주파수 영역에서의 LPF 프로그램 */
void shuffleDFT(Mat &src)
{
    int cX = src.cols / 2;
    int cY = src.rows / 2;

    Mat q1(src, Rect(0, 0, cX, cY));
    Mat q2(src, Rect(cX, 0, cX, cY));
    Mat q3(src, Rect(0, cY, cX, cY));
    Mat q4(src, Rect(cX, cY, cX, cY));

    Mat tmp;
    q1.copyTo(tmp);
    q4.copyTo(q1);
    tmp.copyTo(q4);
    q2.copyTo(tmp);
    q3.copyTo(q2);
    tmp.copyTo(q3);
}
void displayDFT(Mat &src)
{
    Mat image_array[2] = {Mat::zeros(src.size(), CV_32F), Mat::zeros(src.size(), CV_32F)};

    split(src, image_array);
    Mat mag_image;

    magnitude(image_array[0], image_array[1], mag_image);

    mag_image += Scalar::all(1);
    log(mag_image, mag_image);

    normalize(mag_image, mag_image, 0, 1, NORM_MINMAX);
    imshow("DSF_image", mag_image);
}

// 원형 필터
Mat getFilter(Size size)
{
    Mat filter(size, CV_32FC2, Vec2f(0, 0));
    circle(filter, size / 2, 50, Vec2f(1, 1), -1);
    return filter;
}

void main()
{
    Mat image = imread("lenna.png", IMREAD_GRAYSCALE);
    Mat float_img, dft_img, inverted_img;

    image.convertTo(float_img, CV_32FC1, 1.0 / 255.0);
    dft(float_img, dft_img, 16, 0);
    shuffleDFT(dft_img);

    Mat lowpass = getFilter(dft_img.size());
    Mat result;
    // 원형 필터와 DFT 곱하기
    multiply(dft_img, lowpass, result);

    displayDFT(result);

    shuffleDFT(result);
    idft(result, inverted_img, DFT_SCALE | DFT_REAL_OUTPUT);
    imshow("Original", image);
    imshow("inverted_image", inverted_img);

    waitKey(0);
}