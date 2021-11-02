#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;
using namespace std;

void main() {
	Mat image = imread("flower.png", IMREAD_GRAYSCALE);
	Mat result = image.clone();
    
	threshold(image, result, 128, 255, THRESH_BINARY);
	
	imshow("Original image", image);
	imshow("Binary image", result);

	waitKey(0);
}
