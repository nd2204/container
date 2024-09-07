#include <stdio.h>
#include "../include/container.h"

int main() {
  String s1 = str("Hello World!");
  String s2 = str("Hello Duong!");

  String *strArr = array(String, &g_stringAllocator);
  array_append(strArr, s1);
  array_append(strArr, s2);

  for (int i = 0; i < array_len(strArr); ++i) {
    printf("%s\n", strArr[i].m_data);
  }

  /* printf("%s\n", str_scat(&s1, &s2)); */
  /* printf("%s\n", s1.m_data); */
  /* printf("%llu\n", s1.m_len); */
  /* printf("%d", str_find(&s1, "Duong!")); */
  return 0;
}
