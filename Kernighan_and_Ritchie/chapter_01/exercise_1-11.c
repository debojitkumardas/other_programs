/* Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */

/* the word count program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN  1
#define OUT 0

typedef struct {
    char *text;
    int len;
} result;

result* test_01() {
    char test_string[] = "Hello, World!! This is a word counting program.\n";
    int len = strlen(test_string);

    result *ptr = malloc(sizeof(result));

    ptr->text = test_string;
    ptr->len = len;

    return ptr;
}

void counting(int *nl, int *nw, int *nc, char text[]) {

    int c, state = OUT;

    for (int i = 0; text[i] != 0; ++i) {
        c = text[i];
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
}

int main() {

    char test_string[] = "Hello, World!! This is a word counting program.\n";

    int nl, nw, nc;

    nl = nw = nc = 0;
    counting(&nl, &nw, &nc, test_string);

    printf("Number of lines: %d\n", nl);
    printf("Number of words: %d\n", nw);
    printf("Number of characters: %d\n", nc);

    return 0;
}
