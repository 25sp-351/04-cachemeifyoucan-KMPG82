#include <stdio.h>
#include <string.h>

/* recursive function that explores all possible options of cutting a rod of a
given length and returns the maximum value that can be obtained with a given set
of length options and their values */
int rod_cutting(int rod_length, const int length_options[],
                const int length_values[], int number_of_length_options,
                int cuts[], int *remainder) {
    if (rod_length == 0)
        return 0;

    int best_value     = 0;
    int best_remainder = rod_length;
    int best_cuts[number_of_length_options];
    memcpy(best_cuts, cuts, sizeof(best_cuts));

    for (int ix = 0; ix < number_of_length_options; ix++) {
        int current_cuts[number_of_length_options];
        memcpy(current_cuts, cuts, sizeof(current_cuts));

        if (length_options[ix] <= rod_length) {
            current_cuts[ix]++;

            int current_remainder = (rod_length - length_options[ix]);
            int current_value =
                (length_values[ix] +
                 rod_cutting(current_remainder, length_options, length_values,
                             number_of_length_options, current_cuts,
                             &current_remainder));

            if (current_value > best_value) {
                best_value = current_value;
                memcpy(best_cuts, current_cuts, sizeof(best_cuts));
                best_remainder = current_remainder;
            }
        }
    }

    memcpy(cuts, best_cuts, sizeof(best_cuts));
    *remainder = best_remainder;

    return best_value;
}
