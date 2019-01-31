#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc,char** args){
	Point2i p1(10,20);
	cout<<"p1:("<<p1.x<<","<<p1.y<<")"<<endl;
	Point3i p2(10,20,30);
	cout<<"p2:("<<p2.x<<","<<p2.y<<","<<p2.z<<")"<<endl;
	Scalar_<int> s(1,2,3,4);
	cout<<"s:"<<s[0]<<","<<s[1]<<","<<s[2]<<","<<s[3]<<endl;
	Size2i size(100,200);
	cout<<"size:"<<size.width<<","<<size.height<<endl;
	Rect rect(Point(0,0),Size(100,20));
	cout<<"rect:("<<rect.x<<","<<rect.y<<")"<<",("<<rect.width<<","<<rect.height<<")"<<endl;
	cout<<"area of rect:"<<rect.area()<<endl;
	Matx33d m({1,2,3,4,5,6,7,8,9});
	double* values = m.val;
	cout<<"m:";
	for(int i=0;i<9;i++)
		cout<<values[i]<<" ";
	cout<<endl;
	Range range(10,21);
	cout<<"start of range:"<<range.start<<";end of range:"<<range.end<<endl;
	RNG rng;
	cout<<"random int:"<<int(rng)<<endl
		<<"random double:"<<double(rng)<<endl
		<<"a gaussian distribute:"<<rng.gaussian(10)<<endl;
	return 0;
}
