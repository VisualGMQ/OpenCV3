#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int valuex=1,valuey=0;
int sobelkernel=3;
Mat img = imread("1.png"),sobelimg,lapimg;

void sobelCallback(int value,void* param);
void sobelXCallback(int value,void* param);
void sobelYCallback(int value,void* param);

int main(){
	cout<<"Sobel算子用来计算导数（其实是近似拟合）和提取轮廓。其核大小必须是奇数且小于31。其导数的理论计算公式为:d^(xorder+yorder)f(x)/d^(xorder)xd^(yorder)y(x=0,1,2;y=0,1,2),当然最后计算的时候是使用卷积计算的。根据这个计算公式可以知道，一阶x偏导数xorder=1,yorder=0；一阶y偏导数yorder=1,xorder=0"<<endl;
	cout<<"当Soble的核为默认的3*3时，更推荐使用Scharr核去计算。"<<endl;
	cout<<"Laplacian函数理论上使用拉普拉斯函数去计算。当然这里也是使用核去卷积。"<<endl;
	namedWindow("origin");
	moveWindow("origin",0,0);
	imshow("origin",img);
	namedWindow("Sobel");
	moveWindow("Sobel",500,0);
	createTrackbar("tb_sobelx","Sobel",&valuex,2,sobelXCallback);
	createTrackbar("tb_sobely","Sobel",&valuey,2,sobelXCallback);
	createTrackbar("tb_sobel","Sobel",&sobelkernel,3,sobelCallback);
	sobelCallback(sobelkernel,nullptr);
	Laplacian(img,lapimg,CV_64F);
	namedWindow("laplacian");
	moveWindow("Laplacian",0,500);
	imshow("Laplacian",lapimg);
	waitKey(0);
	return 0;
}

void sobelCallback(int value,void* param){
	switch(sobelkernel){
		case 0:
			sobelkernel=-1;
			break;
		case 1:
			sobelkernel=1;
			break;
		case 2:
			sobelkernel=5;
			break;
		case 3:
			sobelkernel=7;
			break;
	}
	Sobel(img,sobelimg,CV_64F,valuex,valuey,sobelkernel);
	imshow("Sobel",sobelimg);
}
void sobelXCallback(int value,void* param){
	if((valuex|valuey)==0){
		setTrackbarPos("tb_sobelx","Sobel",1);
		valuex=1;
	}
	if((sobelkernel==0||sobelkernel==1) && valuex+valuey>1){
		valuex=1;
		valuey=0;
	}
	if(sobelkernel==2 && valuex+valuey>3){
		valuex=2;
		valuey=1;
	}	
	if(sobelkernel==3 && valuex+valuey>4){
		valuex=valuey=2;
	}
	Sobel(img,sobelimg,CV_64F,valuex,valuey,sobelkernel);
	imshow("Sobel",sobelimg);
}

void sobelYCallback(int value,void* param){
	if((valuex|valuey)==0){
		setTrackbarPos("tb_sobelx","Sobel",1);
		valuex=1;
	}	
	if((sobelkernel==0||sobelkernel==1) && valuex+valuey>1){
		valuex=1;
		valuey=0;
	}
	if(sobelkernel==2 && valuex+valuey>3){
		valuex=2;
		valuey=1;
	}	
	if(sobelkernel==3 && valuex+valuey>4){
		valuex=valuey=2;
	}
	Sobel(img,sobelimg,CV_64F,valuex,valuey,sobelkernel);
	imshow("Sobel",sobelimg);
}
