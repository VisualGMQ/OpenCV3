all:simpleTransform Affine Perspective PolarAndMap denoising eqHist
simpleTransform:simpleTransform.cpp
	g++ simpleTransform.cpp -o simpleTransform `pkg-config --libs --cflags opencv` -std=c++11
Affine:Affine.cpp
	g++ Affine.cpp -o Affine `pkg-config --libs --cflags opencv` -std=c++11
Perspective:Perspective.cpp
	g++ Perspective.cpp -o Perspective `pkg-config --libs --cflags opencv` -std=c++11
PolarAndMap:PolarAndMap.cpp
	g++ PolarAndMap.cpp -o PolarAndMap `pkg-config --libs --cflags opencv` -std=c++11
denoising:denoising.cpp
	g++ denoising.cpp -o denoising `pkg-config --libs --cflags opencv` -std=c++11
eqHist:eqHist.cpp
	g++ eqHist.cpp -o eqHist `pkg-config --libs --cflags opencv` -std=c++11
.PHONY:clean
clean:
	-rm simpleTransform.cpp~ simpleTransform Makefile~ Affine Affine.cpp~ Perspective Perspective.cpp~ PolarAndMap PolarAndMap.cpp~ eqHist eqHist.cpp~ denoising.cpp~ denoising
