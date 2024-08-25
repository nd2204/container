#include "../src/list.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

Node* print_node(Node* const p) {
  printf("%p: (%lluB) %s\n", p, p->m_size,(char*) p->m_data);
  return p;
}

void test_node() {
  const char* data = "Hello world";
  u64 dataSize = strlen(data) + 1;

  const char* newData = "This string is 29 bytes long";
  u64 newDataSize = strlen(newData) + 1;

  Node* np = node_new(data, dataSize);
  assert(np->m_size == dataSize);

  np = np->m_next;
  np = node_new(newData, newDataSize);
  assert(np->m_size == newDataSize);
}

void test_list() {
  const char* data = "Hello world";
  u64 dataSize = strlen(data) + 1;
  const char* newData = "This string is 29 bytes long";
  u64 newDataSize = strlen(newData) + 1;

  List list = list_new();

  printf("============================================\n");
  printf("[*] Running test 1: initialization behaviour\n");
  printf("============================================\n");

  printf("+ List has correct size: ");
  assert(list.m_len == 0);
  printf("Passed\n");

  printf("+ List head and tail set to NULL: ");
  assert(list.m_head == 0 && list.m_tail == NULL);
  printf("Passed\n");

  list_push(&list, data, dataSize);

  printf("+ List has correct size after pushing new data to it: ");
  assert(list.m_len == 1);
  printf("Passed\n");

  printf("============================================\n");
  printf("[*] Running test 2: basic list operation\n");
  printf("============================================\n");
  // TODO add list pop test

  printf("+ List behave correctly when added an element: ");
  assert(list.m_head != NULL && list.m_head == list.m_tail);

  list_push(&list, data, strlen(data) + 1);
  assert(list.m_head != NULL && list.m_head != list.m_tail);
  printf("Passed\n");

  printf("+ List copy have difference memory allocated to it: ");
  List newList = list_copy(&list);
  assert(list.m_head != newList.m_head);
  printf("Passed\n");

  list_push(&list, newData, newDataSize);
  Node* elem = list_find(&list, 2);

  printf("+ List return a pointer with a given index: ");
  assert(elem->m_size == newDataSize);
  printf("Passed\n");

  list_free(&list);
  list_free(&newList);
}

int main() {
  test_list();
}
