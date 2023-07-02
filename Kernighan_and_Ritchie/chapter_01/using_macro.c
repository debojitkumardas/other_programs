#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {

    int fahr;

    printf("Fahrenheit Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%10d %7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

    return 0;
}
