#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

ostream& operator<<(ostream& os,Mat& m){
	cout<<endl;
	for(int i=0;i<m.rows;i++){
		for(int j=0;j<m.cols;j++)
			switch(m.type()){
				case CV_32S:
					cout<<m.at<int>(i,j)<<" ";
					break;
				case CV_8U:
					cout<<m.at<uchar>(i,j)<<" ";
					break;
				case CV_8S:
					cout<<m.at<schar>(i,j)<<" ";
					break;
				case CV_16U:
					cout<<m.at<ushort>(i,j)<<" ";
					break;
				case CV_16S:
					cout<<m.at<short>(i,j)<<" ";
					break;
				case CV_32F:
					cout<<m.at<float>(i,j)<<" ";
					break;
				case CV_64F:
					cout<<m.at<double>(i,j)<<" ";
					break;
						
			}
		cout<<endl;
	}
	return os;
}

int main(int argc,char** argv){
	cout<<"--------some factory function--------"<<endl;
	Mat meye = Mat::eye(3,3,CV_32S);
	Mat mones = Mat::ones(3,3,CV_32S);
	Mat mzeros = Mat::zeros(3,3,CV_32S);
	Mat r(1,3,CV_32S);
	r.at<int>(0,0)=1;r.at<int>(0,1)=2;r.at<int>(0,2)=3;
	Mat mdiag = Mat::diag(r); 
	cout<<"eye mat:"<<meye<<endl
		<<"ones mat:"<<mones<<endl
		<<"zeros mat:"<<mzeros<<endl
		<<"diag mat:"<<mdiag<<endl;
	cout<<"--------some operators-------"<<endl;
	cout<<"the channels of meye:"<<meye.channels()<<endl
		<<"use .clone() to clone a mat"<<endl;
	Mat convertmat;
	meye.convertTo(convertmat,CV_32F,3,0.5);
	cout<<"use .convertTo() to convert the mat(every element will multiply alpha,and add beta):"<<convertmat<<endl;
	Mat vec1(1,3,CV_16S),vec2(1,3,CV_16S);
	vec1.at<int>(0,0)=1;vec1.at<int>(0,1)=2;vec1.at<int>(0,2)=3;
	vec2.at<int>(0,0)=2;vec2.at<int>(0,1)=4;vec2.at<int>(0,2)=6;
	cout<<"use .copyTo() to copy the mat to another"<<endl
		<<"you can also use .create() to create a new mat"<<endl
		<<".cross() allow you to calculate two 3-elements vectors"<<endl
		<<"vec1:"<<vec1<<endl<<"vec2:"<<vec2<<endl
		<<"vec1.cross(vec2):"<<vec1.cross(vec2)<<endl
		<<"use .dot() to calculate dot of mat:"<<endl
		<<"vec1.dot(vec2):"<<vec1.dot(vec2)<<endl;
	cout<<".depth() to return depth:"<<convertmat.depth()<<endl
		<<".diag() to return the diag:"<<meye.diag()<<endl
		<<"meye.elemSize():"<<meye.elemSize()<<endl
		<<".empty():"<<meye.empty()<<endl
		<<".t():"<<meye.t()<<endl
		<<".forEach() to operate each elements:";
		meye.forEach<int>([](int& i,const int* position){i=i*2;});
		cout<<meye<<endl;
	meye.reserve(3);
	cout<<"reserve meye:"<<meye<<endl;
	cout<<".isContinues():"<<meye.isContinuous()<<endl;
	cout<<"is meye a sub matrix of another:"<<meye.isSubmatrix()<<endl;
	meye.resize(7);
	cout<<".resize() change the columns of meye:"<<meye<<endl;
	cout<<".reshape() change the column and row of meye:"<<meye.reshape(0,5)<<endl;
	cout<<"-----------there are many non member function operate on Mat-----------"<<endl
		<<"the detail please see book"<<endl;
	return 0;
}

