/* Exercise 1-4. Write a program to print the corresponding Celsius to Fharenheit table. */

#include <stdio.h>

/* Table for conversion from Celsius to Fahrenheit
*   for celsius = 0, 20, ..., 300; floating point version. */

int main() {

    float fahr, celsius;
    float lower, upper, step;

    lower = 0;  // lower limit of celsius scale
    upper = 300;  // upper limit
    step = 20;  // step size

    celsius = lower;
    printf("Celsius Fahrenheit\n");
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%7.0f %10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
