#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img = imread("1.jpg"),topHatimg,blackHatimg;
int thvalue=1,bhvalue=1;

void thCallback(int,void*);
void bhCallback(int,void*);

int main(){
	if(img.empty()){
		cerr<<"1.jpg can't load"<<endl;
		return -1;
	}	
	imshow("origin",img);
	namedWindow("TopHat");
	namedWindow("BlackHat");
	createTrackbar("tophat","TopHat",&thvalue,100,thCallback);
	createTrackbar("blackhat","BlackHat",&bhvalue,100,bhCallback);
	thCallback(thvalue,nullptr);
	bhCallback(bhvalue,nullptr);
	waitKey(0);
	return 0;
}

void thCallback(int value,void* param){
	morphologyEx(img,topHatimg,MORPH_TOPHAT,Mat(),Point(-1,-1),value);
	imshow("TopHat",topHatimg);	
}

void bhCallback(int value,void* param){
	morphologyEx(img,blackHatimg,MORPH_BLACKHAT,Mat(),Point(-1,-1),value);
	imshow("BlackHat",blackHatimg);	
}
