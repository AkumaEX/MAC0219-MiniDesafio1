main: main.o
	gcc -o main -Wall -ansi -pedantic -O0 main.o
clean:
	rm -rf *.o
run: main
	./main