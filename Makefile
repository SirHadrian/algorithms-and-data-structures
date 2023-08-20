COMPILER=g++
COMPILER_FLAGS=-Wall -Werror -Wpedantic -ggdb
TARGET=out

lib.o: lib.cpp
	${COMPILER} ${COMPILER_FLAGS} -c lib.cpp

clean:
	rm *.o ${TARGET}

run:
	./${TARGET}

linear_search: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} linear_search.cpp lib.o 
	
binary_search: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} binary_search.cpp lib.o

bubble_sort: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} bubble_sort.cpp lib.o

linked_list_queue: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} linked_list_queue.cpp lib.o

linked_list_stack: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} linked_list_stack.cpp lib.o 

quicksort: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} quicksort.cpp lib.o 

binary_search_recursive: lib.o
	${COMPILER} ${COMPILER_FLAGS} -o ${TARGET} binary_search_recursive.cpp lib.o 
