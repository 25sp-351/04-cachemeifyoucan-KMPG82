#include "cache_policy_a.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst_node.h"
#include "helpers.h"
#include "linked_list.h"

#define CACHE_SIZE 5
#define EMPTY NULL

Bst_node **cache_array;
Bst_node *root;
Linked_list *eviction_tracker;
function_ptr real_provider;
int current_size;
int open_index;

/* initializes the cache and function pointers */
function_ptr init_cache(function_ptr rod_cutting) {
    real_provider    = rod_cutting;
    cache_array      = malloc(CACHE_SIZE * sizeof(Bst_node *));
    root             = NULL;
    current_size     = 0;
    open_index       = 0;
    eviction_tracker = create_linked_list();

    for (int ix = 0; ix < CACHE_SIZE; ix++)
        cache_array[ix] = EMPTY;

    return cache;
}

/* responsible for returning requested data whether it is in cache or must be
   calcualted*/
int cache(int rod_length, const int length_options[], const int length_values[],
          int number_of_length_options, int cuts[], int *remainder) {
    Bst_node *requested_node = find_node(root, rod_length);
    int max_value;

    if (!requested_node) {
        printf("DID NOT FIND IT\n");
        max_value = (*real_provider)(rod_length, length_options, length_values,
                                     number_of_length_options, cuts, remainder);

        Bst_node *node = create_node(cuts, number_of_length_options, rod_length,
                                     max_value, *remainder);

        if (current_size == CACHE_SIZE) {
            int index_to_evict = evict_index(&eviction_tracker);

            delete_node(&root, cache_array[index_to_evict]->rod_length,
                        number_of_length_options);

            open_index = index_to_evict;
            current_size--;
            cache_array[index_to_evict] = NULL;
        }

        insert_node(&root, node);

        insert_linked_list_node(open_index, &eviction_tracker);

        cache_array[open_index] = node;
        open_index++;
        current_size++;

        if(current_size == CACHE_SIZE)
        {
            for (int i = 0; i < CACHE_SIZE;i++){
                printf("%d\n", cache_array[i]->rod_length);
            }

            print_ll(eviction_tracker);
        }
    } else {
        max_value  = requested_node->max_val;
        *remainder = requested_node->remainder;
        memcpy(cuts, requested_node->cuts,
               number_of_length_options * sizeof(int));
    }

    return max_value;
}
