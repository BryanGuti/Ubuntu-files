#include <stdio.h>

void selection_sort(int numbers[], int length);
void swap(int *min_number, int *max_number);
void print_array(int numbers[], int length);

int main(void) {
    int numbers[] = {95, 87, 80, 73, 69, 65, 59, 52, 44, 40, 31, 24, 18, 10, 3};
    int length = sizeof(numbers) / sizeof(int);

    selection_sort(numbers, length);
    printf("Sorted array:\t");
    print_array(numbers, length);

    return 0;
}

void selection_sort(int numbers[], int length) {
    int i, j, minimum_index;

    for (i = 0; i < length - 1; i++) {
        minimum_index = i;

        for (j = i + 1; j < length; j++) {
            if (numbers[j] < numbers[minimum_index]){
                minimum_index = j;
            }
        }

        swap(&numbers[minimum_index], &numbers[i]);
    }
}

void swap(int *min_number, int *max_number) {
    int temp = *max_number;
    *max_number = *min_number;
    *min_number = temp;
}

void print_array(int numbers[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}
