#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string first_str = get_string("Type the first string: ");
    string second_str = get_string("Type the second string: ");

    if (strcmp(first_str, second_str) == 0) {
        printf("Both strigs are equal.\n");
    } else {
        printf("Both strigs are different.\n");
    }

    return 0;
}
