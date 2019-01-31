#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int value1=0,value2=0,value3=0,value4=0,maxvalue=0;
Mat threimg;
Mat img = imread("1.png");

void tbCallback(int value,void* param);
void tb_maxvalueCallback(int value,void* param);
void ttCallback(int value,void* param);
void tzCallback(int value,void* param);
void atCallback(int value,void* param);


int main(){
	if(img.empty()){
		cerr<<"can't open 1.png"<<endl;
		return -1;
	}
	cout<<"阈值操作是根据不同的thresholdType来就行不同计算的："<<endl
		<<"THRESH_BINARY:     dst=(src>thresh)?MAXVALUE:0"<<endl
		<<"THRESH_BINARY_INV: dst=(src>thresh)?0:MAXVALUE"<<endl
		<<"THRESH_TRUNC:      dst=(src>thresh)?THRESH:src"<<endl
		<<"THRESH_TOZERO:     dst=(src>thresh)?src:0"<<endl
		<<"THRESH_TOZERO_INV: dst=(src>thresh)?0:src"<<endl
		<<"可以看到MAXVALUE只有在二值化才可以用到"<<endl
		<<"或者通过传入THRESH_OTSU来让函数自己决定最合适的阈值方法"<<endl;
	cout<<"还有一种自适应阈值，这个阈值函数中的thresh可以自己变化，你只需要给出MAXVALUE即可（在不需要MAXVALUE的时候可以不给出）。但是这个函数只处理单通道图像,并且src和dst不能一样"<<endl;
	namedWindow("origin");
	moveWindow("origin",0,0);
	imshow("origin",img);
	namedWindow("THRESH_BINARY");
	createTrackbar("tb_thresh","THRESH_BINARY",&value1,255,tbCallback);
	createTrackbar("tb_maxvaluethresh","THRESH_BINARY",&value1,255,tb_maxvalueCallback);
	moveWindow("THRESH_BINARY",300,0);
	namedWindow("THRESH_TRUNC");
	createTrackbar("tt_thresh","THRESH_TRUNC",&value2,255,ttCallback);
	moveWindow("THRESH_TRUNC",600,0);
	namedWindow("THRESH_TOZERO");
	moveWindow("THRESH_TOZERO",0,500);
	createTrackbar("tz_thresh","THRESH_TOZERO",&value3,255,tzCallback);
	namedWindow("adaptThreshold");
	moveWindow("adaptThreshold",500,500);
	Mat adthreimg,grayimg;
	grayimg = imread("1.png",CV_LOAD_IMAGE_GRAYSCALE);
	adaptiveThreshold(grayimg,adthreimg,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,9,1);
	imshow("adaptThreshold",adthreimg);
	waitKey(0);
	return 0;
}

void tbCallback(int value,void* param){
	threshold(img,threimg,value,maxvalue,THRESH_BINARY);
	imshow("THRESH_BINARY",threimg);
	
}

void tb_maxvalueCallback(int value,void* param){
	threshold(img,threimg,value1,value,THRESH_BINARY);
	imshow("THRESH_BINARY",threimg);
}

void ttCallback(int value,void* param){
	threshold(img,threimg,value,0,THRESH_TRUNC);
	imshow("THRESH_TRUNC",threimg);

}

void tzCallback(int value,void* param){
	threshold(img,threimg,value,0,THRESH_TOZERO);
	imshow("THRESH_TOZERO",threimg);
}
