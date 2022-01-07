#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

void main()
{
    Mat image = imread("flower.png", IMREAD_GRAYSCALE);
    Mat result;

    Point center = Point(image.cols / 2, image.rows / 2);
    double angle = 45.0;
    double scale = 1.0;

    Mat rot = getRotationMatrix2D(center, angle, scale);

    warpAffine(image, result, rot, image.size());

    imshow("Original image", image);
    imshow("Result image", result);
    waitKey(0);
}
