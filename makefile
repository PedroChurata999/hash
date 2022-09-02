all : myht
	echo "finished!"

clean :
	rm main.o libhash.o parser.o

purge :
	rm myht main.o libhash.o parser.o

#--

myht : main.o libhash.o parser.o
	gcc -o myht main.o libhash.o parser.o -lm

#--

main.o : main.c
	gcc -Wall -c main.c

libhash.o : libhash.c
	gcc -Wall -c libhash.c

parser.o : parser.c
	gcc -Wall -c parser.c