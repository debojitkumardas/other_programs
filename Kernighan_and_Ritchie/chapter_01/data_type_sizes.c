#include <stdio.h>

int main() {
    printf("size of int %ld bytes.\n", sizeof(int));
    printf("size of float %ld bytes.\n", sizeof(float));
    printf("size of char %ld byte.\n", sizeof(char));
    printf("size of short %ld bytes.\n", sizeof(short));
    printf("size of long %ld bytes.\n", sizeof(long));
    printf("size of double %ld bytes.\n", sizeof(double));
    printf("size of unsigned int %ld bytes.\n", sizeof(unsigned int));
    printf("size of unsigned short %ld bytes.\n", sizeof(unsigned short));
    printf("size of unsigned long %ld bytes.\n", sizeof(unsigned long));
    return 0;
}
