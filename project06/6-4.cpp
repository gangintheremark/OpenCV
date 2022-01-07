#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

void main()
{
    Mat image = imread("flower.png", IMREAD_GRAYSCALE);
    Mat result = Mat(image.size(), CV_8U, Scalar(0));

    resize(image, result, Size(), 2.0, 2.0);

    imshow("Original image", image);
    imshow("Result image", result);
    waitKey(0);
}
