#include <stdio.h>

void swap(void *a, void *b, unsigned size) {

    char *p, *q, temp;

    p = (char *)a;
    q = (char *)b;

    while (size > 0) {
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q++;
        size--;
    }
}

int main(void) {

    int a = 10, b = 20;

    printf("The value of a is %d and b is %d before exchange.\n", a, b);

    swap(&a, &b, sizeof(int));

    printf("The value of a is %d and b is %d after exchange.\n", a, b);

    float c = 15.2, d = 20.001;

    printf("The value of c is %.1f and d is %.3f before exchange.\n", c, d);

    swap(&c, &d, sizeof(float));

    printf("The value of c is %.3f and d is %.1f after exchange.\n", c, d);

    return 0;
}
