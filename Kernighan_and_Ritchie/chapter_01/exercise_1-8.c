/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main() {

    int c, n_tab, n_blank, n_newline;

    n_tab = 0;
    n_blank = 0;
    n_newline = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            ++n_tab;
        if (c == ' ')
            ++n_blank;
        if (c == '\n')
            ++n_newline;
    }

    printf("Count of tabs in the input: %d.\n", n_tab);
    printf("Count of blanks in the input: %d.\n", n_blank);
    printf("Count of newlines in the input: %d.\n", n_newline);

    return 0;
}
