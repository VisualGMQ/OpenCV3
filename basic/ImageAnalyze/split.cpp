#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img = imread("1.jpeg");

int main(){
	Mat ffclone = img.clone();
	cout<<"简单的来说，满水填充等算法就是PS里面的魔棒。魔棒点击的那个点就是参数seed。"<<endl;
	cout<<"满水填充函数通道数必须是1/3"<<endl;
	floodFill(ffclone,Point(0),Scalar(0,255,0,255));
	imshow("floodFill",ffclone);
	Mat wsclone = img.clone();
	wsclone.convertTo(wsclone,CV_8UC3);
	Mat mask = imread("mask.png");
	mask.convertTo(mask,CV_32SC1);
	watershed(wsclone,mask);
	imshow("watershed",wsclone);
	waitKey(0);

	return 0;
}
