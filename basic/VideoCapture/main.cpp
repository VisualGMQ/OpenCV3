#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc,char** argv){
	VideoCapture vc("1.mov");
	if(!vc.isOpened()){
		cout<<"open 1.mov failed"<<endl;
		return -1;
	}
	cout<<"Current position of the video file in milliseconds:"<<vc.get(CAP_PROP_POS_MSEC)<<endl
		<<"0-based index of the frame to be decoded/captured next:"<<vc.get(CAP_PROP_POS_FRAMES)<<endl
		<<"Relative position of the video file: 0=start of the film, 1=end of the film"<<vc.get(CAP_PROP_POS_AVI_RATIO)<<endl
		<<"frame width:"<<vc.get(CAP_PROP_FRAME_WIDTH)<<";frame height:"<<vc.get(CAP_PROP_FRAME_HEIGHT)<<endl
		<<"FPS:"<<vc.get(CAP_PROP_FPS)<<endl
		<<"frame counts:"<<vc.get(CAP_PROP_FRAME_COUNT)<<endl;
	namedWindow("video");
	Mat img;
	vc>>img;
	VideoWriter vw("2.mov",vc.get(CAP_PROP_FOURCC),vc.get(CAP_PROP_FPS),Size(vc.get(CAP_PROP_FRAME_WIDTH),vc.get(CAP_PROP_FRAME_HEIGHT)));
	if(!vw.isOpened()){
		cout<<"can't write 2.mov"<<endl;
	}
	int count=2;
	while(!img.empty()){
		if(count==0){
			vw<<img;
			count=2;
		}
		imshow("video",img);
		vc>>img;
		waitKey(10);
		count--;
	}
	vc.release();
	vw.release();
	destroyAllWindows();
	return 0;
}
