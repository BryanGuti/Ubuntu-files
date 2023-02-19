#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string reverse_string(string text) {
    int length = strlen(text);
    string reversed_string = malloc(length + 1);

    for (int i = 0; i < length; i++)
    {
        reversed_string[i] = text[length - i - 1];
    }

    reversed_string[length] = 0;

    return reversed_string;
}

int main(void) {

    string text = get_string("\nType a text: ");

    printf("\nThe reversed text is: \n\t%s\n", reverse_string(text));

    return 0;
}
