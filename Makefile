all: main.cpp
	g++ main.cpp -lncurses -o tuigol.out

clean:
	rm ./*.out
