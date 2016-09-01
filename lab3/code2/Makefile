inc =  -lm 

all: func.o main.o
	gcc -w -o my_exe func.o main.o -Wno-deprecated -I ${inc} 

main.o: main.c
	gcc -c main.c -Wno-deprecated -I ${inc}

myfn.o: header.h func.c
	gcc -c func.c -Wno-deprecated -I ${inc}
clean:
	rm -f *.o
