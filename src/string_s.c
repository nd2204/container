#include "string_s.h"
#include "malloc.h"

string_s str_new(const char *s) {
  string_s newString;

  if (s == NULL) {
    newString.m_len = 0;
    newString.m_data = "";
    return newString;
  }

  newString.m_len = strlen(s);
  newString.m_data = (char*) malloc(sizeof(char) * (newString.m_len + 1));

  if (newString.m_data == NULL) {
    perror("malloc");
  }

  strcpy(newString.m_data, s);
  return newString;
}

u64 str_len(const string_s* const sp) {
  return (sp == NULL) ? 0 : sp->m_len;
}

const char* str_cat(string_s* dest, const char *src) {
  if (src == NULL) return dest->m_data;
  strcat(dest->m_data, src);
  dest->m_len += strlen(src);
  return dest->m_data;
}

const char* str_scat(string_s* dest, string_s *src) {
  if (src == NULL) return dest->m_data;
  strcat(dest->m_data, src->m_data);
  dest->m_len += src->m_len;
  return dest->m_data;
}

void str_free(const string_s* sp) {
  if (sp == NULL || sp->m_data == NULL) return;
  free(sp->m_data);
}
