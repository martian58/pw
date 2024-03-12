/*
 * File:   pw2.h
 * Author: Fuad Alizada
 * Date:   March 12, 2024
 * Description: Corresponding functions for Practical Work 2 of CS2.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


//Local libs
#include "../pw1/pw1.h"

// Function to show some fancy menu :)
void show_pw2_menu() {
    printf("\n\n");
    printf("%s%s%s",GREEN,"************** PW 2  MENU ****************",RESET);
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Ex_1 (Power finder)\n");
    printf("2. Ex_2 (Prime checker)\n");
    printf("3. Ex_3 (Days in a month)\n");
    printf("4. Ex_4 (Imaginary Bank)\n");
    printf("5. Ex_5 (Inch - centimeter convertor --> uptaded version for pw2.)\n");
    printf("6. Ex_6 (Array manipulation)\n");
    printf("%s%s%s",YELLOW,"7. Go back.\n",RESET);
    printf("%s%s",RED,"8. Exit.\n");
    printf("%s%s%s",GREEN,"9. Clear screen",RESET);
    printf("\n\n");
    printf("%s%s%s%s%s",YELLOW,"Important*->",RESET,WHITE,"Source codes of these exercises are in 'pws_lib/pw2' directory.");
    printf("%s", RESET);
}

//***************************************************************************************************************************

/*EX 1

    1. Calculate and display the integer power of a real.
    2. Do not use built in functions! (or you will get arrested!)
    3. Base can be non-integer, but exponent must be an integer.
    4. If the exponent is negative, invert the base and the exponent.
*/

// Function to calculate power.
double power_calc(double base, int exponent) {
    double result = 1.0;

    // If the exponent is negative, invert the base and exponent.
    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }

    // Multiply base with itself 'exponent' times.
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

// Function to input and calculate power.
void power() {
    double base;
    int exponent; // exponent must be an integer.

    // Input base from the user.
    printf("%s%s%s",WHITE,"(power) Enter the base: ", RESET);
    // It's better to use do-while loop here but i used both in different exercises not to get bored.
    while (scanf("%lf", &base) != 1) {
        printf("%s%s%s", RED, "(power) Invalid input. Please enter a number: ", RESET);
        while (getchar() != '\n'); // Clear input buffer.
    }

    // Input exponent from the user.
    printf("%s%s%s",WHITE,"(power) Enter the exponent: ", RESET);
    while (scanf("%d", &exponent) != 1) {
        printf("%s%s%s", RED, "(power) Invalid input. Please enter an integer: ", RESET);
        while (getchar() != '\n'); // Clear input buffer.
    }

    // Calculate and display the power.
    printf("%s\n(power) Answer is:%s %lf\n%s",WHITE,GREEN,power_calc(base, exponent),RESET);

}


//*********************************************************************************************************

/*
EX 2

    1. Write a program that checks if a number entered by the user is a prime number or not.
    2. 0 and 1 are not prime numbers.
    3. Use "Trial Division" algorithm for this task.
        exp:
            Take the number, start deviding it to all numbers between 2 and the square root of input nummber.
            Use 'for' loop for that.
    4. Validate user input, it can only be non-negative integers.
*/

// Function to check if a number is prime
bool isPrime(int num) {
    // 0 and 1 are not prime numbers.
    if (num <= 1) {
        return false;
    }
    // Check for divisibility from 2 to the square root of num.
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Get user input, validate and check if the input number is a prime.
int is_prime() {
    int number;

    // Input the number from the user with validation
    printf("%s%s%s",WHITE,"(prime_checker) Enter an integer number: ",RESET);
    while (scanf("%d", &number) != 1 || number < 0) {
        printf("%s%s%s",RED,"(prime_checker) Invalid input. Please enter a non-negative integer: ",RESET);
        while (getchar() != '\n'); 
    }

    // Check if the number is prime and display the result.
    if (isPrime(number)) {
        printf("%s(prime_checker) %d is a prime number.\n",GREEN,number);
    } else {
        printf("%s(prime_checker) %d is not a prime number%s.\n",YELLOW,number,RESET);
    }

    return 0;
}

//******************************************************************************************************************************************

/*
EX 3

    1. Consider Leap years.
    2. Inputs must be validated.

*/

// Function to check if a year is a leap year.
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

// Function to get the number of days in a month.
int getDaysInMonth(int month, int year) {

    /*   Array to store the number of days in each month.
         We can add 'isLeapYear()' function's return value, it is either 1 or 0.
    */
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Return the number of days in the given month.
    return daysInMonth[month - 1];
}

// Function to get the name of the month.
const char* getMonthName(int month) {
    // Array to store the names of the months.
    const char* monthNames[] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};

    // Check if the month is valid.
    if (month < 1 || month > 12) {
        return "Invalid Month";
    }

    // Return the name of the month.
    return monthNames[month - 1];
}

