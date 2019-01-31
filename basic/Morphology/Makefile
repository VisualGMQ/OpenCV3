all:erodeAnddilate openAndclose gradient topHatAndblackHat getKernels
erodeAnddilate:erodeAnddilate.cpp
	g++ erodeAnddilate.cpp -o erodeAnddilate `pkg-config --libs --cflags opencv` -std=c++11
openAndclose:openAndclose.cpp
	g++ openAndclose.cpp -o openAndclose `pkg-config --libs --cflags opencv` -std=c++11
gradient:gradient.cpp
	g++ gradient.cpp -o gradient `pkg-config --libs --cflags opencv` -std=c++11

topHatAndblackHat:topHatAndblackHat.cpp
	g++ topHatAndblackHat.cpp -o topHatAndblackHat `pkg-config --libs --cflags opencv` -std=c++11 
getKernels:getKernels.cpp
	g++ getKernels.cpp -o getKernels `pkg-config --libs --cflags opencv` -std=c++11
.PHONY:clean
clean:
	-rm erodeAnddilate erodeAnddilate.cpp~ openAndclose openAndclose.cpp~ Makefile~ topHatAndblackHat getKernels getKernels.cpp~
