#ifndef ARRAY_H
#define ARRAY_H

#include "allocator.h"

#define DEBUG

#define ARRAY_CAPACITY_DEFAULT 16

typedef struct ArrayHeader {
  Allocator* m_allocator;
  u64 m_capacity;
  u64 m_len;
  u8 m_pad[8];
} ArrayHeader;

#ifdef DEBUG
void ArrayHeader_print(ArrayHeader* ah);
#define AH_PRINT(ah) ArrayHeader_print((ArrayHeader*) (ah))
#else
#define AH_PRINT(ah) 
#endif

ArrayHeader* array_header(void* arr);

u64 array_len(void* arr);

void* array_new(u64 dataSize, u64 arrSize, Allocator* a);

void* array_ensure_capacity(void* arr, u64 dataCount, u64 dataSize);

#define array(T, a) array_new(sizeof(T), 16, (a))

#define array_capacity(arr) (array_header(arr)->m_capacity)

#define array_append(arr, v) ( \
    (arr) = array_ensure_capacity(arr, 1, sizeof(v)), \
    (arr)[array_header(arr)->m_len] = (v), \
    &(arr)[array_header(arr)->m_len++])

#endif
