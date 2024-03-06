#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../src/constants.h"

// Function to show the main menu
void show_pw1_menu() {
    printf("\n\n");
    printf("%s%s%s",GREEN,"************** PW 1  MENU ****************",RESET);
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Ex_1 (GCD Finder)\n");
    printf("2. Ex_2 (Quadratic eq. solver)\n");
    printf("3. Ex_3 (Absolute value finder)\n");
    printf("4. Ex_4 (Inch - centimeter convertor)\n");
    printf("%s%s%s",YELLOW,"5. Go back.\n",RESET);
    printf("%s%s",RED,"6. Exit.\n");
    printf("%s%s%s",GREEN,"7. Clear screen",RESET);
    printf("\n\n");
    printf("%s%s%s%s%s",YELLOW,"Important*->",RESET,WHITE,"Source codes of these exercises are in 'pws_lib/pw1' directory.");
    printf("%s", RESET);
}

//EX 1

// Function to calculate the GCD using Euclidean algorithm

int gcd(int a, int b) {
    // Base cases
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main_gcd() {
    int a, b;
    int first_num_scanned;
    int second_num_scanned;

    // Input two positive integers from the user
    printf("%s%s%s",WHITE,"(gcd) Enter the first positive integer: ", RESET);
    first_num_scanned = scanf("%d", &a);
    if (first_num_scanned != 1 || a <= 0) {
        printf("%s%s%s", RED, "(gcd) Invalid input. Please enter a positive integer.\n", RESET);
        return 1;
    }
    else{
        printf("%s%s%s",WHITE,"(gcd) Enter the second positive integer: ", RESET);
        second_num_scanned = scanf("%d", &b);
            if (second_num_scanned != 1 || b <= 0) {
            printf("%s%s%s", RED, "(gcd) Invalid input. Please enter a positive integer.\n", RESET);
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


//EX 2


int quad() {
    float disc;//Discriminant
    float x1, x2;//roots
    float a, b, c;//Coefficients

    // Geting coefficients from the user
    printf("%s%s%s",WHITE,"(quad) Enter coefficients 'a, b, c' of the quadratic equation:",RESET);
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
        printf("%s%s%s",YELLOW,"(quad) Equation has no real solutions\n",RESET);
    }
    //Return 0 if there was no errors
    return 0;
}

//EX 3

int abs_val() {
    double num1, num2;

    // Input two numbers from the user
    printf("%s%s%s",WHITE,"(abs) Enter the first number: ",RESET);
    if (scanf("%lf", &num1) != 1) {
        printf("%s%s%s",RED,"(abs) Invalid input. Please enter a valid number.\n",RESET);

        return 1;
    }

    printf("%s%s%s",WHITE,"(abs) Enter the second number: ",RESET);
    if (scanf("%lf", &num2) != 1) {
        printf("%s%s%s",RED,"(abs) Invalid input. Please enter a valid number.\n",RESET);

        return 1;
    }

    // Calculate the absolute difference
    double absolute_difference = (num1 > num2) ? (num1 - num2) : (num2 - num1);
    printf("%s",GREEN);
    printf("(abs) The absolute difference between %.2f and %.2f is: %.2f\n", num1, num2, absolute_difference);
    printf("%s",RESET);
    return 0;
}


//EX 4
void convert_length(float length, char unit) {
    float centimeters, inches;

    switch(unit) {
        case 'i':
            centimeters = length * 2.54; // 1 inch = 2.54 cm
            printf("%.4f %c = %.4f cm\n", length, unit, centimeters);
            break;
        case 'm':
            centimeters = length * 100; // 1 meter = 100 cm
            inches = centimeters / 2.54; // Convert centimeters to inches
            printf("%.4f %c = %.4f cm\n", length, unit, centimeters);
            printf("%.4f %c = %.4f i\n", length, unit, inches);
            break;
        case 'c':
            inches= length/2.54;
            printf("%.4f %c = %.4f i\n", length, unit, inches);
            break;
        default:
            printf("%s%s%s%s",RED,"(conv) Invalid unit. Please enter a valid unit-->",BLUE,"(i, m, or c).\n",RESET);

    }
}

int conv() {
    float length;
    char unit;

    
    printf("%s%s%s",WHITE,"(conv) Enter the length: ",RESET);
    scanf("%f%c", &length, &unit);
    if (unit == 'i' || unit == 'm' || unit == 'c') {
        convert_length(length, unit);
    } else {
        printf("%s%s%s%s",RED,"(conv) Invalid unit. Please enter a valid unit-->",BLUE,"(i, m, or c).\n",RESET);
    }
    

    return 0;
    }
