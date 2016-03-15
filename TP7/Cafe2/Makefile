test_automate: main.o automate.o
	gcc -o test_automate main.o automate.o

main.o: main.c automate.h
	gcc -c main.c

automate.o: automate.c automate.h
	gcc -c automate.c
