#include "cache_policy_b.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst_node.h"
#include "helpers.h"
#include "random_index.h"

#define CACHE_SIZE 5
#define EMPTY -1

int *cache_array;
Bst_node *root;
function_ptr real_provider;
int current_size;
int open_index;

/* initializes the cache and function pointers */
function_ptr init_cache(function_ptr rod_cutting) {
    real_provider = rod_cutting;
    cache_array   = malloc(CACHE_SIZE * sizeof(int));
    root          = NULL;
    current_size  = 0;
    open_index    = 0;

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
            int index_to_evict = evict_index(CACHE_SIZE);

#ifdef DEBUG
            printf("-------------------------------------------\n");
            printf("EVICTING RANDOM INDEX: %d\n", index_to_evict);
#endif

            int rod_length_to_evict     = cache_array[index_to_evict];

            cache_array[index_to_evict] = EMPTY;

            delete_bst_node(&root, rod_length_to_evict,
                            number_of_length_options);

            open_index = index_to_evict;
            current_size--;
        }

        Bst_node *new_node = create_bst_node(cuts, number_of_length_options,
                                             rod_length, max_value, *remainder);

        insert_bst_node(&root, new_node);

        cache_array[open_index++] = new_node->rod_length;
        current_size++;
    } else {
        max_value  = requested_node->max_val;
        *remainder = requested_node->remainder;

        memcpy(cuts, requested_node->cuts,
               number_of_length_options * sizeof(int));
    }

#ifdef DEBUG
    printf("-------------------------------------------\n");
    printf("ROD LENGTHS IN CACHE ARRAY AFTER INSERTION: ");
    for (int ix = 0; ix < current_size; ix++)
        printf("%d ", cache_array[ix]);
    printf("\n-------------------------------------------\n");
#endif

    return max_value;
}
