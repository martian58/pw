/*
 * File:   standard_deviation.h
 * Author: Fuad Alizada
 * Date:   April 08, 2024
 * Description: Functions to calculate Standard Deviation, Mean Value and more.
 */

#include <stdio.h>
#include <math.h>

#include "../../pws_lib/pw3/pw3.h"

// Predefined values of pi and acceleration (in m/s^2).
#define PI 3.14159265359
#define G 9.81
// Function to display the Standard Deviation Menu.
void show_standard_deviation_menu() {
    printf("\n\n");
    printf("%s************** STANDARD DEVIATION  MENU ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Period Finder (Therotical)\n");
    printf("2. Period Finder (Practical)\n");
    printf("3. Mean Value Finder (GOOD)\n");
    printf("4. Standard Deviation Finder (Excellent)\n");
    printf("5. Relative Difference\n");
    printf("%s7. Go back.%s\n",YELLOW, RESET);
    printf("%s8. Exit.\n",RED);
    printf("%s9. Clear screen%s",GREEN,RESET);
    printf("\n\n");
    printf("%sImportant*-> %sSource codes of these exercises are in 'src/standard_deviation' directory.%s",YELLOW,WHITE,RESET);
    printf("%s", RESET);
}

int period_theoretical() {
    double l; // Length of the pendulum.
    double period; // Period of the pendulum.

    // Prompt the user to enter the length of the pendulum.
    printf("%sEnter the length of the pendulum (in meters): ",WHITE);
    while (scanf("%lf", &l) != 1 || l <= 0) {
        printf("%sInvalid input for length. Please enter a positive number.%s\n",RED,RESET);
        while (getchar() != '\n'); // Clear input buffer
        printf("%sEnter the length of the pendulum (in meters): ",WHITE);
    }

    // Calculate the period using the formula T = 2*pi*sqrt(L/g).
    period = 2 * PI * sqrt(l / G);

    // Display the calculated period.
    printf("%sThe period of the pendulum is:%s %.8lf seconds\n%s",WHITE,GREEN, period,RESET);

    return 0;
}


int period_practical() {
    double total_time; // Total time for the given number of oscillations.
    int k; // Number of oscillations.

    // Prompt the user to enter the total time.
    while (1) {
        printf("%sEnter the total time (in seconds): ",WHITE);
        if (scanf("%lf", &total_time) != 1 || total_time <= 0) {
            printf("%sInvalid input for total time. Please enter a positive number.\n%s",RED,RESET);
            while (getchar() != '\n'); 
        } else {
            break; // Break out of the loop if input is valid.
        }
    }

    // Prompt the user to enter the number of oscillations.
    while (1) {
        printf("%sEnter the number of oscillations (k): ",WHITE);
        if (scanf("%d", &k) != 1 || k <= 0) {
            printf("%sInvalid input for number of oscillations. Please enter a positive integer.\n%s",RED,RESET);
            while (getchar() != '\n');
        } else {
            break; // Break out of the loop if input is valid.
        }
    }

    // Calculate the period.
    double period = total_time / k;

    // Display the calculated period.
    printf("%sThe period of the pendulum is:%s %.8lf seconds\n%s",WHITE,GREEN, period,RESET);

    return 0;
}

int mean_value() {
    int n; // Number of measurements.
    double sum = 0.0; // The sum of measurements.
    double mean; // Mean value.

    // Prompt the user to enter the number of measurements.
    printf("%sEnter the number of measurements (n): %s",WHITE,RESET);
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("%sInvalid input. Please enter a positive integer for the number of measurements.\n%s",RED,RESET);
        while (getchar() != '\n'); 
        printf("%sEnter the number of measurements (n): %s",WHITE,RESET);
    }

    // Prompt the user to enter the individual measurements and calculate their sum.
    for (int i = 1; i <= n; ++i) {
        double T; // Individual measurement.
        printf("%sEnter measurement T%d%s: ", WHITE,i,RESET);
        while (scanf("%lf", &T) != 1) {
            printf("%sInvalid input. Please enter a numeric value for measurement T%d: %s",RED, i,RESET);
            while (getchar() != '\n'); 
        }

        sum += T;
    }

    // Calculate the mean value.
    mean = sum / n;

    // Display the mean value.
    printf("%sMean value:%s %.8lf\n%s",WHITE,GREEN, mean,RESET);

    return 0;
}

int standard_deviation() {
    int n; // Number of measurements.
    double sum = 0.0; // The sum of measurements.
    double sum_squares = 0.0; // Sum of squared differences.
    double standard_deviation; // Standard deviation.

    // Prompt the user to enter the number of measurements.
    printf("%sEnter the number of measurements (n): %s",WHITE,RESET);
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("%sInvalid input. Please enter a positive integer for the number of measurements.\n%s",RED,RESET);
        while (getchar() != '\n'); 
        printf("%sEnter the number of measurements (n): %s",WHITE,RESET);
    }

    // Prompt the user to enter the individual measurements and calculate the sum of measurements.
    for (int i = 1; i <= n; ++i) {
        double T; // Individual measurement of period.
        printf("%sEnter measurement T%d: %s",WHITE, i,RESET);
        while (scanf("%lf", &T) != 1) {
            printf("%sInvalid input. Please enter a numeric value for measurement T%d: %s",RED, i,RESET);
            while (getchar() != '\n');
            printf("%sEnter measurement T%d: %s",WHITE, i,RESET);
        }

        sum += T;
        sum_squares += T * T; // Sum of squared differences.
    }

    // Calculate the mean value.
    double mean = sum / n;

    // Calculate the standard deviation.
    standard_deviation = sqrt((sum_squares - n * mean * mean) / (n - 1));

    // Display the standard deviation.
    printf("%sStandard deviation:%s %.8lf\n%s",WHITE,GREEN, standard_deviation,RESET);

    return 0;
}

int relative_difference() {
    double tabulated_value, found_value; // Variables to store tabulated and found values
    double relative_difference; // Variable to store the relative difference

    // Prompt the user to enter the tabulated value with input validation
    printf("%sEnter the tabulated value:%s ",WHITE,RESET);
    while (scanf("%lf", &tabulated_value) != 1) {
        printf("%sInvalid input. Please enter a numeric value for the tabulated value: %s",RED,RESET);
        while (getchar() != '\n'); // Clear input buffer
    }

    // Prompt the user to enter the found value with input validation
    printf("%sEnter the found value in experiment: %s",WHITE,RESET);
    while (scanf("%lf", &found_value) != 1) {
        printf("%sInvalid input. Please enter a numeric value for the found value: %s",RED,RESET);
        while (getchar() != '\n'); // Clear input buffer
    }

    // Calculate the relative difference
    relative_difference = fabs((found_value - tabulated_value) / tabulated_value) * 100;

    // Display the relative difference with at least 5 digits after the decimal point
    printf("%sThe relative difference is:%s %.5lf%%\n%s",WHITE,GREEN,relative_difference,RESET);

    return 0;
}