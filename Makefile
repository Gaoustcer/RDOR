builddir = ./build 
main:main.cpp arrobject.cpp arrobject.h
	g++ main.cpp arrobject.cpp filesize.cpp -o main
encoder:encoder.cpp arrobject.cpp arrobject.h
	g++ encoder.cpp arrobject.cpp filesize.cpp -o encoder
decoder:decoder.cpp arrobject.cpp arrobject.h readdecode.h readdecode.cpp
	g++ decoder.cpp arrobject.cpp filesize.cpp readdecode.cpp -o decoder
