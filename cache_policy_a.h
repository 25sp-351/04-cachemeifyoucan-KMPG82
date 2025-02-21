#pragma once

typedef int (*function_ptr)(int rod_length, const int length_options[],
                            const int length_values[],
                            int number_of_length_options, int cuts[],
                            int *remainder);

function_ptr init_cache(function_ptr rod_cutting);

int cache(int rod_length, const int length_options[], const int length_values[],
          int number_of_length_options, int cuts[], int *remainder);
