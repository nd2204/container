#include "allocator.h"
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

Allocator get_default_allocator() {
  return (Allocator) {
    .alloc = default_alloc,
    .free = default_free,
    .context = 0
  };
}

Allocator g_defaultAllocator = {
  .alloc = default_alloc,
  .free = default_free,
  .context = 0
};
