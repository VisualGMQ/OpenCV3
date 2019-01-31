#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int value1=1,value2=1,value3=1,value4=1,value5=1;
Mat img = imread("1.png");
Mat blurimg,boximg,gaussimg,medianimg,bilanimg;

void blurCallback(int value,void* param);
void bfCallback(int value,void* param);
void gaussCallback(int value,void* param);
void medianCallback(int value,void* param);
void bilanCallback(int value,void* param);


int main(){
	cout<<"滤波的本质都是使用核与图像进行卷积，如果有多通道的话会对每个通道分别计算。"<<endl;
	cout<<"blur为简单模糊，其锚点处的值为核范围内值的平均值。你可以指定内核的大小和锚点"<<endl;
	cout<<"boxFilter为方框滤波，其将核范围内的所有值全部变成相等的值。"<<endl;
	cout<<"GaussianBlur为高斯滤波，使用高斯内核进行滤波"<<endl
		<<"medianBlur为中值滤波，会将锚点处的值变成核内所有值的中间值。由于中值滤波的核一定是方的，所以只需要给出核的大小即可"<<endl;
	cout<<"高斯滤波和中值滤波的核必须是奇数，且中值滤波必须大于1"<<endl;
	cout<<"最后的双边滤波和高斯滤波差不多，但是不会滤波掉边缘，也就是说对线框式图像效果少。双边滤波的sigma参数要十分大才可以看出效果"<<endl;
	namedWindow("origin");
	moveWindow("origin",0,0);
	imshow("origin",img);
	Mat blurimg;
	namedWindow("blur");
	moveWindow("blur",500,0);
	createTrackbar("blurtrackbar","blur",&value1,50,blurCallback);
	setTrackbarMin("blurtrackbar","blur",1);
	blurCallback(value1,nullptr);
	Mat boximg;
	namedWindow("boxFilter");
	moveWindow("boxFilter",0,500);
	createTrackbar("bftrack","boxFilter",&value2,50,bfCallback);
	setTrackbarMin("bftrack","boxFilter",1);
	bfCallback(value2,nullptr);
	namedWindow("GaussianBlur");
	moveWindow("GaussianBlur",0,1000);
	createTrackbar("gausstrack","GaussianBlur",&value3,50,gaussCallback);
	setTrackbarMin("gausstrack","GaussianBlur",1);
	gaussCallback(value3,nullptr);
	namedWindow("medianBlur");
	moveWindow("medianBlur",1000,0);
	createTrackbar("mediantrack","medianBlur",&value4,50,medianCallback);
	setTrackbarMin("mediantrack","medianBlur",3);
	medianCallback(value4,nullptr);
	namedWindow("bilateralFilter");
	moveWindow("bilateralFilter",1000,500);
	createTrackbar("bilatetrack","bilateralFilter",&value4,10,bilanCallback);
	setTrackbarMin("bilatetrack","bilateralFilter",3);
	bilanCallback(value5,nullptr);

	waitKey(0);
	return 0;
}

void blurCallback(int value,void* param){
	blur(img,blurimg,Size(value,value));
	imshow("blur",blurimg);
}

void bfCallback(int value,void* param){
	boxFilter(img,boximg,CV_8U,Size(value,value));
	imshow("boxFilter",boximg);
}

void gaussCallback(int value,void* param){
	if(value%2==0)
		value++;
	GaussianBlur(img,gaussimg,Size(value,value),0);
	imshow("GaussianBlur",gaussimg);
}

void medianCallback(int value,void* param){
	if(value%2==0)
		value++;
	medianBlur(img,medianimg,value);
	imshow("medianBlur",medianimg);
}

void bilanCallback(int value,void* param){
	bilateralFilter(img,bilanimg,value,1000,100);
	imshow("bilateralFilter",bilanimg);
}
