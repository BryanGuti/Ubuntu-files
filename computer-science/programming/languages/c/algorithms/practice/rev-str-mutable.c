#include <cs50.h>
#include <stdio.h>
#include <string.h>

void reverse_string(string str){
    int length = strlen(str);
    char temp;
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main(void) {
    string str = get_string("Type the text you want to reverse: ");

    printf("\nThe original string is: \t%s\n", str);
    reverse_string(str);
    printf("\nThe reversed string is: \t %s\n", str);

    return 0;
}
