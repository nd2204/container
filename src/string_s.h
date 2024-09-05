#ifndef STRING_T_H
#define STRING_T_H

#include "string.h"
#include "types.h"
#include "list.h"

// All string must be heap allocated
typedef struct string_s {
  u64 m_len;
  char* m_data;
} string_s;

string_s str_new(const char *s);

u64 str_len(const string_s* const sp);

const char* str_cat(string_s* dest, const char *s);

const char* str_scat(string_s* dest, string_s *src);

void str_free(const string_s* sp);

#endif
