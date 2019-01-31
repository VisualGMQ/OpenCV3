#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
	Mat img1 = imread("1.jpg"),img2 = imread("2.jpg");
	Mat transimg;
	fastNlMeansDenoisingColored(img1,transimg);
	imshow("img1",transimg);
	fastNlMeansDenoisingColored(img2,transimg);
	imshow("img2",transimg);
	waitKey(0);
	
	return 0;
}
