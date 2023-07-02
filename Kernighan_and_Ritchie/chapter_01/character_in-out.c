#include <stdio.h>

int main() {

    int c;
    long nc = 0;

    while ((c = (getchar() != EOF))) {
        printf("%d", c);
        nc++;
    }

    printf("\n%d\n%ld\n", c, nc);

    return 0;
}