int days_in_month() {
    int month, year;
    
    // Input the month and year from the user with validation.
    printf("%s%s%s",WHITE,"(days_in_month) Enter the month number: ",RESET);
    while (scanf("%d", &month) != 1 || month < 1 || month > 12) {
        printf("%s%s%s",RED,"(days_in_month) Invalid input. Please enter a number between 1 and 12: ",RESET);
        while (getchar() != '\n'); 
    }
    // Check if the year really exist. 
    printf("%s%s%s",WHITE,"(days_in_month) Enter the year: ",RESET);
    while (scanf("%d", &year) != 1 || year <= 0) {
        printf("%s%s%s",RED,"(days_in_month) Invalid input. Please enter an exixting year!: ",RESET);
        while (getchar() != '\n'); 
    }

    // Get the number of days in the month.
    int daysInMonth = getDaysInMonth(month, year);
    
    // Display the number of days and the name of the month.
    if (daysInMonth != -1) {
        printf(GREEN);
        printf("(days_in_month) Number of days in %s %d is %d\n", getMonthName(month), year, daysInMonth);
        printf(RESET);
    }
    
    return 0;
}


//************************************************************************************************************************************************

/*
EX 4

    1. Initial capital, Interest rate must be float, But Investment period is always positive integer.
    2. Make sure to validate user input, Write a function to clear the buffer after invalid inputs.
    3. Our imaginary bank also shows in how many years the client's money would double, so write a function that does it.

*/


void calculate_interest(float initial_capital, float interest_rate, int investment_period) {
/* Calculates the interest earned over multiple years.
 * Parameters:
 *   initial_capital - the initial amount of money
 *   interest_rate - the annual interest rate (in decimal)
 *   investment_period - the number of years for the investment
 * Returns:
 *   None
 */
    float capital = initial_capital;
    for (int year = 1; year <= investment_period; year++) {
        float interest = capital * interest_rate;
        capital += interest;
        printf("On year %d, capital: %s%.2f%s, interest earned: %s%.2f%s\n", year, GREEN, capital, RESET, GREEN, interest, RESET);
    }
}

int years_to_double(float initial_capital, float interest_rate) {
    /*
 * Calculates the number of years required for an investment to double based on the given initial capital and interest rate.
 * 
 * Parameters:
 *   initial_capital - The initial amount of money invested.
 *   interest_rate - The annual interest rate (expressed as a decimal) for the investment.
 * 
 * Returns:
 *   An integer representing the number of years required for the investment to double.
 */
    float capital = initial_capital;
    int years = 0;
    while (capital < initial_capital * 2) {
        float interest = capital * interest_rate;
        capital += interest;
        years++;// Increment the years.
    }
    return years;
}

int bank() {
    float initial_capital, interest_rate;
    int investment_period;
    int num_items; // Use this variable for validation.

    // Input validation loop.
    do {
        //get input from the user.
        printf("%s(bank) Enter the initial capital (should be positive): %s", WHITE, RESET);
        num_items = scanf("%f", &initial_capital);
        clear_input_buffer();//clear buffer
        // Checking the condition for initial capital using if statement.
        if(num_items != 1 || initial_capital <= 0){
            printf("%s%s%s", RED, "(bank) Invalid input!\n", RESET);
        }
    } while (num_items != 1 || initial_capital <= 0);

    do {
        //same stuff here, just validation.
        printf("%s(bank) Enter the interest rate (in decimal, should be between 0 and 1): %s", WHITE, RESET);
        num_items = scanf("%f", &interest_rate);
        clear_input_buffer();
        if(num_items != 1 || interest_rate >=1 || interest_rate <= 0){
            printf("%s%s%s", RED, "(bank) Invalid input!\n", RESET);
        }
    } while (num_items != 1 || interest_rate <= 0 || interest_rate >= 1);

    do {
        //same here too.
        printf("%s(bank) Enter the investment period (should be a positive integer): %s", WHITE, RESET);
        num_items = scanf("%d", &investment_period);
        clear_input_buffer();
        if(num_items != 1 || investment_period <= 0){
            printf("%s%s%s", RED, "(bank) Invalid input!\n", RESET);
        }
    } while (num_items != 1 || investment_period <= 0);

    // Finally Print the values for the user.
    // Dont mind my comments :)
    printf("\n%sEvolution of capital:%s\n",BLUE,RESET);
    calculate_interest(initial_capital, interest_rate, investment_period);

    int doubling_years = years_to_double(initial_capital, interest_rate);
    printf("\n(bank) It takes %s%d%s years to double the initial capital.\n", GREEN, doubling_years, RESET);

    return 0;
} 


//**************************************************************************************************************************************************

// EX 5

/*
    1. 1 inch is 2.54 cm and 1 m is 100 cm.
    2. User must enter the amount and the unit as follows '<amount><unit>'. Update: amount and unit can have spaces between them. 
    3. Example: 2i, 45m, 12c. Update: Units can be uppercase.
    4. program must convert the input and display it in cm and inches.
    5. Use switch-cases for efficiency.
    6. Update: After calculation user is asked if they want to convert again.
        Created by: Fuad Alizada
*/




