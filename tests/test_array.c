#include "../src/array.h"
#include <memory.h>
#include <malloc.h>

void* default_alloc(u64 bytes, void* context) {
  (void) context;
  return malloc(bytes);
}

void* default_free(u64 bytes, void* ptr, void* context) {
  (void)ptr, (void) context;
  free(ptr);
  return 0;
}

int main() {
  Allocator my_allocator = {default_alloc, default_free, 0};
  int *arr = array(int, &my_allocator);

  array_append(arr, 20);

  /* printf("%lu", sizeof("What")); */
}
