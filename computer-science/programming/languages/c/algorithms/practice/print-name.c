#include <stdio.h>
#include <cs50.h>

int main() {
    string name = get_string("Type your name: ");

    printf("Hi!, %s, welcome to my PC.\n", name);

    return 0;
}