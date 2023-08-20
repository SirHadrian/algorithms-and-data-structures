COMPILER=gcc
COMPILER_FLAGS=-Wall -Werror -Wpedantic -ggdb
TARGET=out

lib.o: lib.c
	${COMPILER} ${COMPILER_FLAGS} -c lib.c

clean:
	rm *.o ${TARGET}

run:
	./${TARGET}

linear_search: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} linear_search.c lib.o 
	
binary_search: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} binary_search.c lib.o

bubble_sort: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} bubble_sort.c lib.o

linked_list_queue: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} linked_list_queue.c lib.o

linked_list_stack: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} linked_list_stack.c lib.o 

quicksort: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} quicksort.c lib.o 

binary_search_recursive: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} binary_search_recursive.c lib.o 
