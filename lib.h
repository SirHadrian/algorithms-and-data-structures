#pragma once
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

typedef enum { False = 0, True = 1 } Bool;
typedef unsigned int uint;

void print_array(int array[], uint length);
int floorff(float number);
void swap(int *a, int *b);
void die(const char *error);
