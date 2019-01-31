#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
	cout<<"这里我们通过getDerivKernels和getGaussianKernel函数来获得一些Sobel(Scharr)和Gaussian的核"<<endl;
	Mat sobelx,sobely,gaussian;
	getDerivKernels(sobelx,sobely,0,1,3);
	cout<<"dx=0,dy=1,3*3 sobel kernel:"<<endl
		<<"sobelx:"<<endl<<sobelx<<endl
		<<"sobely:"<<endl<<sobely<<endl;
	getDerivKernels(sobelx,sobely,1,0,3);
	cout<<"dx=1,dy=0,3*3 sobel kernel:"<<endl
		<<"sobelx:"<<endl<<sobelx<<endl
		<<"sobely:"<<endl<<sobely<<endl;
	getDerivKernels(sobelx,sobely,1,1,5);
	cout<<"dx=1,dy=1,5*5 sobel kernel:"<<endl
		<<"sobelx:"<<endl<<sobelx<<endl
		<<"sobely:"<<endl<<sobely<<endl;
	getDerivKernels(sobelx,sobely,0,2,3);
	cout<<"dx=0,dy=2,5*5 sobel kernel:"<<endl
		<<"sobelx:"<<endl<<sobelx<<endl
		<<"sobely:"<<endl<<sobely<<endl;
	getDerivKernels(sobelx,sobely,2,2,7);
	cout<<"dx=2,dy=2,7*7 sobel kernel:"<<endl
		<<"sobelx:"<<endl<<sobelx<<endl
		<<"sobely:"<<endl<<sobely<<endl;
	cout<<"-----------------------------------"<<endl;
	gaussian = getGaussianKernel(3,0);
	cout<<"3*3,sigma=0 gaussian kernel:"<<endl
		<<gaussian<<endl;
	gaussian = getGaussianKernel(7,0);
	cout<<"7*7,sigma=0 gaussian kernel:"<<endl
		<<gaussian<<endl;
	gaussian = getGaussianKernel(7,5);
	cout<<"7*7,sigma=5 gaussian kernel:"<<endl
		<<gaussian<<endl;
	return 0;
}
