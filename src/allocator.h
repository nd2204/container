#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "types.h"

typedef struct Allocator {
  void* (*alloc)(u64 bytes, void* context);
  void* (*free)(u64 bytes, void* ptr, void* context);
  void* context;
} Allocator;

#endif
