#include <stdio.h>
#include <time.h>

#define NUMBER_OF_ELEMENTS 2000000

/*
DIFFERENCE BETWEN fwrite vs fprintf!!!
fwrite is for binary data
fprintf is for normal text
*/

int main() {

    FILE* fpointer = fopen("data.in", "w");
    if (fpointer == NULL) {
        printf("Error: File does not exist.\n");
        return 1;
    }

    time_t start;
    start = time(&start);

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        // write to file specified
        if (i == NUMBER_OF_ELEMENTS - 1) {
            fprintf(fpointer, "%d", NUMBER_OF_ELEMENTS - i);
        }
        else {
            fprintf(fpointer, "%d\n", NUMBER_OF_ELEMENTS - i);
        }
    }

    time_t end;
    end = time(&end);

    fclose(fpointer);

    printf("Write to file successful!\n");
    printf("Time taken: %lds\n", (end - start));

    return 0;
}