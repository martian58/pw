#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate a random unsorted array of length 15
void generateRandomArray(int arr[], int size) {
    // Seed the random number generator
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Generating random numbers between 0 and 99
    }
}

// Function to perform selection sort
void selection_sort(int arr[], int n) {
    int i, j, min_index;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // Swap the found minimum element with the first element
        swap(&arr[min_index], &arr[i]);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void array_sort() {
    int arr[15];
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    generateRandomArray(arr, size);

    printf("Random unsorted array: \n");
    printArray(arr, size);

    selection_sort(arr, size);

    printf("Sorted array: \n");
    printArray(arr, size);
}

int main() {
    array_sort();
    return 0;
}
