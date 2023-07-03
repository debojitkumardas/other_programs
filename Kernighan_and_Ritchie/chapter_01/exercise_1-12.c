/* Exercise 1-12. Write a program that prints its input one word per line. */

#include <stdio.h>

#define IN  1
#define OUT 0

int main() {

    char test_string[] = "Hello, World!! This is an interesting program.\n";
    int c, state;

    state = OUT;
    for (int i = 0; test_string[i] != 0; ++i) {
        c = test_string[i];
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
        }
    }
}
