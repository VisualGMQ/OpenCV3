#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img = imread("1.jpeg");
Mat output;
int typevalue=1;

int main(){
	cout<<"可以看出，直接对图像进行距离变换是没什么用的，一般会先阈值化，模糊或者归一化"<<endl;
	imshow("origin",img);
	cvtColor(img,img,COLOR_BGR2GRAY);
	Mat canny;
	Canny(img,canny,50,150);
	canny = 255-canny;
	namedWindow("Canny");
	moveWindow("Canny",400,0);
	imshow("Canny",canny);
	distanceTransform(canny,output,DIST_L2,5);
	namedWindow("distanceTransform");
	moveWindow("distanceTransform",800,0);
	imshow("distanceTransform",output);
	waitKey(0);
	return 0;
}
