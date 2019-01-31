#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int value=1;
Mat canvas(300,700,CV_8U);
void callback(int value,void* param);

int main(int argc,char** args){
	namedWindow("window");
	createTrackbar("trackbar","window",&value,20,callback);
	setTrackbarMin("trackbar","window",1);
	callback(value,nullptr);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

void callback(int value,void* param){
	canvas = Mat::zeros(Size(canvas.cols,canvas.rows),CV_8U);
	putText(canvas,"the text was here",Point(0,150),FONT_HERSHEY_SIMPLEX,value,Scalar(255,0,0,255));	
	imshow("window",canvas);
}
