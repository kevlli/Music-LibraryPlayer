all: main.o library.o song.o 
	gcc -o main main.o library.o song.o
main.o: main.c library.h song.h
	gcc -c main.c
library.o: library.c library.h song.h
	gcc -c library.c
song.o: song.c song.h
	gcc -c song.c
run:
	./main
clean:
	rm *.o
	rm main
