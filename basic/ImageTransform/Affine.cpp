#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img = imread("2.jpg");
Mat affinimg;

int main(){
	imshow("origin",img);
	warpAffine(img,affinimg,getRotationMatrix2D(Point2f(img.rows/2,img.cols/2),30,1),img.size());
	imshow("rotate 30degree",affinimg);
	Point2f srcpoints[]={
		Point2f(0,0),
		Point2f(0,img.rows-1),
		Point2f(img.cols-1,0)
	};
	Point2f dstpoints[]={
		Point2f(100,100),
		Point2f(0,img.rows-1),
		Point2f(img.cols-100,0)
	};
	warpAffine(img,affinimg,getAffineTransform(srcpoints,dstpoints),img.size());
	imshow("a simple affine transform",affinimg);
	waitKey(0);
	return 0;
}
