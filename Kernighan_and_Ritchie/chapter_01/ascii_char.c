#include <stdio.h>

int main() {

    for (int i = 0; i < 256; i++) {
        printf("%d: ", i);
        putchar(i);
        putchar('\n');
    }

    return 0;
}
