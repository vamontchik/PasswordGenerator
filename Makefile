all:
	clang++ -std=c++20 -O3 gen.cpp -o gen.exe

clean:
	rm gen.exe