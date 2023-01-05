builddir = ./build 
main:main.cpp arrobject.cpp arrobject.h
	g++ main.cpp arrobject.cpp filesize.cpp -o main