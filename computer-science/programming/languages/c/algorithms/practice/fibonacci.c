#include <stdio.h>
#include <cs50.h>

//fibonacci using recursion

int fibonacci_number(int position) {
    if (position == 1){
        return 0;
    }
    if (position == 2) {
        return 1;
    }
    return (fibonacci_number(position - 1) + fibonacci_number(position - 2));
}

int main() {
    printf("\nSearch out fibonacci number in a certain position.\n");

    int number;

    do
    {
        number = get_int("Type the position: ");
    } while (number <= 0);

    printf("The number of position %d is %d.\n", number, fibonacci_number(number));

    return 0;
}