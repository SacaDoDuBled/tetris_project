prog : main.o pieces.o general_function.o
	gcc -o prog main.o pieces.o general_function.o


main.o : main.c
	gcc -o main.o -c main.c

pieces.o : pieces.c
	gcc -o pieces.o -c pieces.c

general_function.o : general_function.c
	gcc -o general_function.o -c general_function.c