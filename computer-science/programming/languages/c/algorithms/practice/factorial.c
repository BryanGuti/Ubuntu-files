// Get a integer number and calculate number's factorial
#include <stdio.h>
#include <cs50.h>

long factorial(int number) {
    if (number == 0) {
        return 1;
    }
    return number * factorial(number - 1);
}

int main(void) {
    int number;
    do
    {
        number = get_int("\nType a number greater or equal than 0: ");
    } while (number < 0);

    printf("\n\nThe factorial of %d is: \t%ld\n", number, factorial(number));

    return 0;
}