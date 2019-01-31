#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc,char** argv){
	Mat m(4,4,CV_16U);
	randu(m,1,20);	
	MatConstIterator_<int> mit = m.begin<int>();
	cout<<"m:";
	for(;mit!=m.end<int>();mit++)
		cout<<*mit<<" ";
	cout<<endl;

	return 0;
}
