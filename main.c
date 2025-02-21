#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cache_policy_a.h"
#include "error_handling.h"
#include "helpers.h"
#include "rod_cutting.h"

#define INITIAL_SIZE 5
#define BUFFER_SIZE 100
#define SIZE_MULTIPLIER 2

/* main function that takes in the rod length as an argument from the command
line */
int main(int argc, char *argv[]) {
    FILE *file_pointer = NULL;
    char buffer[BUFFER_SIZE];
    int remainder                = 0;
    int number_of_length_options = 0;
    int array_size               = INITIAL_SIZE;
    int length;
    int value;
    int *length_options   = malloc(INITIAL_SIZE * sizeof(int));
    int *values           = malloc(INITIAL_SIZE * sizeof(int));
    function_ptr provider = init_cache(rod_cutting);

    if (argc != 2 || !sscanf(argv[1], "%s", buffer)) {
        printf("Invalid input.\n");
        return 0;
    }

    file_pointer = fopen(buffer, "r");

    if (file_pointer == NULL) {
        printf("File not found.\n");
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
        if (sscanf(buffer, "%d, %d", &length, &value) != 2 ||
            length_value_additional_characters(buffer) ||
            negative_length_value(length, value) == 0) {
            printf(
                "Invalid input. Only enter positive integers in the specified "
                "format.  For example, \"24, 5\".\n");
            return 0;
        }

        if (number_of_length_options == array_size) {
            array_size *= SIZE_MULTIPLIER;

            values         = realloc(values, array_size * sizeof(int));
            length_options = realloc(length_options, array_size * sizeof(int));
        }

        length_options[number_of_length_options] = length;
        values[number_of_length_options]         = value;

        (number_of_length_options)++;
    }

    fclose(file_pointer);

    int *cuts = calloc(number_of_length_options, sizeof(int));

    sort(length_options, values, number_of_length_options);

    int rod_length;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (!sscanf(buffer, "%d", &rod_length) ||
            rod_length_additional_characters(buffer)) {
            printf("Invalid input.\n");
            continue;
        }

        int max_val = provider(rod_length, length_options, values,
                               number_of_length_options, cuts, &remainder);

        print_results(length_options, values, cuts, number_of_length_options,
                      remainder, max_val);

        memset(cuts, 0, number_of_length_options * sizeof(int));
    }

    return 0;
}
