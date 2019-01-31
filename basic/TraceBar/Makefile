all:main.cpp
	g++ main.cpp -o exe `pkg-config --libs --cflags opencv` -std=c++11
.PHONY:clean
clean:
	-rm Makefile~ main.cpp~ exe
