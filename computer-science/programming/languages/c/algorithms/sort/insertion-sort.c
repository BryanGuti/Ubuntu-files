// #include <cs50.h>
#include <stdio.h>

void insertion_sort(int numbers[], int length);
void print_numbers(int numbers[], int length);

int main(void) {
    int numbers[] = {95, 87, 80, 73, 69, 65, 59, 52, 44, 40, 31, 24, 18, 10, 3};

    int length = (sizeof(numbers) / sizeof(int));

    // for (int i = 0; i < 15; i++) {
    //     printf("Position %i\t%i\n", i, numbers[i]);
    //     printf("Direction %i\t%p\n", i, (numbers + i));
    //     printf("\n");
    // }

    insertion_sort(numbers, length);
    print_numbers(numbers, length);

    return 0;
}

void insertion_sort(int numbers[], int length) {
    int i, j, current_number;
    int counter = 0;
    for (i = 1; i < length; i++) {
        current_number = numbers[i];
        j = i - 1;

        while (j >= 0 && numbers[j] > current_number) {
            counter++;
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = current_number;
    }
    printf("%i\n", counter);
}

void print_numbers(int numbers[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%i ", numbers[i]);
    }
    printf("\n");

}
