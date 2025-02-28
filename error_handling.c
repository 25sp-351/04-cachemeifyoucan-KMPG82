#include <stdio.h>
#include <string.h>

/* takes in a string and checks for additional characters after inputting two
   integers */
int length_value_additional_characters(const char *buffer) {
    int length_parsed;
    sscanf(buffer, "%*d, %*d%n", &length_parsed);

    if (strlen(buffer) - length_parsed != 1 ||
        strlen(buffer) - length_parsed != 0) {
        return 0;
    }
    return 1;
}

/* takes in two integers and checks if they are positive integers */
int negative_length_value(int length, int value) {
    return (length > 0 && value > 0);
}

/* takes in a string and checks for additional characters after inputting an
   integer */
int rod_length_additional_characters(const char *buffer) {
    int length_parsed;

    return (sscanf(buffer, "%*d%n", &length_parsed) != 1 &&
            (strlen(buffer) - length_parsed) != 1);
}

/* takes in an integer and checks if it is a positive integer */
int negative_rod_length(int rod_length) {
    return (rod_length < 0);
}
