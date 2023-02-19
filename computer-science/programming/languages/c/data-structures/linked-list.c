// Prepend linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(int argc, char **argv){    //(string argv[]), (char *argv[])
    node *list = NULL;

    int i, number;

    for (i = 1; i < argc; i++) {
        number = atoi(argv[i]);     //atoi -> ascii to integer

        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }

        n->number = number;
        // n->next = NULL;
        n->next = list;
        list = n;
    }

    node *tmp = list;

    while (tmp != NULL)
    {
        printf("%i\n", tmp->number);
        tmp = tmp->next;
    }

    tmp = list;

    while (tmp != NULL) {
        node *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    return 0;
}
