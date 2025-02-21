#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

#include "linked_list_node.h"

Linked_list* create_linked_list() {
    Linked_list* new_ll = malloc(sizeof(Linked_list));
    new_ll->head        = NULL;
    new_ll->tail        = NULL;

    return new_ll;
}

void insert_linked_list_node(int index, Linked_list** eviction_tracker) {
    Linked_list_node* new_node = create_linked_list_node(index);

    if ((*eviction_tracker)->head == NULL &&
        (*eviction_tracker)->tail == NULL) {
        (*eviction_tracker)->head = new_node;
        (*eviction_tracker)->tail = new_node;
        return;
    }

    (*eviction_tracker)->tail->next = new_node;
    (*eviction_tracker)->tail       = new_node;
}

int evict_index(Linked_list** eviction_tracker) {
    if ((*eviction_tracker)->head == NULL)
        return -1;

    int index_to_evict                       = (*eviction_tracker)->head->index;

    Linked_list_node* node_of_index_to_evict = (*eviction_tracker)->head;

    (*eviction_tracker)->head                = (*eviction_tracker)->head->next;

    if ((*eviction_tracker)->tail == node_of_index_to_evict)
        (*eviction_tracker)->tail = NULL;

    free(node_of_index_to_evict);

    return index_to_evict;
}
