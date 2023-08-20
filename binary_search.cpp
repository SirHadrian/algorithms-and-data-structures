#include "lib.h"
#include <cmath>

int binary_search(int array[], uint length, int item) {
  uint low = 0;
  uint high = length - 1;

  while (low <= high) {
    uint middle = std::floor((low + high) / 2.);

    if (array[middle] == item)
      return middle;
    else if (item < array[middle])
      high = middle;
    else
      low = middle + 1;
  }
  return -1;
}

int main(void) {

  int items[] = {0, 1, 2, 3, 4, 5};
  uint length = sizeof(items) / sizeof(items[0]);

  lib::print_array(items, length);
  int index = binary_search(items, length, 1);
  std::cout << "\nIndex: " << index << std::endl;

  return EXIT_SUCCESS;
}
