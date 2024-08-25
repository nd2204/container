#include "node.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

Node* node_new(const void* data, u64 data_size) {
  Node* p = (Node*) malloc(sizeof(Node));
  if (p == NULL) {
    fprintf(stderr, "FATAL: cannot allocate memory\n");
  }
  p->m_size = data_size;
  p->m_data = malloc(data_size);
  p->m_next = NULL;
  memcpy(p->m_data, data, data_size);
  return p;
}

Node* node_copy(Node* const other) {
  return node_new(other->m_data, other->m_size);
}

void node_free(Node* const np) {
  if (np->m_data)
    free(np->m_data);
  free(np);
}
