#include "../src/list.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main() {
  List l = list_new();

  printf("[*] Running test 1: initialization behaviour\n");

  printf("+ List has correct size: ");
  assert(l.m_len == 0);
  printf("Passed\n");

  printf("+ List head and tail set to NULL: ");
  assert(l.m_head == 0 && l.m_tail == NULL);
  printf("Passed\n");

  char* data = "Hello world";
  list_push(&l, data, strlen(data) + 1);
  printf("[*] Running test 2: basic list operation\n");
  // TODO add list pop test

  printf("+ List behave correctly when added an element on empty:");
  assert(l.m_head != NULL && l.m_head == l.m_tail);
}
