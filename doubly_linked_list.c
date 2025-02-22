#include "doubly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list_node.h"

Doubly_linked_list* create_doubly_linked_list() {
    Doubly_linked_list* new_dll = malloc(sizeof(Doubly_linked_list));
    new_dll->head               = NULL;
    new_dll->tail               = NULL;

    return new_dll;
}

void insert_doubly_linked_list_node(int index,
                                    Doubly_linked_list** eviction_tracker) {
    Doubly_linked_list_node* new_node = create_doubly_linked_list_node(index);
    new_node->next                    = (*eviction_tracker)->head;

    if ((*eviction_tracker)->head != NULL)
        (*eviction_tracker)->head->previous = new_node;

    (*eviction_tracker)->head = new_node;

    if ((*eviction_tracker)->tail == NULL)
        (*eviction_tracker)->tail = new_node;
}

int evict_index(Doubly_linked_list** eviction_tracker) {
    if ((*eviction_tracker)->tail == NULL)
        return -1;

    int index_to_evict = (*eviction_tracker)->tail->index;

    Doubly_linked_list_node* node_of_index_to_evict = (*eviction_tracker)->tail;

    if ((*eviction_tracker)->tail->previous) {
        (*eviction_tracker)->tail       = (*eviction_tracker)->tail->previous;
        (*eviction_tracker)->tail->next = NULL;
    } else {
        (*eviction_tracker)->head = NULL;
        (*eviction_tracker)->tail = NULL;
    }

    free(node_of_index_to_evict);

    return index_to_evict;
}

void move_head(Doubly_linked_list** eviction_tracker, int index) {
    if ((*eviction_tracker)->head->index == index)
        return;

    Doubly_linked_list_node* current_node = (*eviction_tracker)->head;

    while (current_node != NULL) {
        if (current_node->index == index) {
            if (current_node->previous != NULL)
                current_node->previous->next = current_node->next;

            if (current_node->next != NULL)
                current_node->next->previous = current_node->previous;

            if ((*eviction_tracker)->tail == current_node)
                (*eviction_tracker)->tail = current_node->previous;

            current_node->next     = (*eviction_tracker)->head;
            current_node->previous = NULL;

            if ((*eviction_tracker)->head != NULL)
                (*eviction_tracker)->head->previous = current_node;

            (*eviction_tracker)->head = current_node;

            return;
        }
        current_node = current_node->next;
    }
}
