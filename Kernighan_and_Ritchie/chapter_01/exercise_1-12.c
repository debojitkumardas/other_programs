/* Exercise 1-12. Write a program that prints its input one word per line. */

#include <stdio.h>

int main() {

    char test_string[] = "Hello, World!! This is an interesting program.\n";
    int c;

    for (int i = 0; test_string[i] != 0; ++i) {
        c = test_string[i];
        if (c == ' ' || c == '\t')
            printf("\n");
        else
            putchar(c);
    }
}
