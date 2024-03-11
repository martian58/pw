#include <stdio.h>
#define SIZE_MAX 100

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void calculate_statistics(int size, float arr[], float *avg, float *min, float *max) {
/*
 * Calculates the average, smallest, and largest values of a series of real values.
 * 
 * Parameters:
 *   size - The number of elements in the array.
 *   arr - The array containing the real values.
 *   avg - Pointer to store the calculated average.
 *   min - Pointer to store the smallest value.
 *   max - Pointer to store the largest value.
 * 
 * Returns:
 *   None
 */
    float sum = 0;
    *min = arr[0];
    *max = arr[0];

    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }

    *avg = sum / size;
}

int array_func() {
    int size;
    float arr[SIZE_MAX];
    float average, min, max;
    int num_valid;

    // Input validation loop for array size
    do {
        printf("Enter the size of the array (up to %d): ", SIZE_MAX);
        num_valid = scanf("%d", &size);
        clear_input_buffer();
        if (num_valid != 1 || size <= 0 || size > SIZE_MAX) {
            printf("Invalid size. Please enter a positive integer up to %d.\n", SIZE_MAX);
            continue;
        }
    } while (num_valid != 1 || size <= 0 || size > SIZE_MAX);

    // Input loop for array elements.
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        do {
            printf("Element %d: ", i + 1);
            num_valid = scanf("%f", &arr[i]);
            clear_input_buffer();
            if(num_valid !=1){
                printf("Invalid input. please enter real numbers!\n");
                continue;
            }
        } while(num_valid != 1);
    }

    // Calculate statistics.
    calculate_statistics(size, arr, &average, &min, &max);

    // Display results.
    printf("Average: %.2f\n", average);
    printf("Smallest value: %.2f\n", min);
    printf("Largest value: %.2f\n", max);

    return 0;
}

int main(){
    array_func();
    return 0;
}