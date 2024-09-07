#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "types.h"

#define DEFAULT_ALLOCATOR ( \
  (Allocator) { \
    .alloc = default_alloc, \
    .free = default_free, \
    .context = 0 \
  })


typedef struct Allocator {
  void* (*alloc)(u64 bytes, void* context);
  void* (*free)(u64 bytes, void* ptr, void* context);
  void* context;
} Allocator;

void* default_free(u64 bytes, void* ptr, void* context);

void* default_alloc(u64 bytes, void* context);

Allocator get_default_allocator();

void* arena_alloc(u64 bytes, void* ptr, void* context);

void* arena_free(u64 bytes, void* context);

#endif
