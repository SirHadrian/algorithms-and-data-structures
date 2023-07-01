lib.o: lib.c
	gcc -Wall -Werror -Wpedantic -c lib.c

clean:
	rm *.o alg

linear_search: lib.o
	gcc -Wall -Werror -Wpedantic -o alg linear_search.c lib.o && ./alg
	
binary_search: lib.o
	gcc -Wall -Werror -Wpedantic -o alg binary_search.c lib.o && ./alg

bubble_sort: lib.o
	gcc -Wall -Werror -Wpedantic -o alg bubble_sort.c lib.o && ./alg

linked_list_queue: lib.o
	gcc -Wall -Werror -Wpedantic -o alg linked_list_queue.c lib.o && ./alg

linked_list_stack: lib.o
	gcc -Wall -Werror -Wpedantic -o alg linked_list_stack.c lib.o && ./alg
