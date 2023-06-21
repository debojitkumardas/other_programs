#include <stdio.h>
#include <time.h>

int main(void)
{
    struct timespec ts;
    int msec;  // time in millisecond

    msec = 100;  // specifying wait time as 100 millisecond
    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    printf("The progress bar.\t");

    for (int i = 1; i < 101; i++) {
        if (i % 10 == 0)
            printf("#");

        if (i % 4 == 0 && i != 100)
            printf("-");
        if (i % 4 == 1)
            printf("\\");
        if (i % 4 == 2)
            printf("|");
        if (i % 4 == 3)
            printf("/");

        nanosleep(&ts, &ts);  // sleep() only takes in seconds; had to use nanosleep instead

        printf("%3d%c", i, '%');

        printf("\b\b\b\b\b");

        fflush(stdout);  // explicitly flushing the stream buffer
    }

    printf("\n");

    return 0;
}
