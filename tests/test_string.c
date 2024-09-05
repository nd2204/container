#include <stdio.h>
#include "../src/string_s.h"

int main() {
  string_s s1 = str_new("Hello World!");
  string_s s2 = str_new("Hello Duong!");

  printf("%s", str_scat(&s1, &s2));
  printf("%s", s1.m_data);
  return 0;
}
