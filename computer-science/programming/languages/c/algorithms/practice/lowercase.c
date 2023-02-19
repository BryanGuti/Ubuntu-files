#include <cs50.h>
#include <stdio.h>

// ASCII code: 'a'-> 97, 'A'-> 65, 'z' -> 122, 'Z' -> 90

int length_string(string text);
string to_uppercase(string text);

int main(void) {
    string text = get_string("Type any text: ");

    printf("\nLowercase:\t%s\n", to_uppercase(text));

    return 0;
}

int length_string(string text) {
    int length = 0;

    while (text[length] != '\0') {
        length++;
    }

    return length;
}

string to_uppercase(string text) {
    int length = length_string(text);
    for (int i = 0; i < length; i++) {
        if (text[i] >= 65 && text[i] <= 90) {
            text[i] += 32;
        }
    }

    return text;
}
