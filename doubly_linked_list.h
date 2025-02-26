#pragma once
#include "doubly_linked_list_node.h"

typedef struct Doubly_linked_list {
    Doubly_linked_list_node* head;
    Doubly_linked_list_node* tail;
} Doubly_linked_list;

Doubly_linked_list* create_doubly_linked_list();

void insert_doubly_linked_list_node(int rod_length,
                                    Doubly_linked_list** eviction_tracker);

int evict_index(Doubly_linked_list** eviction_tracker);

void move_head(Doubly_linked_list** eviction_tracker, int rod_length);

Doubly_linked_list_node* find_node_in_doubly_linked_list(
    Doubly_linked_list_node* head, int rod_length);

void print_doubly_linked_list(Doubly_linked_list* list);
