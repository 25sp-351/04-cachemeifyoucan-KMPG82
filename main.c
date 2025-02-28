#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cache_policy_a.h"
#include "error_handling.h"
#include "helpers.h"
#include "rod_cutting.h"

#define INITIAL_SIZE 5
#define BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int remainder                = 0;
    int number_of_length_options = 0;
    int array_size               = INITIAL_SIZE;
    int *length_options          = malloc(INITIAL_SIZE * sizeof(int));
    int *values                  = malloc(INITIAL_SIZE * sizeof(int));
    function_ptr provider        = init_cache(rod_cutting);

    if (argc != 2 || !sscanf(argv[1], "%s", buffer)) {
        printf("Invalid file name. For example, \"options.txt\"\n");
        return 0;
    }

    read_file(&length_options, &values, &number_of_length_options, &array_size,
              buffer);

    int *cuts = calloc(number_of_length_options, sizeof(int));

    sort(length_options, values, number_of_length_options);

    int rod_length;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (!sscanf(buffer, "%d", &rod_length) ||
            rod_length_additional_characters(buffer)) {
            printf(
                "Invalid input. Only enter positive integers. For example "
                "\"5\".\n");
            continue;
        }

        int max_val = provider(rod_length, length_options, values,
                               number_of_length_options, cuts, &remainder);

        print_results(length_options, values, cuts, number_of_length_options,
                      remainder, max_val);
        printf("\n");

        memset(cuts, 0, number_of_length_options * sizeof(int));
    }

    return 0;
}
