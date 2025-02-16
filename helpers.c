#include <stdio.h>
#include <stdlib.h>

#include "error_handling.h"

#define SIZE_MULTIPLIER 2
#define BUFFER_SIZE 100

/* prints the distribution of cuts along with how much value they contributed to
the total, the remainder, and the most value that can be obtained */
void print_results(int length_options[], int values[], int cuts[],
                   int number_of_length_options, int remainder, int max_value) {
    for (int ix = 0; ix < number_of_length_options; ix++) {
        if (cuts[ix] != 0) {
            const int total_value = (cuts[ix] * values[ix]);
            printf("%d @ %d = %d\n", cuts[ix], length_options[ix], total_value);
        }
    }

    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", max_value);
}

/* uses a selection sort algorithm to sort the pieces in descending order based
on value, then based on length if values are the same */
void sort(int *length_options, int *values, int number_of_length_options) {
    for (int ix = 0; ix < number_of_length_options; ix++) {
        for (int jx = ix + 1; jx < number_of_length_options; jx++) {
            if (values[ix] < values[jx]) {
                int temp           = values[ix];
                values[ix]         = values[jx];
                values[jx]         = temp;

                temp               = length_options[ix];
                length_options[ix] = length_options[jx];
                length_options[jx] = temp;
                continue;
            }

            if (values[ix] == values[jx]) {
                if (length_options[ix] < length_options[jx]) {
                    int temp           = length_options[ix];
                    length_options[ix] = length_options[jx];
                    length_options[jx] = temp;
                }
            }
        }
    }
}
