#include "lib.h"

Bool linear_search(int array[], uint length, int item) {
  for (uint i = 0; i < length; ++i) {
    if (array[i] == item)
      return True;
  }
  return False;
}

int main(void) {

  int items[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  uint length = sizeof(items) / sizeof(items[0]);

  print_array(items, length);

  Bool find = linear_search(items, length, 5);
  fprintf(stdout, "\nFound: %d\n", find);

  return 0;
}
