/* Exercise 1-2. Experiment to find out what happens when print's argument string contains \c, where c is some character not listed above. */

#include <stdio.h>

int main() {
    // printf("hello, world \c \n");  // shows are error: unknown escape sequence
    printf("For \\c the following error is displayed: unknown escape sequence.\n");

    return 0;
}
