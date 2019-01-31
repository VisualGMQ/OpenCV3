#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int hvalue=100,lvalue=0;
Mat img = imread("1.jpeg");
Mat outputimg;

void hvalueCallback(int value,void* param);
void lvalueCallback(int value,void* param);

void judge();


int main(){
	imshow("origin",img);
	cout<<"Canny的原理是：计算图像的梯度，如果梯度小于低阈值抛弃，高于高阈值就接受（保留），两者之间的话如果这个像素连接着一个高阈值像素就接受"<<endl;
	cout<<"建议的Canny算法的高低阈值比为2:1或者3:1"<<endl;
	namedWindow("canny");
	createTrackbar("high value","canny",&hvalue,255,hvalueCallback);
	setTrackbarMin("high value","canny",1);
	createTrackbar("low value","canny",&lvalue,254,lvalueCallback);
	moveWindow("canny",400,0);
	hvalueCallback(hvalue,nullptr);
	imshow("origin",img);
	waitKey(0);
	return 0;
}

void hvalueCallback(int value,void* param){
	judge();
}

void lvalueCallback(int value,void* param){
	judge();
}

void judge(){
	if(lvalue>hvalue){
		lvalue=hvalue-1;
		setTrackbarPos("high value","canny",hvalue);
		setTrackbarPos("low value","canny",lvalue);
	}
	Canny(img,outputimg,lvalue,hvalue);
	imshow("canny",outputimg);
}
