#include <stdio.h>
#include <time.h>

#define NUMBER_OF_ELEMENTS 10000

/*
DIFFERENCE BETWEN fwrite vs fprintf!!!
fwrite is for binary data
fprintf is for normal text
*/
void generate_positive_integers_data() {

    FILE* fpointer = fopen("positive_integers.in", "w");
    if (fpointer == NULL) {
        printf("Error: File does not exist.\n");
        return;
    }

    struct timespec ts_start;
    timespec_get(&ts_start, TIME_UTC);

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        // write to file specified
        if (i == NUMBER_OF_ELEMENTS - 1) {
            fprintf(fpointer, "%d", NUMBER_OF_ELEMENTS - i);
        }
        else {
            fprintf(fpointer, "%d\n", NUMBER_OF_ELEMENTS - i);
        }
    }

    struct timespec ts_end;
    timespec_get(&ts_end, TIME_UTC);

    fclose(fpointer);

    printf("Write to file successful!\n");

    long sec = ts_end.tv_sec - ts_start.tv_sec;
    float nanosec = ts_end.tv_nsec - ts_start.tv_nsec;
    if (nanosec < 0) {
        nanosec += 1000000000;
        sec -= 1;
    }
    printf("Time taken: %ld.%.0fs\n", sec, nanosec);
}
