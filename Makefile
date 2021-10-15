EXECUTABLES= main$(EXECEXT)

all : $(EXECUTABLES)

mergeSort.o : mergeSort.c mergeSort.h
	gcc -c mergeSort.c

quickSort.o : quickSort.c mergeSort.h
	gcc -c quickSort.c

main.o : main.c mergeSort.h quickSort.h
	gcc -c main.c

main$(EXECEXT) : main.o mergeSort.o quickSort.o
	gcc -o main$(EXECEXT) main.o mergeSort.o quickSort.o

clean :
	-rm *.o
	-rm $(EXECUTABLES)