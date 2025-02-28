#include "doubly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list_node.h"

/* creates a doubly linked list and initializes its values */
Doubly_linked_list* create_doubly_linked_list() {
    Doubly_linked_list* new_dll = malloc(sizeof(Doubly_linked_list));
    new_dll->head               = NULL;
    new_dll->tail               = NULL;

    return new_dll;
}

/* inserts a node into the doubly linked list */
void insert_doubly_linked_list_node(int rod_length,
                                    Doubly_linked_list** eviction_tracker) {
    Doubly_linked_list_node* new_node =
        create_doubly_linked_list_node(rod_length);
    new_node->next = (*eviction_tracker)->head;

    if ((*eviction_tracker)->head != NULL)
        (*eviction_tracker)->head->previous = new_node;

    (*eviction_tracker)->head = new_node;

    if ((*eviction_tracker)->tail == NULL)
        (*eviction_tracker)->tail = new_node;
}

/* returns the index that is stored at the tail, the least recently used item in
   the cache and removes the node from the list */
int evict_index(Doubly_linked_list** eviction_tracker) {
    if ((*eviction_tracker)->tail == NULL)
        return -1;

    int rod_length_to_evict = (*eviction_tracker)->tail->rod_length;

    Doubly_linked_list_node* node_of_item_to_evict = (*eviction_tracker)->tail;

    if ((*eviction_tracker)->tail->previous) {
        (*eviction_tracker)->tail       = (*eviction_tracker)->tail->previous;
        (*eviction_tracker)->tail->next = NULL;
    } else {
        (*eviction_tracker)->head = NULL;
        (*eviction_tracker)->tail = NULL;
    }

    free(node_of_item_to_evict);

    return rod_length_to_evict;
}

/* moves the head of the list to the most recently used item in the cache */
void move_head(Doubly_linked_list** eviction_tracker, int rod_length) {
    if ((*eviction_tracker)->head->rod_length == rod_length)
        return;

    Doubly_linked_list_node* current_node = (*eviction_tracker)->head;

    while (current_node != NULL) {
        if (current_node->rod_length == rod_length) {
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

Doubly_linked_list_node* find_node_in_doubly_linked_list(
    Doubly_linked_list_node* head, int rod_length) {
    if (head == NULL)
        return NULL;

    while (head != NULL || head->rod_length == rod_length)
        head = head->next;

    return head;
}

void print_doubly_linked_list(Doubly_linked_list* list) {
    if (list == NULL || list->head == NULL) {
        printf("Empty.\n");
        return;
    }

    Doubly_linked_list_node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->rod_length);
        current = current->next;
    }
    printf("\n");
}
