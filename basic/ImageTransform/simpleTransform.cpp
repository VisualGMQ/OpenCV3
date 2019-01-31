#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;

Mat img = imread("1.jpg");
Mat resizeimg;
vector<Mat> pymat;
int pyrvalue=0;

void pyrCallback(int,void*);

int main(){
	if(img.empty()){
		cerr<<"1.jpg can't load"<<endl;
		return -1;
	}
	cout<<"这里给出缩放，扭曲和旋转三种变换"<<endl
		<<"缩放的话你可以使用resize函数，或者使用图像金字塔(pyrDown,pyrUp,buildPyramid)"<<endl
		<<"resize可以是Mat的成员函数，这样你只能给出新大小，如果是全局函数resize允许你直接给出一个新大小，或者给出x或y的拉伸长度"<<endl;
	cout<<"图像金字塔的API解释是\"滤波并缩放\"，也就是说会先滤波"<<endl;
	resize(img,resizeimg,Size(),0.5,0.5);
	namedWindow("resize");
	moveWindow("resize",400,0);
	imshow("resize",resizeimg);
	imshow("origin",img);
	pyrDown(img,resizeimg);
	namedWindow("pyrDown");
	moveWindow("pyrDown",800,0);
	imshow("pyrDown",resizeimg);
	pyrUp(img,resizeimg);
	namedWindow("pyrUp");
	moveWindow("pyrUp",0,800);
	imshow("pyrUp",resizeimg);
	buildPyramid(img,pymat,10);
	namedWindow("buildPyramid");
	moveWindow("buildPyramid",400,400);
	createTrackbar("buildpyramid","buildPyramid",&pyrvalue,9,pyrCallback);
	pyrCallback(pyrvalue,nullptr);
	waitKey(0);
	return 0;
}

void pyrCallback(int value,void* param){
	imshow("buildPyramid",pymat[value]);
}
