#include "cache.h"

#include <stdio.h>
#include <stdlib.h>

#include "Bst_node.h"
#include "helpers.h"

#define CAPACITY 10

Bst_node *nodes;
Bst_node root;
int current_size;
function_ptr real_provider;

/* initializes the cache and function pointers */
function_ptr init_cache(function_ptr rod_cutting) {
    real_provider = rod_cutting;
    nodes         = malloc(CAPACITY * sizeof(struct bst_node));
    root          = NULL;
    current_size  = 0;

    for (int ix = 0; ix < CAPACITY; ix++)
        nodes[ix] = NULL;

    return cache;
}

int cache(int rod_length, const int length_options[], const int length_values[],
          int number_of_length_options, int cuts[], int *remainder) {

    if (NULL) {
        int max_value =
            (*real_provider)(rod_length, length_options, length_values,
                             number_of_length_options, cuts, remainder);

        // cache_array[rod_length] = max_value;
    }

    return NULL;  // cache_array[rod_length];
}
