#ifndef STRING_T_H
#define STRING_T_H

#include "string.h"
#include "types.h"
#include "allocator.h"
#include "array.h"
#include "malloc.h"

#define str(x) str_new(x, &g_stringAllocator);

extern Allocator g_stringAllocator;

// All string must be heap allocated
typedef struct String {
  u64 m_len;
  char* m_data;
  Allocator* m_allocator;
} String;

String str_new(const char *s, Allocator* ap);

u64 str_len(const String* const sp);

const char* str_cat(String* dest, const char *s);

const char* str_scat(String* dest, String *src);

void str_free(const String* sp);

i32 str_find(const String* const sp, const char* target);

#endif
