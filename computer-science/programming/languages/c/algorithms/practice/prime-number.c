#include <stdio.h>
#include <cs50.h>

void search_out_prime_number(int number) {
    for (int i = 2; i <= number; i++)
    {
        if (number % i > 0){
            continue;
        }
        if ((number % i == 0) && (i < number)){
            printf("\n%d is not prime number.\n", number);
            break;
        }

        printf("\n%d is a prime number.\n", number);
    }
}

int main() {
    printf("\n\nSearch out if your number is a prime number!!\n\n");

    int number;
    do
    {
        number = get_int("Type the number you want to search out: ");
    } while (number <= 1);

    search_out_prime_number(number);

    return 0;
}