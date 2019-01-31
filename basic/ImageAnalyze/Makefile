all:canny HoughTransform distanceTransform split
canny:canny.cpp
	g++ canny.cpp -o canny `pkg-config --libs --cflags opencv` -std=c++11
HoughTransform:HoughTransform.cpp
	g++ HoughTransform.cpp -o HoughTransform `pkg-config --libs --cflags opencv` -std=c++11
distanceTransform:distanceTransform.cpp
	g++ distanceTransform.cpp -o distanceTransform `pkg-config --libs --cflags opencv` -std=c++11
split:split.cpp
	g++ split.cpp -o split `pkg-config --libs --cflags opencv` -std=c++11
.PHONY:clean
clean:
	-rm Makefile~ canny canny.cpp~ HoughTransform HoughTransform.cpp~ distanceTransform.cpp~ distanceTransform split split.cpp~
