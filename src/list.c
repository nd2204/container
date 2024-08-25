#include "types.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

static Node* return_node(Node* const np) {
  return np;
}

List list_new() {
  List l;
  l.m_len = 0;
  l.m_head = NULL;
  l.m_tail = NULL;
  return l;
}

void list_push(List* const lp, const void* const data, u64 data_size) {
  if (lp == NULL) {
    *lp = list_new();
  }

  Node *new_node = node_new(data, data_size);
  if (lp->m_len <= 0) {
    lp->m_head = new_node;
    lp->m_tail = lp->m_head;
  } else {
    lp->m_tail->m_next = new_node;
    lp->m_tail = new_node;
  }

  lp->m_len++;
}

Node* list_find(const List* const lp, u64 idx) {
  if (lp == NULL || idx > lp->m_len - 1) return NULL;
  Node *p = lp->m_head;
  for (; idx > 0; --idx) {
    p = p->m_next;
  }
  return p;
}

List list_copy(List* const lp) {
  List l = list_foreach(lp, return_node);
  return l;
}

List list_foreach(List* const lp, Node* (*cb)(Node* const)) {
  List l = list_new();
  if (lp == NULL) return l;
  for (Node *p = lp->m_head; p != NULL; p = p->m_next) {
    list_push(&l, cb(p), p->m_size); 
    l.m_len++;
  }
  return l;
}

void list_free(List* const lp) {
  if (lp == NULL) return;

  Node *curNode = lp->m_head;
  Node *nextNode = NULL;
  while(curNode != NULL) {
    nextNode = curNode->m_next;
    node_free(curNode);
    curNode = nextNode;
  }

  *lp = list_new();
}
