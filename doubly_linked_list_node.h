#pragma once
#include "bst_node.h"

typedef struct Doubly_linked_list_node {
    int rod_length;
    struct Doubly_linked_list_node *next;
    struct Doubly_linked_list_node *previous;
} Doubly_linked_list_node;

Doubly_linked_list_node *create_doubly_linked_list_node(int rod_length);
