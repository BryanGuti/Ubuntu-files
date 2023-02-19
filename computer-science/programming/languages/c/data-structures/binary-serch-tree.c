#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int number;
    struct node *less;
    struct node *greater;
} node;

int main (int argc, char **argv) {
    // Complete algorithm
}

bool search(node *tree, int number) {
    if (tree == NULL) return false;
    if (tree->number == number) return true;
    if (tree->number < number) return search(tree->greater, number);
    else return search(tree->less, number);
}