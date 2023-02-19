#include <stdio.h>
#include <cs50.h>

int length_string(string str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

string capitalize(string str) {
    int length = length_string(str);

    if (str[0] >= 97 && str[0] <= 122) {
        str[0] -= 32;
    }

    for (int i = 1; i < length; i++){
        if ( str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }

    return str;
}

int main(void) {
    string str = get_string("Type any text: ");

    printf("Capitalize:\t%s\n", capitalize(str));

    return 0;
}