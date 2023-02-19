#include <stdio.h>

void merge_sort(int numbers[], int length);
void print_array(int numbers[], int length);

int main(void) {
    int numbers[] = {95, 87, 80, 73, 69, 65, 59, 52, 44, 40, 31, 24, 18, 10, 3};
    int length = sizeof(numbers) / sizeof(int);

    merge_sort(numbers, length);
    printf("Sorted numbers:\t");
    print_array(numbers, length);

    return 0;
}

void merge_sort(int numbers[], int length) {

}

void print_array(int numbers[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}
