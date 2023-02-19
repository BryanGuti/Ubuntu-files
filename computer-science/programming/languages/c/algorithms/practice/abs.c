#include <stdio.h>
#include <cs50.h>

int get_abs(int number){
    if(number >= 0){
        return number;
    }
    return -number;
}

int main() {
    printf("Search out absolute value!!!\n\n");

    int number = get_int("Type the number you like to search absolute value out: ");

    printf("\nThe absolute value of %d is: %d\n", number, get_abs(number));

    return 0;
}