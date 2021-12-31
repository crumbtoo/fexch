install:
	clang++ -pthread -std=c++17 -o fexch main.cpp
	mv fexch /usr/local/bin

uninstall:
	rm /usr/local/bin/fexch
