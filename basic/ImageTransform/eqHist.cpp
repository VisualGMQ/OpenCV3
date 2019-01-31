#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
	Mat img1 = imread("1.jpg",CV_8UC1),img2 = imread("2.jpg",CV_8UC1);
	Mat transimg;
	imshow("origin img1",img1);
	imshow("origin img2",img2);
	equalizeHist(img1,transimg);
	imshow("img1",transimg);
	equalizeHist(img2,transimg);
	imshow("img2",transimg);
	waitKey(0);
	return 0;
}
