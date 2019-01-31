#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int rhovalue=10,theta=100,threvalue=100;

void rhoCallback(int value,void* param);
void thetaCallback(int value,void* param);
void threCallback(int value,void* param);
void help();
void help2();
void dpCallback(int value,void* param);
void mindisCallback(int value,void* param);

Mat img = imread("2.jpg");
Mat img2 = imread("3.jpg");
vector<Vec2f> lines;
vector<Vec3f> circles;
int dpvalue=1;
int mindisvalue=10;


int main(){
	imshow("origin",img);
	cvtColor(img,img,COLOR_BGR2GRAY);
	cvtColor(img2,img2,COLOR_BGR2GRAY);
	namedWindow("HoughLines");
	moveWindow("HoughLines",400,0);
	createTrackbar("rho value","HoughLines",&rhovalue,500,rhoCallback);
	createTrackbar("theta value","HoughLines",&theta,314,thetaCallback);
	createTrackbar("threshold value","HoughLines",&threvalue,200,threCallback);
	setTrackbarMin("rho value","HoughLines",1);
	setTrackbarMin("theta value","HoughLines",1);
	setTrackbarMin("threshold value","HoughLines",1);
	help();
	namedWindow("HoughCircles");
	moveWindow("HoughCircles",100,100);
	createTrackbar("dp value","HoughCircles",&dpvalue,300,dpCallback);
	createTrackbar("min distance value","HoughCircles",&mindisvalue,200,mindisCallback);
	setTrackbarMin("dp value","HoughCircles",1);
	setTrackbarMin("min distance value","HoughCircles",10);
	help2();
	waitKey(0);
	return 0;
}

void help(){
	Mat canny;
	Canny(img,canny,50,150);
	HoughLines(canny,lines,rhovalue,theta/100.0,threvalue);
	for(int i=0;i<lines.size();i++){
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a*rho, y0 = b*rho;
		pt1.x = cvRound(x0 + 1000*(-b));
		pt1.y = cvRound(y0 + 1000*(a));
		pt2.x = cvRound(x0 - 1000*(-b));
		pt2.y = cvRound(y0 - 1000*(a));
		line(canny, pt1, pt2, Scalar(255,0,0,255), 2, CV_AA);
	}
	imshow("HoughLines",canny);
}

void rhoCallback(int value,void* param){help();}
void thetaCallback(int value,void* param){help();}
void threCallback(int value,void* param){help();}
void help2(){
	Mat clone = img2.clone();
	HoughCircles(img2,circles,HOUGH_GRADIENT,dpvalue/1000.0,mindisvalue);
	for(int i=0;i<circles.size();i++)
		circle(clone,Point(cvRound(circles[0][0]),cvRound(circles[0][1])),cvRound(circles[0][2]),Scalar(255,0,0,255),2);
	imshow("HoughCircles",clone);
}

void dpCallback(int value,void* param){help2();}
void mindisCallback(int value,void* param){help2();}
