#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

/* 셔플링 */
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
    imshow("result", mag_image);
}
void main()
{
    Mat image = imread("flower.png", IMREAD_GRAYSCALE);
    Mat float_img;
    Mat result;
    image.convertTo(float_img, CV_32FC1, 1.0 / 255.0);
    // 그레이스케일 영상을 실수 영상으로 변환
    dft(float_img, result, 16, 0);
    imshow("Original", image);
    shuffleDFT(result);
    displayDFT(result);

    waitKey(0);
}
