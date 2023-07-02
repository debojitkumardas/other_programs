/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */

#include <stdio.h>

int main() {

    int c, count = 1;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            count = 1;
        }
        else if (count < 2) {
            putchar(c);
            count++;
        }
    }

    return 0;
}