// Function for converting between units.
void convert_length2(float length, char unit) {
    /*
 * Converts a length from one unit to another and displays the result.
 * Supports conversion between inches (i), meters (m), and centimeters (c).
 * 
 * Parameters:
 *   length - The value of the length to be converted.
 *   unit - The unit of the length ('i' for inches, 'm' for meters, 'c' for centimeters).
 * 
 * Returns:
 *   None
 */
    float centimeters, inches;

    switch(tolower(unit)) { // Convert unit to lowercase.
        case 'i':
            centimeters = length * 2.54; // 1 inch = 2.54 cm.
            printf(GREEN);
            printf("%.4f %c = %.4f cm\n\n", length, unit, centimeters);
            printf(RESET);
            break;
        case 'm':
            centimeters = length * 100; // 1 meter = 100 cm.
            inches = centimeters / 2.54; // Convert centimeters to inches.
            printf(GREEN);
            printf("%.4f %c = %.4f cm\n", length, unit, centimeters);
            printf("%.4f %c = %.4f i\n\n", length, unit, inches);
            printf(RESET);
            break;
        case 'c':
            printf(GREEN);
            inches= length/2.54;//Convert centimeters to inches.
            printf("%.4f %c = %.4f i\n\n", length, unit, inches);
            printf(RESET);
            break;
        default:
            printf("%s%s%s%s",RED,"(conv2) Invalid unit. Please enter a valid unit-->",BLUE,"(i, m, or c).\n",RESET);
    }
}

// Main Function of the convertor.
int conv2() {
    float length;
    char unit;
    int num_valid;

    char again; // Variable to store user input for repeat.

    do {
        // Scan the inputs from the user.
        printf("%s%s%s",WHITE,"(conv2) Enter the length: ",RESET);
        num_valid = scanf("%f %c", &length, &unit); // Allow blanks between value and unit.

        //Check if input is in valid format.
        if ( num_valid != 0 && (tolower(unit) == 'i' || tolower(unit) == 'm' || tolower(unit) == 'c')) {
            convert_length2(length, unit);
        } else {
            // If input is in wrong format, then warn the user about this and show the correct version.
            printf("%s%s%s%s",RED,"(conv2) Invalid unit. Please enter a valid unit-->",BLUE,"(i, m, or c).\n",RESET);
        }

        // Ask user if they want to start over? .

        /*
            Exit the program if and only of the user inputs 'n' or 'N'.
            if input is anything different than 'n' or 'N' the continue to running the code.
        */
        printf("%s%s%s",WHITE, "(conv2) Do you want to convert another length? (y/N): ", RESET);
        scanf(" %c", &again); 
        if (tolower(again) =='y'){
            continue;
        }else if(tolower(again)=='n'){
            printf("%s%s",RED,"Exiting...\n\n",RESET);
            break;
        }else{
            printf("%s%s%s",RED,"(conv2) Invalid input. Continuing the convention...\n\n",RESET);
            continue;
        }

    } while (tolower(again) != 'n'); // Repeat if user input is 'y' or 'Y'.

    return 0;
}

//***************************************************************************************************************************************************

//EX 6

/*
    1.
    2. Define a SIZE_MAX variable to prevent buffer-overflow.

*/

#define SIZE_MAX 100

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

    // Input validation loop for array size.
    do {
        printf("%s(array) Enter the size of the array (up to %d): %s",WHITE, SIZE_MAX,RESET);
        num_valid = scanf("%d", &size);
        clear_input_buffer();
        if (num_valid != 1 || size <= 0 || size > SIZE_MAX) {
            printf("%s(array) Invalid size. Please enter a positive integer up to %d.%s\n\n",RED,SIZE_MAX,RESET);
            continue;
        }
    } while (num_valid != 1 || size <= 0 || size > SIZE_MAX);

    // Input loop for array elements.
    printf("%s\n(array) Enter the elements of the array:\n%s",BLUE,RESET);
    for (int i = 0; i < size; i++) {
        do {
            printf("%s(array) Element %d%s: ", WHITE,i + 1,RESET);
            num_valid = scanf("%f", &arr[i]);
            clear_input_buffer();
            if(num_valid !=1){
                printf("%s(array) Invalid input. Please enter real numbers!\n\n%s",RED,RESET);
                continue;
            }
        } while(num_valid != 1);
    }

    // Calculate statistics.
    calculate_statistics(size, arr, &average, &min, &max);

    // Display results.
    printf("\n\n%sAverage: %s%.2f\n%s",WHITE,GREEN,average,RESET);
    printf("%sSmallest value: %s%.2f\n%s",WHITE,GREEN, min,RESET);
    printf("%sLargest value: %s%.2f\n%s",WHITE,GREEN,max,RESET);

    return 0;
}
