#include <stdio.h>
#include <cs50.h>

int main() {
    int times = get_int("How many times you want to print?: ");

    for (int i = 0; i < times; i++)
    {
        printf("\nprinting line number %d\n", i + 1);
    }
    printf("END!!\n");

    return 0;
}
