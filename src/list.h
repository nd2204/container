#pragma once

#include "types.h"
#include "node.h"

typedef struct List {
  u64   m_len;
  Node *m_head,
       *m_tail;
} List;

List list_new();

void list_push(List* const lp, const void* data, u64 data_size);

Node* list_find(const List* const lp, u64 idx);

void list_free(List* const lp);

List list_copy(List* const lp);

List list_foreach(List* const lp, Node* (*cb)(Node* const));
