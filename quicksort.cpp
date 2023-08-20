#include "lib.h"

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int index = low - 1;

  for (int i = low; i < high; ++i) {
    if (array[i] < pivot) {
      index++;
      lib::swap(&array[index], &array[i]);
    }
  }
  index++;
  lib::swap(&array[index], &array[high]);

  return index;
}

void quicksort(int array[], int low, int high) {
  if (low < high) {
    int pivot = partition(array, low, high);

    quicksort(array, low, pivot - 1);
    quicksort(array, pivot + 1, high);
  }
}

int main(void) {

  int items[] = {9, 5, 8, 3, 1, 0, 6, 8, 5, 9};
  uint length = sizeof(items) / sizeof(items[0]);

  lib::print_array(items, length);

  quicksort(items, 0, length - 1);

  std::cout << "\nArray after sort:" << std::endl;
  lib::print_array(items, length);

  return EXIT_SUCCESS;
}
