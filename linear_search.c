#include "lib.h"

int linear_search(int array[], uint length, int item) {
  // Iterate over all the input
  for (uint i = 0; i < length; ++i) {
    // Check every element for the item
    if (array[i] == item)
      return i;
  }
  return -1;
}

int main(void) {

  int items[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  uint length = sizeof(items) / sizeof(items[0]);

  print_array(items, length);

  int index = linear_search(items, length, 5);
  fprintf(stdout, "\nIndex: %d\n", index);

  return EXIT_SUCCESS;
}
