#include "lib.h"

void print_array(int array[], uint length) {
  std::cout << "| ";
  for (uint i = 0; i < length; ++i) {
    std::cout << array[i] << " | ";
  }
}

int floorff(float number) { return (uint)number; }

void swap(int *a, int *b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

void die(const char *error) {
  std::cerr << error << std::endl;
  exit(EXIT_FAILURE);
}
