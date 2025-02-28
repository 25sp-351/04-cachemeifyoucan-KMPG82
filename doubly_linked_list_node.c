#include "doubly_linked_list_node.h"

#include <stdio.h>
#include <stdlib.h>

/* takes in required data for a dll node and initializes a new dll node using
   the given data, returns the new node */
Doubly_linked_list_node* create_doubly_linked_list_node(int rod_length) {
    Doubly_linked_list_node* new_node = malloc(sizeof(Doubly_linked_list_node));
    new_node->rod_length              = rod_length;
    new_node->next                    = NULL;
    new_node->previous                = NULL;

    return new_node;
}
