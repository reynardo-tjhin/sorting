#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <math.h>

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
extern void heap_sort(int* arr, int length);
extern void merge_sort(int* arr, int length);

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

    printf("\n");

    // heap sort
    printf("Heap Sort\n");
    // copy the array
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        arr_copy[i] = arr[i];
    }
    // find the start time
    timespec_get(&ts_start, TIME_UTC);
    // call selection sort function
    heap_sort(arr_copy, NUMBER_OF_ELEMENTS);
    // find the end time
    timespec_get(&ts_end, TIME_UTC);
    // find the time
    calculate_time_difference(ts_start, ts_end);

    printf("\n");

    // merge-sort
    printf("Merge Sort\n");
    // copy the array
    for (int i = 0; i < 10; i++) {
        arr_copy[i] = 10 - i;
    }
    // find the start time
    timespec_get(&ts_start, TIME_UTC);
    // call selection sort function
    merge_sort(arr_copy, 10);
    // find the end time
    timespec_get(&ts_end, TIME_UTC);
    // find the time
    calculate_time_difference(ts_start, ts_end);

    // quick sort

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
        printf("Error: Counting sort fails due to calloc not enough!\n");
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

void heap_sort(int* arr, int length) {

    // create a temporary heap
    int* heap = (int *) malloc(sizeof(int) * length);
    if (heap == NULL) {
        printf("Error: Heap sort fails due to malloc not enough!\n");
        return;
    }
    // put each element into heap
    for (int i = 0; i < length; i++) {
        heap[i] = arr[i];
        // upheap to restore the heap order
        int child = i;
        while (child != 0) {
            int parent;
            // index is even means it is a right child
            if (child % 2 == 0) {
                parent = (child - 2) / 2; // right child is at index 2i + 2 (where i is the index of parent)
            }
            // index is odd means it is a left child
            else {
                parent = (child - 1) / 2; // left child is at index 2i + 1 (where i is the index of parent)
            }

            // swap the parent and the child if the parent is greater than the child
            if (heap[parent] > heap[child]) {
                int temp = heap[child];
                heap[child] = heap[parent];
                heap[parent] = temp;
            }
            child = parent;
        }
    }

    // "remove" each element and put them back to arr to sort
    int end_index_of_heap = length - 1;
    for (int i = 0; i < length; i++) {
        
        arr[i] = heap[0]; // smallest is always the at the root of the heap
        
        // remove the root
        heap[0] = heap[end_index_of_heap];
        end_index_of_heap -= 1;

        // down heap
        int parent = 0;
        while ((end_index_of_heap != -1) && (parent < end_index_of_heap)) {

            // get the indices of left child and right child
            int left_child = 2 * parent + 1;
            if (left_child > end_index_of_heap) {
                left_child = -1;
            }
            int right_child = 2 * parent + 2;
            if (right_child > end_index_of_heap) {
                right_child = -1;
            }

            // if the index is the last one
            if (left_child == -1 && right_child == -1) {
                break;
            }

            // get the smaller from the two
            int smaller_one = 0; // the index of the smaller value from right and left children
            if (left_child == -1) { smaller_one = right_child; }
            else if (right_child == -1) { smaller_one = left_child; }
            else {
                if (heap[right_child] > heap[left_child]) {
                    smaller_one = left_child;
                } else {
                    smaller_one = right_child;
                }
            }
            
            // swap if parent is larger
            if (heap[parent] > heap[smaller_one]) {
                int temp = heap[smaller_one];
                heap[smaller_one] = heap[parent];
                heap[parent] = temp;
            }
            parent = smaller_one;
        }
    }
    free(heap);
}

void merge_sort(int* arr, int length) {

    int starting_n = 1;
    while (starting_n < length) {

        int ending_n = starting_n * 2;
        int freq = length / ending_n;
        if (length % ending_n > 0) { freq += 1; } // get the ceiling of the division
        for (int i = 0; i < freq; i++) {

            int index = i * ending_n; // the start index

            int first_start_index = index; // the first group
            int first_end_index = index + starting_n;
            int second_start_index = index + starting_n; // the second group
            int second_end_index = second_start_index + starting_n;

            // create a temporary array to store the result
            int size = ending_n;
            if (i == freq - 1) {
                size = length - (ending_n * i);
            }
            // printf("%d: %d\n", i, size);
            int* temp_array = (int *) malloc(sizeof(int) * size);
            for (int j = 0; j < size; j++) {

                if (first_start_index == first_end_index || first_start_index >= length) {
                    temp_array[j] = arr[second_start_index];
                    second_start_index += 1;
                }
                else if (second_start_index == second_end_index || second_start_index >= length) {
                    temp_array[j] = arr[first_start_index];
                    first_start_index += 1;
                }
                else {
                    if (arr[first_start_index] < arr[second_start_index]) {
                        temp_array[j] = arr[first_start_index];
                        first_start_index += 1;
                    }
                    else {
                        temp_array[j] = arr[second_start_index];
                        second_start_index += 1;
                    }
                }
            }
            // assign the values in the temp array to the original array
            int temp_index = index;
            for (int j = 0; j < size; j++) {
                arr[temp_index] = temp_array[j];
                temp_index += 1;
            }
            free(temp_array);

            // printf("%d:[ ", i);
            // for (int j = 0; j < size; j++) {
            //     printf("%d ", arr[index]);
            //     index += 1;
            // }
            // printf("] ");
        }
        // printf("\n");
        starting_n = ending_n;
    }
}