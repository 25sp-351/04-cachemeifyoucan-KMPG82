#include "doubly_linked_list_node.h"

#include <stdio.h>
#include <stdlib.h>

/* creates a doubly linked list node and initializes its values */
Doubly_linked_list_node* create_doubly_linked_list_node(int index) {
    Doubly_linked_list_node* new_node = malloc(sizeof(Doubly_linked_list_node));
    new_node->index                   = index;
    new_node->next                    = NULL;
    new_node->previous                = NULL;

    return new_node;
}
