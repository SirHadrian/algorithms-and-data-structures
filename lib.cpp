#include "lib.h"

void lib::print_array(int array[], uint length) {
  std::cout << "| ";
  for (uint i = 0; i < length; ++i) {
    std::cout << array[i] << " | ";
  }
  std::cout << std::endl;
}

int lib::floorff(float number) { return (uint)number; }

void swap(int *a, int *b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

void lib::die(const char *error) {
  std::cerr << error << std::endl;
  exit(EXIT_FAILURE);
}
