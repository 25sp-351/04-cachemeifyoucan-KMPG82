#include "cache.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>

#define NOT_PRESENT -1
#define ARRAY_SIZE 10

int cache_array[ARRAY_SIZE];
int cache_index = 0;

function_ptr real_provider;

/* initializes the cache and function pointers */
function_ptr init_cache(function_ptr rod_cutting) {
    for (int ix = 0; ix < ARRAY_SIZE; ix++)
        cache_array[ix] = NOT_PRESENT;

    real_provider = rod_cutting;

    return cache;
}

int cache(int rod_length, const int length_options[], const int length_values[],
          int number_of_length_options, int cuts[], int *remainder) {

    if (cache_array[rod_length] == NOT_PRESENT) {
        int max_value =
            (*real_provider)(rod_length, length_options, length_values,
                             number_of_length_options, cuts, remainder);

        cache_array[rod_length] = max_value;
    }

    return cache_array[rod_length];
}
