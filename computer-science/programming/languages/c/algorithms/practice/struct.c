#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

struct Users {
    char *name;
    char *id;
    float credit;
    char *address;
};

int main (void) {

    struct Users user;
    user.name = get_string("Type the user name: ");
    user.id = "0";
    user.credit = get_float("Type the credit amount: ");
    user.address = get_string("Type the user's address: ");

    printf("\n");
    printf("\tUser name: \t%s\n", user.name);
    printf("\tUser id: \t%s\n", user.id);
    printf("\tUser credit: \t%f\n", user.credit);
    printf("\tUser address: \t%s\n", user.address);

    return 0;
}
