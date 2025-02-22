#pragma once

typedef struct Doubly_linked_list_node {
    int index;
    struct Doubly_linked_list_node *next;
    struct Doubly_linked_list_node *previous;
} Doubly_linked_list_node;

Doubly_linked_list_node *create_doubly_linked_list_node(int index);
