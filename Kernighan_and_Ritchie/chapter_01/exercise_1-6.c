/* Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

int main() {

    int c;

    printf("Enter a character, could be any character even an EOF (press ctrl + d) character.\n");

    if ((c = (getchar() != EOF)))
        printf("character entered; getchar() != EOF: %d\n", c);
    else
        printf("EOF entered; getchar() != EOF: %d\n", c);

    return 0;
}
