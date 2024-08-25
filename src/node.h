#pragma once

#include "types.h"

typedef struct Node {
  u64         m_size;
  void        *m_data;
  struct Node *m_next;
} Node;

Node* node_new(const void* data, u64 data_size);

Node* node_copy(Node* const other);

void node_free(Node* const np);
