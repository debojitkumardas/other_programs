/* Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */

/* the word count program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN  1
#define OUT 0

void run_test(char *test_string) {

    int nl, nw, nc, state;
    char c;

    state = OUT;
    nl = nw = nc = 0;
    while (*test_string != '\0') {
        c = *test_string;
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
        test_string++;
    }

    printf("Number of lines: %d\n", nl);
    printf("Number of words: %d\n", nw);
    printf("Number of characters: %d\n", nc);
}

int main() {

    char test_string_01[] = "Hello, World!! This is a word counting program.\n";
    char test_string_02[] = " \t \n \n \n";
    char test_string_03[] = ".... \t ... \n";
    char test_string_04[] = "String are fun. I wonder the things I'll disc-\nover while working through this exercises.\n";

    printf("Running test 01 for test string:\n");
    printf("%s\n", test_string_01);
    run_test(test_string_01);
    printf("\n\n");

    printf("Running test 02 for test string:\n");
    printf("%s\n", test_string_02);
    run_test(test_string_02);
    printf("\n\n");

    printf("Running test 03 for test string:\n");
    printf("%s\n", test_string_03);
    run_test(test_string_03);
    printf("\n\n");

    printf("Running test 04 for test string:\n");
    printf("%s\n", test_string_04);
    run_test(test_string_04);
    printf("\n\n");

    return 0;
}
