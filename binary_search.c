#include "lib.h"

int binary_search(int array[], uint length, int item) {
  uint low = 0;
  uint high = length - 1;

  while (low <= high) {
    uint middle = floorff((low + high) / 2.);
    int pivot = array[middle];

    if (pivot == item)
      return middle;
    else if (item < pivot)
      high = middle;
    else
      low = middle + 1;
  }
  return -1;
}

int main(void) {

  int items[] = {0, 1, 2, 3, 4, 5};
  uint length = sizeof(items) / sizeof(items[0]);

  print_array(items, length);
  uint index = binary_search(items, length, 1);
  fprintf(stdout, "\nIndex: %d\n", index);

  return EXIT_SUCCESS;
}
