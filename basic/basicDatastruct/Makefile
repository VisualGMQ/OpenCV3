all:basicDatastructs.cpp Mat.cpp
	g++ basicDatastructs.cpp -o bD `pkg-config --libs --cflags opencv` -std=c++11
	g++ Mat.cpp -o Mat `pkg-config --libs --cflags opencv` -std=c++11
.PHONY:clean
clean:
	-rm bD basicDatastructs.cpp~ Makefile~ Mat.cpp~ Mat
