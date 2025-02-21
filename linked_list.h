#pragma once
#include "linked_list_node.h"

typedef struct Linked_list {
    Linked_list_node* head;
    Linked_list_node* tail;
} Linked_list;

Linked_list* create_linked_list();

void insert_linked_list_node(int index, Linked_list** eviction_tracker);

int evict_index(Linked_list** eviction_tracker);