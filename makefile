all: main.o library.o song.o client
	gcc -o main main.o library.o song.o pipe_networking.o
main.o: main.c library.h song.h pipe_networking.h
	gcc -c main.c
library.o: library.c library.h song.h
	gcc -c library.c
song.o: song.c song.h
	gcc -c song.c
client: basic_client.o pipe_networking.o
	gcc -o client basic_client.o pipe_networking.o
basic_client.o: basic_client.c pipe_networking.h
	gcc -c basic_client.c
pipe_networking.o: pipe_networking.c pipe_networking.h
	gcc -c pipe_networking.c

	
run:
	./main
clean:
	rm *.o
	rm main
	rm client
	rm library.bin
	rm mario

