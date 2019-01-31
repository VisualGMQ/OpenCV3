#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
	cout<<"logPolar()用于将对书坐标变为极坐标。。。（虽然不知道有什么用）"<<endl;
	Mat img = imread("2.jpg");
	Mat transimg;
	logPolar(img,transimg,Point2f(img.cols/2,img.rows/2),1,INTER_LINEAR|WARP_FILL_OUTLIERS);
	imshow("logPolar",transimg);
	waitKey(0);
	return 0;
}
