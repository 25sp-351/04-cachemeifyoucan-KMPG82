#pragma once

typedef struct Linked_list_node {
    int index;
    struct Linked_list_node *next;
} Linked_list_node;

Linked_list_node* create_linked_list_node(int index);