#include "lib.h"

int binary_search_recursive(int array[], int left, int right, int item) {

  if (left <= right) {
    uint middle = floorff((left + right) / 2.);

    if (item == array[middle])
      return middle;

    if (item < array[middle])
      return binary_search_recursive(array, left, middle, item);
    else
      return binary_search_recursive(array, middle + 1, right, item);
  }
  return -1;
}

int main(void) {

  int items[] = {0, 1, 2, 3, 4, 5};
  uint length = sizeof(items) / sizeof(items[0]);

  print_array(items, length);
  int index = binary_search_recursive(items, 0, length - 1, 5);
  fprintf(stdout, "\nIndex: %d\n", index);

  return EXIT_SUCCESS;
}
