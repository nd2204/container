#include <stdio.h>
#include "../src/string_s.h"

int main() {
  Allocator a = get_default_allocator();
  String s1 = str_new("Hello World!", &a);
  String s2 = str_new("Hello Duong!", &a);

  printf("%s\n", str_scat(&s1, &s2));
  printf("%s\n", s1.m_data);
  printf("%d", str_find(&s1, "Duong!"));
  return 0;
}
