#include "cache_policy_a.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst_node.h"
#include "doubly_linked_list.h"
#include "helpers.h"

#define CACHE_SIZE 5
#define EMPTY NULL

Bst_node **cache_array;
Bst_node *root;
Doubly_linked_list *eviction_tracker;
function_ptr real_provider;
int current_size;
int open_index;

/* initializes the cache and function pointers */
function_ptr init_cache(function_ptr rod_cutting) {
    real_provider    = rod_cutting;
    cache_array      = malloc(CACHE_SIZE * sizeof(Bst_node*));
    root             = NULL;
    current_size     = 0;
    open_index       = 0;
    eviction_tracker = create_doubly_linked_list();

    for (int ix = 0; ix < CACHE_SIZE; ix++)
        cache_array[ix] = EMPTY;

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
            int index_to_evict = evict_index(&eviction_tracker);
            Bst_node *node_to_evict = cache_array[index_to_evict];


            printf("EVICTING INDEX %d with value %d\n", index_to_evict,
                   cache_array[index_to_evict]->rod_length);
            cache_array[index_to_evict] = NULL;
            delete_bst_node(&root, node_to_evict->rod_length,
                            number_of_length_options);

            open_index = index_to_evict;
            current_size--;
        }

        Bst_node *new_node =
            create_bst_node(cuts, number_of_length_options, rod_length,
                            max_value, *remainder, open_index);

        insert_bst_node(&root, new_node);

        insert_doubly_linked_list_node(open_index, &eviction_tracker);

        cache_array[open_index] = new_node;
        current_size++;
        open_index++;
    } else {
        max_value  = requested_node->max_val;
        *remainder = requested_node->remainder;

        memcpy(cuts, requested_node->cuts,
               number_of_length_options * sizeof(int));

        move_head(&eviction_tracker, requested_node->index);
    }

    printf("---------------------------\n");
    print_doubly_linked_list(eviction_tracker);
    printf("---------------------------\n");
    print_bst(root);
    printf("---------------------------\n");

    return max_value;
}
