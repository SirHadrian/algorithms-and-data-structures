#include "lib.h"

void print_array(int array[], uint length) {
  fprintf(stdout, "| ");
  for (uint i = 0; i < length; ++i) {
    fprintf(stdout, "%d | ", array[i]);
  }
}

int floorff(float number) { return (uint)number; }

void swap(int *a, int *b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

void die(const char *error) {
  fprintf(stderr, "%s\n", error);
  exit(EXIT_FAILURE);
}
