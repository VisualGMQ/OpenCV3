#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img = imread("1.jpg");
Mat openimg,closeimg;
int openvalue=1,closevalue=1;

void openCallback(int,void*);
void closeCallback(int,void*);

int main(){
	if(img.empty()){
		cerr<<"can't open 1.jpg"<<endl;
		return -1;
	}
	cout<<"开操作就是先腐蚀后膨胀，闭操作就是先膨胀后腐蚀。"<<endl
		<<"这里虽然可以通过erode和dilate来完成开闭操作，但是我还是选择使用morphologyEx函数来实现"<<endl;
	namedWindow("Open operator");
	namedWindow("Close operator");
	createTrackbar("open trackbar","Open operator",&openvalue,20,openCallback);
	createTrackbar("close trackbar","Close operator",&closevalue,20,closeCallback);
	openCallback(openvalue,nullptr);
	closeCallback(closevalue,nullptr);
	namedWindow("origin");
	imshow("origin",img);
	moveWindow("origin",0,0);
	moveWindow("Open operator",200,0);
	moveWindow("Close operator",400,0);
	waitKey(0);
	return 0;
}

void openCallback(int value,void* param){
	morphologyEx(img,openimg,MORPH_OPEN,Mat(),Point(-1,-1),value);
	imshow("Open operator",openimg);
}
void closeCallback(int value,void* param){
	morphologyEx(img,closeimg,MORPH_CLOSE,Mat(),Point(-1,-1),value);
	imshow("Close operator",closeimg);
}
