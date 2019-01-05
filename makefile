all:
	clang++ src/* -o bin/main -O3 -std=c++1y
run: all
	bin/main
