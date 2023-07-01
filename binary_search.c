#include "lib.h"

Bool binary_search(int array[], uint length, int item) {
  uint low = 0;
  uint high = length;

  while (low < high) {
    uint middle = floorff((low + high) / 2.);
    uint pivot = array[middle];

    if (pivot == item)
      return True;
    else if (item < pivot)
      high = middle;
    else
      low = middle + 1;
  }
  return False;
}

int main(void) {

  int items[] = {0, 1, 2, 3, 4, 5};
  uint length = sizeof(items) / sizeof(items[0]);

  print_array(items, length);
  Bool find = binary_search(items, length, 5);
  fprintf(stdout, "\nFound: %d\n", find);

  return 0;
}
