#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img = imread("1.jpg"),erodeimg,dilateimg;
int erodevalue=1,dilatevalue=1;

void erodeCallback(int,void*);
void dilateCallback(int,void*);


int main(){
	cout<<"erode腐蚀函数其实是将核内的元素取最小值，而dilate膨胀则是取最大值。两个算子默认的核都是3*3的"<<endl;		
	if(img.empty()){
		cerr<<"can't open image"<<endl;
		return -1;
	}
	namedWindow("erode");
	namedWindow("dilate");
	createTrackbar("erodetb","erode",&erodevalue,80,erodeCallback);	
	createTrackbar("dilatetb","dilate",&dilatevalue,800,dilateCallback);	
	setTrackbarMin("erodetb","erode",1);
	setTrackbarMin("dilatetb","dilate",1);
	erodeCallback(erodevalue,nullptr);
	dilateCallback(dilatevalue,nullptr);
	waitKey(0);
	return 0;
}

void erodeCallback(int value,void* param){
	erode(img,erodeimg,Mat(),Point(-1,-1),value);
	imshow("erode",erodeimg);
}
void dilateCallback(int value,void* param){
	dilate(img,dilateimg,Mat(),Point(-1,-1),value);
	imshow("dilate",dilateimg);
}
