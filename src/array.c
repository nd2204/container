#include "array.h"
#include <malloc.h>
#include <memory.h>

void* array_new(u64 dataSize, u64 arrSize, Allocator* a) {
  void *p = 0;
  u64 size = dataSize * arrSize + sizeof(ArrayHeader);
  ArrayHeader *header = a->alloc(size, 0);

  if (header) {
    header->m_capacity = 0;
    header->m_len = 0;
    header->m_allocator = a;
    p = header + 1;
  }

  return p;
}

ArrayHeader* array_header(void* arr) {
  return ((ArrayHeader*) arr) - 1;
}

u64 array_len(void* arr) {
  return array_header(arr)->m_len;
}

void* array_ensure_capacity(void* arr, u64 dataCount, u64 dataSize) {
  ArrayHeader *ah = array_header(arr);
  u64 desiredCapacity = ah->m_len + dataCount;

  if (ah->m_capacity >= desiredCapacity) {
    ah += 1;
  }
  else {
    u64 newCapacity = ah->m_capacity * 2;
    while (newCapacity < desiredCapacity) {
      newCapacity *= 2;
    }
    u64 newSize = sizeof(ArrayHeader) + newCapacity * dataSize;
    ArrayHeader *new_ah = ah->m_allocator->alloc(newSize, ah->m_allocator->context);

    if (new_ah) {
      u64 oldSize = sizeof(*ah) + ah->m_len * dataSize;
      memcpy(new_ah, ah, oldSize); 
      if (ah->m_allocator->free) {
        ah->m_allocator->free(oldSize, ah, ah->m_allocator->context);
      }

      new_ah->m_capacity = newCapacity;
      ah = new_ah + 1;
    }
    else {
      ah = 0;
    }
  }

  return ah; 
}
