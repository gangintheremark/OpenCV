#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

void main() {
	Mat image = imread("lenna.png", IMREAD_GRAYSCALE);
	Mat binary;

	threshold(image, binary, 0, 255, THRESH_BINARY | THRESH_OTSU); 

	imshow("Original image", image);
	imshow("Binary image", binary);
 
	waitKey(0);
}
