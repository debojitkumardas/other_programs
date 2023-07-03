/* Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */

/* the word count program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN  1
#define OUT 0

int main() {

    char test_string[] = "Hello, World!! This is a word counting program.\n";

    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    for (int i = 0; test_string[i] != 0; ++i) {
        c = test_string[i];
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("Number of lines: %d\n", nl);
    printf("Number of words: %d\n", nw);
    printf("Number of characters: %d\n", nc);

    return 0;
}
