#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

void main()
{
    Mat image = imread("flower.png", IMREAD_GRAYSCALE);
    Mat result = Mat(image.size(), CV_8U, Scalar(0));

    Point2f srcTri[3];
    srcTri[0] = Point2f(0.f, 0.f);
    srcTri[1] = Point2f(image.cols - 1.f, 0.f);
    srcTri[2] = Point2f(0.f, image.rows - 1.f);

    Point2f dstTri[3];
    dstTri[0] = Point2f(0.f, image.rows * 0.33f);
    dstTri[1] = Point2f(image.cols * 0.85f, image.rows * 0.25f);
    dstTri[2] = Point2f(image.cols * 0.15f, image.rows * 0.7f);

    Mat warp_mat = getAffineTransform(srcTri, dstTri);

    result = Mat::zeros(image.rows, image.cols, image.type());
    warpAffine(image, result, warp_mat, result.size());

    imshow("Original image", image);
    imshow("Result image", result);
    waitKey(0);
}
