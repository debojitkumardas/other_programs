/* Exercise 1-5. Modify the termperature conversion program to print the tabel in reverse order, that is, from 300 degree to 0. */

#include <stdio.h>

int main() {

    int fahr;

    printf("Fahrenheit Celsius\n");
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%10d %7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

    return 0;
}
