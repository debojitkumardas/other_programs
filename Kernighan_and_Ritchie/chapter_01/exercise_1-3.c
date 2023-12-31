#include <stdio.h>

/* print Fahrenheit-Celsius table
*   for fahr = 0, 20, ..., 300; floating point version */

int main() {

    float fahr, celsius;
    float lower, upper, step;

    lower = 0;  // lower limit of temperature
    upper = 300;  // upper limit of termperature
    step = 20;  // step size

    fahr = lower;
    printf("Celsius Fahrenheit\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%7.0f %10.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
