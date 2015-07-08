all: shell

shell:
	g++ -std=c++11 -o shell.x shell.cpp

clean:
	rm -f *.x
