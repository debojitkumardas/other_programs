#include <stdio.h>
#include <math.h>

#define XMAX 10
#define YMAX 10
#define RADIUS 10

int main(void) {

    // loop
    // printf("\x1b[2J");
    for (int y = -YMAX; y <= YMAX; y++) {
        for (int x = -XMAX; x <= XMAX; x++) {
            if (x*x + y*y == RADIUS * RADIUS)
                putchar('@');
            else
                putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}
