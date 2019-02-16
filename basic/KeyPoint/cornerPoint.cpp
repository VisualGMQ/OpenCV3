#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
	VideoCapture vc("2.mov");
	if(!vc.isOpened()){
		cout<<"can't find 2.mov"<<endl;
		return -1;
	}
	Mat img,gray,clone;
	vector<Point2f> points;
	vc>>img;
	namedWindow("cornerPoint");
	namedWindow("sub cornerPoint");
	while(!img.empty()){
		cvtColor(img,gray,COLOR_BGR2GRAY);
		clone = img.clone();
		goodFeaturesToTrack(gray,points,0,0.1,5);
		for(Point2f i : points)
			circle(img,i,5,Scalar(0,255,0,255));
		imshow("cornerPoint",img);
		TermCriteria tc(TermCriteria::EPS,10,0.1);
		cornerSubPix(gray,points,Size(5,5),Size(-1,-1),tc);
		for(Point2f i : points)
			circle(clone,i,5,Scalar(255,0,0,255));
		imshow("sub cornerPoint",clone);
		vc>>img;
		waitKey(10);
	}
	return 0;
}
