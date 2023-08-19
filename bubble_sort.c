#include "lib.h"

void bubble_sort(int array[], uint length) {
  for (uint i = 0; i < length; ++i) {
    for (uint j = 0; j < length - 1 - i; ++j) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}

int main(void) {

  int items[] = {4, 1, 4, 2, 0, 8};
  uint length = sizeof(items) / sizeof(items[0]);

  print_array(items, length);

  bubble_sort(items, length);

  fprintf(stdout, "\nArray after sort:\n");
  print_array(items, length);

  return EXIT_SUCCESS;
}
