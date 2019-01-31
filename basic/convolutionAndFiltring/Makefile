all:copyMakeBorder threshold blur derivative
copyMakeBorder:copyMakeBorder.cpp
	g++ copyMakeBorder.cpp -o copyMakeBorder `pkg-config --libs --cflags opencv`
threshold:threshold.cpp
	g++ threshold.cpp -o threshold `pkg-config --libs --cflags opencv` -std=c++11
blur:blur.cpp
	g++ blur.cpp -o blur `pkg-config --libs --cflags opencv` -std=c++11
derivative:derivative.cpp
	g++ derivative.cpp -o derivative `pkg-config --libs --cflags opencv` -std=c++11
.PHONY:clean
clean:
	-rm copyMakeBorder copyMakeBorder.cpp~ Makefile~ threshold threshold.cpp~ blur.cpp~ blur derivative derivative.cpp~
