#include <stdio.h>
#include <string.h>

/* checks for additional characters after inputting two integers representing
the length and value */
int length_value_additional_characters(const char *buffer) {
    int length_parsed;
    sscanf(buffer, "%*d, %*d%n", &length_parsed);

    if (strlen(buffer) - length_parsed != 1 || strlen(buffer) - length_parsed != 0){
        return 0;
    }
    return 1;
}

/* checks if length and value are positive integers */
int negative_length_value(int length, int value) {
    return (length > 0 && value > 0);
}

/* checks for additional characters after inputting an integer that represents
the rod length */
int rod_length_additional_characters(const char *buffer) {
    int length_parsed;

    return (sscanf(buffer, "%*d%n", &length_parsed) != 1 &&
            (strlen(buffer) - length_parsed) != 1);
}

/* checks if rod length is a positive integer */
int negative_rod_length(int rod_length) {
    return (rod_length < 0);
}
