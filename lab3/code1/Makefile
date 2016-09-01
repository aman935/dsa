inc =  -lm 

all: myFunc.o main.o
	gcc -w -o my_exe myFunc.o main.o -Wno-deprecated -I ${inc} 

main.o: main.c
	gcc -c main.c -Wno-deprecated -I ${inc}

myfn.o: myLib.h myFunc.c
	gcc -c myFunc.c -Wno-deprecated -I ${inc}
clean:
	rm -f *.o
