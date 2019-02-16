all:cornerPoint OpticalFlow
cornerPoint:cornerPoint.cpp
	g++ cornerPoint.cpp -o cornerPoint `pkg-config --libs --cflags opencv` -std=c++11
OpticalFlow:OpticalFlow.cpp
	g++ OpticalFlow.cpp -o OpticalFlow `pkg-config --libs --cflags opencv` -std=c++11
.PHONY:clean
clean:
	-rm cornerPoint OpticalFlow
