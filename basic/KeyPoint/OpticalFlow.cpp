#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
	VideoCapture vc("2.mov");
	if(!vc.isOpened()){
		cerr<<"can't open 2.mov"<<endl;
		return -1;
	}
	Mat img,previmg,gray;
	vc>>img;
	namedWindow("video");
	vector<Point2f> points,nextpoints;
	vector<uchar> featurefound;
	cvtColor(img,gray,COLOR_BGR2GRAY);
	while(!img.empty()){
		previmg = img.clone();
		vc>>img;	
		goodFeaturesToTrack(gray,points,0,0.1,5);
		cornerSubPix(gray,points,Size(5,5),Size(-1,-1),TermCriteria(TermCriteria::MAX_ITER|TermCriteria::EPS,20,0.03));
		calcOpticalFlowPyrLK(previmg,img,points,nextpoints,featurefound,noArray());
		points = nextpoints;
		for(int i=0;i<points.size();i++)
			if(featurefound[i]!=0)
				circle(img,Point2f((points[i].x+nextpoints[i].x)/2,(points[i].y+nextpoints[i].y)/2),5,Scalar(0,255,0,255));
		imshow("video",img);
		waitKey(10);
	}

	return 0;
}
