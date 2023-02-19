// Append linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

typedef struct {
    struct node *head;
    struct node *tail;
} list;

int main(int argc, char **argv) {
    list *l = malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;

    int i;

    for (i = 1; i < argc; i++) {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }

        n->number = number;
        n->next = NULL;

        if (l->head == NULL && l->tail == NULL){
            l->head = n;
            l->tail = n;
            continue;
        }

        l->tail->next = n;
        l->tail = n;
    }

    node *tmp = l->head;

    while (tmp != NULL) {
        printf("%i\n", tmp->number);
        tmp = tmp->next;
    }

    tmp = l->head;

    while (tmp != NULL) {
        node *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    free(l);

    return 0;
}
