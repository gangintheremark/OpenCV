#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

void main()
{
    Mat image = imread("flower.png", IMREAD_GRAYSCALE);
    Mat result = Mat(image.size(), CV_8U, Scalar(0));

    int tx = 100;
    int ty = 20;

    Mat t = (Mat_<double>(2, 3) << 1, 0, tx, 0, 1, ty);

    warpAffine(image, result, t, image.size());

    imshow("Original image", image);
    imshow("Result image", result);
    waitKey(0);
}