#include <stdio.h>
#include <stdlib.h>
#include "linked_list_node.h"

Linked_list_node* create_linked_list_node(int index){
    Linked_list_node* new_node = malloc(sizeof(Linked_list_node));
    new_node->index            = index;
    new_node->next             = NULL;

    return new_node;
}