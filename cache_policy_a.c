#include "cache_policy_a.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst_node.h"
#include "doubly_linked_list.h"
#include "helpers.h"

#define CACHE_SIZE 5
#define EMPTY NULL

Bst_node *root;
Doubly_linked_list *eviction_tracker;
function_ptr real_provider;
int current_size;

/* initializes the cache and function pointers */
function_ptr init_cache(function_ptr rod_cutting) {
    real_provider    = rod_cutting;
    root             = NULL;
    current_size     = 0;
    eviction_tracker = create_doubly_linked_list();

    return cache;
}

/* responsible for returning requested data whether it is in cache or must be
   calcualted*/
int cache(int rod_length, const int length_options[], const int length_values[],
          int number_of_length_options, int cuts[], int *remainder) {
    Bst_node *requested_node = find_bst_node(root, rod_length);
    int max_value;

    if (requested_node == NULL) {
        max_value = (*real_provider)(rod_length, length_options, length_values,
                                     number_of_length_options, cuts, remainder);

        if (current_size == CACHE_SIZE) {
            int rod_length_to_evict = evict_index(&eviction_tracker);

            delete_bst_node(&root, rod_length_to_evict,
                            number_of_length_options);

            current_size--;
        }

        Bst_node *new_node = create_bst_node(cuts, number_of_length_options,
                                             rod_length, max_value, *remainder);

        insert_bst_node(&root, new_node);

        insert_doubly_linked_list_node(rod_length, &eviction_tracker);

        current_size++;
    } else {
        max_value  = requested_node->max_val;
        *remainder = requested_node->remainder;

        memcpy(cuts, requested_node->cuts,
               number_of_length_options * sizeof(int));

        move_head(&eviction_tracker, requested_node->rod_length);
    }

    return max_value;
}
