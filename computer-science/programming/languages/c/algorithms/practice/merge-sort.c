#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

void merge(int* list, int low, int mid, int high) {
    
}

void merge_sort(int* list, int low, int high){
    int mid;
    if (low < high) {
        mid = (low + high) / 2;

        merge_sort(list, low, mid);
        merge_sort(list, mid + 1, high);

        merge(list, low, mid, high);
    }
}

int main(void) {
    int length = get_int("Type the array's length: ");
    int *numbers = malloc(sizeof(int) * length);
    int i;
    for (i = 0; i < length; i++) {
        printf("Type the element %d:", i);
        numbers[i] = get_int(" ");
    }

    for (i = 0; i < length; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}