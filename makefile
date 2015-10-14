CC =  gcc
CFLAGS = -I.
DEPS = headers.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

headers: main.o dbfunctions.o
	gcc -o main main.o dbfunctions.o -I. 
