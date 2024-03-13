/*
 * File:   pw1.h
 * Author: Fuad Alizada
 * Date:   March 05, 2024
 * Description: Corresponding functions for Practical Work 1 of CS2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../src/build.h"

// Function to show some fancy menu :)
void show_pw1_menu() {
    printf("\n\n");
    printf("%s************** PW 1  MENU ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Ex_1 (GCD Finder)\n");
    printf("2. Ex_2 (Quadratic eq. solver)\n");
    printf("3. Ex_3 (Absolute value finder)\n");
    printf("4. Ex_4 (Inch - centimeter convertor)\n");
    printf("%s5. Go back.%s\n",YELLOW, RESET);
    printf("%s6. Exit.\n",RED);
    printf("%s7. Clear screen%s",GREEN,RESET);
    printf("\n\n");
    printf("%sImportant*-> %sSource codes of these exercises are in 'pws_lib/pw1' directory.%s",YELLOW,WHITE,RESET);
    printf("%s", RESET);
}
//***************************************************************************************************************************************
//EX 1

// Function to calculate the GCD using Euclidean algorithm

int gcd(int a, int b) {
    // Base cases
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
// Main function for gcd
int main_gcd() {
    int a, b;
    int first_num_scanned;
    int second_num_scanned;

    // Input two positive integers from the user
    /*
        1. Make sure the user inputs only positive integers.
        2. Use another variable (e.g 'num_scanned') to check if the input is valid.
        3. If value is valid, then do the same for the second input.
            Created by: Fuad Alizada 
    */
    printf("%s(gcd) Enter the first positive integer: %s",WHITE, RESET);
    first_num_scanned = scanf("%d", &a);
    if (first_num_scanned != 1 || a <= 0) {
        printf("%s(gcd) Invalid input. Please enter a positive integer.%s\n",RED, RESET);
        return 1;
    }
    else{
        printf("%s(gcd) Enter the second positive integer: %s",WHITE,RESET);
        second_num_scanned = scanf("%d", &b);
            if (second_num_scanned != 1 || b <= 0) {
            printf("%s(gcd) Invalid input. Please enter a positive integer.%s\n",RED, RESET);
            return 1;
    }
}


    // Calculate and display the GCD
    int result = gcd(a, b);
    printf("%s", GREEN);
    printf("(gcd) The greatest common divisor of %d and %d is: %d\n", a, b, result);
    printf("%s", RESET);

    return 0;
}

//*****************************************************************************************************************************************
//EX 2

/*
    1. Quadratic equations can have 2, 1 or no real roots.
    2. User's input can be non-integer.
    3. Cases:
            1. No real root if discriminant is below zero.
            2. 2 identical roots (1 root) if discriminant is equal to zero.
            3. 2 different roots if discriminant is above zero.

        Created by: Fuad Alizada
*/

int quad() {
    float disc;//Discriminant
    float x1, x2;//roots
    float a, b, c;//Coefficients

    // Geting coefficients from the user
    printf("%s(quad) Enter coefficients 'a, b, c' (seperated by spaces): %s",WHITE, RESET);
    scanf("%f %f %f", &a, &b, &c);

    // Calculating the discriminant
    disc = b * b - 4 * a * c;

    if (disc > 0) {
        // If Equation has 2 real roots
        x1 = (-b + sqrt(disc)) / (2 * a);
        x2 = (-b - sqrt(disc)) / (2 * a);
        printf("%s",GREEN);
        printf("(quad) Two possible solutions:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
        printf("%s",RESET);
    } else if (disc == 0) {
        //If equation has one real root
        x1 = x2 = -b / (2 * a);
        printf("%s",GREEN);
        printf("(quad) Equation has 1 solution: x = %.2f\n", x1);
        printf("%s",RESET);
    } else {
        // If Equation has no real roots
        printf("%s(quad) Equation has no real solutions.%s\n",YELLOW, RESET);
    }
    //Return 0 if there was no errors
    return 0;
}
//**************************************************************************************************************************************
//EX 3

/*
    1. Write a sigle function to calculate the abs. difference of two numbers.
    2. Numbers can be non-integer.
    3. Do not use built-in abs() function.
        Created by: Fuad Alizada
*/


int abs_val() {
    double num1, num2;

    // Input two numbers from the user
    printf("%s(abs) Enter the first number: %s",WHITE,RESET);
    if (scanf("%lf", &num1) != 1) {
        printf("%s(abs) Invalid input. Please enter a valid number.%s\n",RED,RESET);

        return 1;
    }

    printf("%s(abs) Enter the second number: %s",WHITE,RESET);
    if (scanf("%lf", &num2) != 1) {
        printf("%s(abs) Invalid input. Please enter a valid number.%s\n",RED,RESET);

        return 1;
    }

    // Calculate the absolute difference
    /*
        Find the greatest number and substract the smaller one from it.
    */
    double absolute_difference = (num1 > num2) ? (num1 - num2) : (num2 - num1);
    printf("%s",GREEN);
    printf("(abs) The absolute difference between %.2f and %.2f is: %.2f\n", num1, num2, absolute_difference);
    printf("%s",RESET);
    return 0;
}

//*********************************************************************************************************************
//EX 4

/*
    1. 1 inch is 2.54 cm and 1 m is 100 cm.
    2. User must enter the amount and the unit as follows '<amount><unit>'
    3. Example: 2i, 45m, 12c
    4. program must convert the input and display it in cm and inches.
    5. Use switch-cases for efficiency.
        Created by: Fuad Alizada
*/

// Function for converting between units.
void convert_length(float length, char unit) {
    float centimeters, inches;

    switch(unit) {
        case 'i':
            centimeters = length * 2.54; // 1 inch = 2.54 cm.
            printf("%s",GREEN);
            printf("%.4f %c = %.4f cm\n", length, unit, centimeters);
            printf("%s",RESET);
            break;
        case 'm':
            centimeters = length * 100; // 1 meter = 100 cm.
            inches = centimeters / 2.54; // Convert centimeters to inches.
            printf("%s",GREEN);
            printf("%.4f %c = %.4f cm\n", length, unit, centimeters);
            printf("%.4f %c = %.4f i\n", length, unit, inches);
            printf("%s",RESET);
            break;
        case 'c':
            printf("%s",GREEN);
            inches= length/2.54;//Convert centimeters to inches.
            printf("%.4f %c = %.4f i\n", length, unit, inches);
            printf("%S",RESET);
            break;
        default:
            printf("%s(conv) Invalid unit. Please enter a valid unit--> %s(i, m, or c).%s\n",RED,BLUE,RESET);

    }
}
// Main Function of the convertor
int conv() {
    float length;
    char unit;

    // Scan the inputs from the user
    printf("%s(conv) Enter the length: %s",WHITE,RESET);
    scanf("%f%c", &length, &unit);
    //Check if input is in valid fromat.
    if (unit == 'i' || unit == 'm' || unit == 'c') {
        convert_length(length, unit);
    } else {
        // If input is in wrong format, then warn the user about this and show the correct version.
        printf("%s(conv) Invalid unit. Please enter a valid unit--> %s(i, m, or c).%s\n",RED,BLUE,RESET);

    }
    

    return 0;
    }
