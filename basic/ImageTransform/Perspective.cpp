#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img = imread("2.jpg");
Mat transimg;

int main(){
	Point2f srcpoints[]={
		Point2f(0,0),
		Point2f(0,img.rows-1),
		Point2f(img.cols-1,0),
		Point2f(img.cols-1,img.rows-1)
	};
	Point2f dstpoints[]={
		Point2f(100,50),
		Point2f(50,img.rows-1),
		Point2f(img.cols-1-100,20),
		Point2f(img.cols-1-50,img.rows-1-70)
	};
	warpPerspective(img,transimg,getPerspectiveTransform(srcpoints,dstpoints),img.size());
	imshow("Perspective transform",transimg);
	waitKey(0);
	return 0;
}
