#include "../include/container.h"
#include <memory.h>
#include <malloc.h>
#include <assert.h>

int main() {
  Allocator my_allocator = {default_alloc, default_free, 0};
  int *arr = array(int, &my_allocator);

  printf("Appending 4 integer into the array:\n");

  // NOLINTBEGIN
  array_append(arr, 20);
  array_append(arr, 16);
  array_append(arr, 32);
  array_append(arr, 10);
  // NOLINTEND

  ArrayHeader* ah = array_header(arr);

  printf("Expecting 4 element in the array: ");
  assert(ah->m_len == 4);
  printf("PASSED");

  AH_PRINT(ah);
}
