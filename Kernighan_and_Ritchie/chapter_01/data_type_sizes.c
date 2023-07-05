#include <stdio.h>

int main() {

    printf("size of int %ld bytes.\n", sizeof(int));
    printf("size of float %ld bytes.\n", sizeof(float));
    printf("size of char %ld byte.\n", sizeof(char));
    printf("size of short %ld bytes.\n", sizeof(short));
    printf("size of long %ld bytes.\n", sizeof(long));
    printf("size of double %ld bytes.\n", sizeof(double));
    printf("size of long double %ld bytes.\n", sizeof(long double));
    printf("size of unsigned int %ld bytes.\n", sizeof(unsigned int));
    printf("size of unsigned short %ld bytes.\n", sizeof(unsigned short));
    printf("size of unsigned long %ld bytes.\n", sizeof(unsigned long));

    int a;
    char c;
    printf("Enter an int: ");
    scanf("%d", &a);
    printf("Enter a char: ");
    scanf(" %c", &c);

    printf("The entered integer is: %d\n", a);
    printf("The entered character is: %c\n", c);

    return 0;
}
