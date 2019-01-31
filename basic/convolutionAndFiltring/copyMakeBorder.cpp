#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc,char** argv){
	Mat img = imread("1.png"),borderimg;
	namedWindow("origin");
	moveWindow("origib",0,0);
	imshow("origin",img);
	copyMakeBorder(img,borderimg,50,50,50,50,BORDER_CONSTANT,Scalar(0,200,0,255));
	namedWindow("BORDER_CONSTANT");
	moveWindow("BORDER_CONSTANT",500,0);
	imshow("BORDER_CONSTANT",borderimg);
	copyMakeBorder(img,borderimg,50,50,50,50,BORDER_WRAP);
	namedWindow("BORDER_WRAP");
	moveWindow("BORDER_WRAP",1000,0);
	imshow("BORDER_WRAP",borderimg);
	copyMakeBorder(img,borderimg,50,50,50,50,BORDER_REPLICATE);
	namedWindow("BORDER_REPLICATE");
	moveWindow("BORDER_REPLICATE",0,700);
	imshow("BORDER_REPLICATE",borderimg);
	copyMakeBorder(img,borderimg,50,50,50,50,BORDER_REFLECT);
	namedWindow("BORDER_REFLECT");
	moveWindow("BORDER_REFLECT",700,700);
	imshow("BORDER_REFLECT",borderimg);
	
	waitKey(0);
	return 0;
}
