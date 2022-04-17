#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#include "generate_data.c"

#define MAX_BUFFER_SIZE 100

// All the helper functions
extern void generate_positive_integers_data();
extern void calculate_time_difference(struct timespec ts_start, struct timespec ts_end);

// All the sorting algorithms
extern void selection_sort(int* arr);
extern void bubble_sort(int* arr);
extern void insertion_sort(int* arr);
extern void counting_sort(int* arr);

int main() {

    // Research: https://www.geeksforgeeks.org/sorting-algorithms/

    generate_positive_integers_data();

    printf("\n");

    FILE* fpointer = fopen("positive_integers.in", "r");
    if (fpointer == NULL) {
        printf("Error: File does not exist.\n");
        return 1;
    }

    // get data from file
    int* arr = (int *) malloc(sizeof(int) * NUMBER_OF_ELEMENTS);
    if (arr == NULL) {
        printf("Error: not enough size for malloc.\n");
        return 1;
    }
    int line = 1;
    int index = 0;
    char buffer[MAX_BUFFER_SIZE] = { '\0' };
    while (fgets(buffer, MAX_BUFFER_SIZE, fpointer) != NULL) {
        // get the number
        int number = atoi(buffer);
        if (strcmp(buffer, "0") && number == 0) {
            printf("Error: Line %d is not an integer.\n", line);
        }
        else {
            arr[index] = number;
        }
        index += 1;
        line += 1;
    }

    // close the file
    fclose(fpointer);

    // selection sort
    printf("Selection Sort\n");
    // copy the array
    int* arr_copy = (int *) malloc(sizeof(int) * NUMBER_OF_ELEMENTS);
    if (arr_copy == NULL) {
        printf("Error: not enough size for malloc.\n");
        free(arr);
        return 1;
    }
    // copy the array
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        arr_copy[i] = arr[i];
    }
    // find the start time
    struct timespec ts_start;
    timespec_get(&ts_start, TIME_UTC);
    // call selection sort function
    selection_sort(arr_copy);
    // find the end time
    struct timespec ts_end;
    timespec_get(&ts_end, TIME_UTC);
    // find the time
    calculate_time_difference(ts_start, ts_end);

    printf("\n");

    // bubble sort
    printf("Bubble Sort\n");
    // copy the array
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        arr_copy[i] = arr[i];
    }
    // find the start time
    timespec_get(&ts_start, TIME_UTC);
    // call selection sort function
    bubble_sort(arr_copy);
    // find the end time
    timespec_get(&ts_end, TIME_UTC);
    // find the time
    calculate_time_difference(ts_start, ts_end);

    printf("\n");

    // insertion sort
    printf("Insertion Sort\n");
    // copy the array
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        arr_copy[i] = arr[i];
    }
    // find the start time
    timespec_get(&ts_start, TIME_UTC);
    // call selection sort function
    insertion_sort(arr_copy);
    // find the end time
    timespec_get(&ts_end, TIME_UTC);
    // find the time
    calculate_time_difference(ts_start, ts_end);

    printf("\n");

    // counting sort
    printf("Counting Sort\n");
    // copy the array
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        arr_copy[i] = arr[i];
    }
    // find the start time
    timespec_get(&ts_start, TIME_UTC);
    // call selection sort function
    counting_sort(arr_copy);
    // find the end time
    timespec_get(&ts_end, TIME_UTC);
    // find the time
    calculate_time_difference(ts_start, ts_end);

    // quick sort

    // merge-sort

    // heap sort

    // free the malloc'ed array
    free(arr_copy);
    free(arr);

    return 0;
}

void calculate_time_difference(struct timespec ts_start, struct timespec ts_end) {

    long sec = ts_end.tv_sec - ts_start.tv_sec;
    float nanosec = ts_end.tv_nsec - ts_start.tv_nsec;
    if (nanosec < 0) {
        nanosec += 1000000000;
        sec -= 1;
    }
    printf("Time taken: %ld.%.0fs\n", sec, nanosec);
}

void selection_sort(int* arr) {
    
    // go through each element in the array
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        // find the minimum element
        int minimum = arr[i];
        int index = i;
        for (int j = i + 1; j < NUMBER_OF_ELEMENTS; j++) {
            if (minimum > arr[j]) {
                minimum = arr[j];
                index = j;
            }
        }
        // swap between the minimum and the i-th element
        int temp = arr[i];
        arr[i] = minimum;
        arr[index] = temp;
    }
}

void bubble_sort(int* arr) {

    // go through each element in the array
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        // swapping through each elements
        for (int j = 0; j < NUMBER_OF_ELEMENTS; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int* arr) {

    // go through each element in the array
    for (int i = 1; i < NUMBER_OF_ELEMENTS; i++) {
        // get the current value
        int current_value = arr[i];
        // compare with the values in front
        int j = 0;
        int need_to_insert = 0;
        for (j; j < i; j++) {
            if (arr[i] < arr[j]) {
                need_to_insert = 1;
                break;
            }
        }
        // move the values behind
        if (need_to_insert) {
            int temp = arr[i];
            for (int k = j + 1; k < i + 1; k++) {
                arr[i - k + 1] = arr[i - k];
            }
            arr[j] = temp;
        }
    }
}

void counting_sort(int* arr) {

    // find the largest number
    int largest_number = arr[0];
    for (int i = 1; i < NUMBER_OF_ELEMENTS; i++) {
        if (largest_number < arr[i]) {
            largest_number = arr[i];
        }
    }
    int* counting_arr = (int *) calloc(largest_number, sizeof(int));
    if (counting_arr == NULL) {
        printf("Error: Counting sort fails!\n");
        return;
    }
    // put each element into the counting array
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        counting_arr[ arr[i] ] += 1;
    }
    // sort the array
    int index = 0;
    for (int i = 0; i < largest_number; i++) {
        if (counting_arr[i] != 0) {
            for (int j = 0; j < counting_arr[i]; j++) {
                arr[index] = i;
                index += 1;
            }
        }
    }
    free(counting_arr);
}