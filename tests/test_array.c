#include "../src/array.h"
#include <memory.h>
#include <malloc.h>
#include <assert.h>

int main() {
  Allocator my_allocator = {default_alloc, default_free, 0};
  int *arr = array(int, &my_allocator);

  array_append(arr, 20);
  array_append(arr, 16);
  array_append(arr, 32);
  array_append(arr, 10);

  ArrayHeader* ah = array_header(arr);
  assert(ah->m_len == 4);

  AH_PRINT(ah);
}
