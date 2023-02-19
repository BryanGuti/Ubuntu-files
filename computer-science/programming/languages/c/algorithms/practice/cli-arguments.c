#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {//char** argv

    printf("Hello,");

    for (int i = 1; i < argc; i++) {
        printf(" %s", argv[i]);
    }

    printf("\n");

    return 0;
}
