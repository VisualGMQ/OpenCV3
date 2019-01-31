#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img = imread("1.jpg");
Mat gradimg;
int gradvalue=0;

void gradCallback(int,void*);

int main(){
	if(img.empty()){
		cerr<<"can't load 1.jpg"<<endl;
		return -1;
	}
	cout<<"形态学梯度是膨胀减去腐蚀的操作"<<endl;
	namedWindow("Gradient");
	createTrackbar("gradient","Gradient",&gradvalue,80,gradCallback);
	gradCallback(gradvalue,nullptr);
	imshow("origin",img);
	moveWindow("Gradient",300,0);
	waitKey(0);
	return 0;
}

void gradCallback(int,void*){
	morphologyEx(img,gradimg,MORPH_GRADIENT,Mat(),Point(-1,-1),gradvalue);
	imshow("Gradient",gradimg);
}
