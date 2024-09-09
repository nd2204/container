#include "string_t.h"

String str_new(const char *s, Allocator* ap) {
  String newString;

  if (s == NULL) {
    newString.m_len = 0;
    newString.m_data = "";
    return newString;
  }

  newString.m_len = strlen(s);
  newString.m_data = ap->alloc(sizeof(char) * (newString.m_len + 1), ap->context);

  if (newString.m_data == NULL) {
    perror("alloc");
  }

  strcpy(newString.m_data, s);
  return newString;
}

u64 str_len(const String* const sp) {
  return (sp == NULL) ? 0 : sp->m_len;
}

const char* str_cat(String* dest, const char *src) {
  if (src == NULL) return dest->m_data;
  dest->m_len += strlen(src);
  dest->m_data = strcat(dest->m_data, src);
  return dest->m_data;
}

const char* str_scat(String* dest, String *src) {
  if (src == NULL) return dest->m_data;
  dest->m_len += src->m_len;
  dest->m_data = strcat(dest->m_data, src->m_data);
  return dest->m_data;
}

i32 str_find(const String* const sp, const char* target) {
  i32 targetLen = strlen(target);
  b8 match;
  for (i32 i = 0; i < sp->m_len; ++i) {
    match = true;
    for (i32 j = 0; j < targetLen; ++j) {
      if (target[j] != sp->m_data[j + i] || j + i >= sp->m_len) {
        match = false;
        break;
      }
    }
    if (match) return i;
  }
  return -1;
}

void str_free(const String* sp) {
  if (sp == NULL || sp->m_data == NULL) return;
  free(sp->m_data);
  sp->m_allocator->free(sizeof(String), (void*) sp, sp->m_allocator->context);
}
