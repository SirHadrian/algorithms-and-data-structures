CC=gcc
CPP=g++
CFLAGS=-Wall -Wextra -Wconversion -Wuninitialized -Wpedantic -Werror
LDLIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET=a.out

default: 

clean:
	rm *.o ${TARGET}

linked_list_queue: 
	${CPP} ${CFLAGS} -o ${TARGET} linked_list_queue.cpp && ./a.out

linked_list_stack: 
	${CPP} ${CFLAGS} -o ${TARGET} linked_list_stack.cpp && ./a.out

quicksort: 
	${CPP} ${CFLAGS} -o ${TARGET} quicksort.cpp && ./a.out

linear_search: timer.o
	${CC} ${CFLAGS} ${LDLIBS} -o ${TARGET} linear_search.c timer.o && ./a.out

binary_search: timer.o
	${CC} ${CFLAGS} ${LDLIBS} -o ${TARGET} binary_search.c timer.o && ./a.out

bubble_sort: timer.o
	${CC} ${CFLAGS} ${LDLIBS} -o ${TARGET} bubble_sort.c timer.o && ./a.out

selection_sort: timer.o
	${CC} ${CFLAGS} ${LDLIBS} -o ${TARGET} selection_sort.c timer.o && ./a.out

timer.o: timer.c
	${CC} ${CFLAGS} -c timer.c
