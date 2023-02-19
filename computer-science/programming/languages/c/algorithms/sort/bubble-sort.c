#include <stdio.h>

void bubble_sort(int numbers[], int length);
void swap(int *min_number, int *max_number);
void print_array(int numbers[], int length);

int main(void) {
    int numbers[] = {95, 87, 80, 73, 69, 65, 59, 52, 44, 40, 31, 24, 18, 10, 3};
    int length = sizeof(numbers) / sizeof(int);

    bubble_sort(numbers, length);
    printf("Sorted array:\t");
    print_array(numbers, length);

    return 0;
}

void bubble_sort(int numbers[], int length) {
    int i, j, n, m;

    for (i = 0, n = length - 1; i < n; i++){
        for (j = 0, m = n - i; j < m; j++) {
            if (numbers[j] > numbers[j + 1]){
                swap(&numbers[j + 1], &numbers[j]);
            }
        }
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
