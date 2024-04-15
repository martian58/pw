/*
 * File:   pw3.h
 * Author: Fuad Alizada
 * Date:   March 22, 2024
 * Description: Corresponding functions for Practical Work 3 of CS2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//Local libs
#include "../pw2/pw2.h"


// Function to show the mwnu of pw 3.
void show_pw3_menu() {
    printf("\n\n");
    printf("%s************** PW 3  MENU ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Ex_1 (Display elements of an array)\n");
    printf("2. Ex_2 (Selection Sort of arrays)\n");
    printf("3. Ex_3 (strlen, strcpy, strcmp, strcat, strncpy alternatives)\n");
    printf("4. Ex_4 (Imaginary Bank)\n");
    printf("5. Ex_5 (Encoders)\n");
    printf("%s7. Go back.%s\n",YELLOW,RESET);
    printf("%s8. Exit.%s\n",RED,RESET);
    printf("%s9. Clear screen%s",GREEN,RESET);
    printf("\n\n");
    printf("%sImportant*-> %sSource codes of these exercises are in 'pws_lib/pw3' directory.%s",YELLOW,WHITE,RESET);
    printf("%s", RESET);
}


//********************************************************************************************************************
// EX 1:
    /*
        Write a program to display a given array in the following format:

                        [12, 4, 56, 456, 45767]
    */

int print_arr(int arr[],int size){
        /* Function to print the array in a formatted manner.
         Parameters:
         - arr: The array to be printed.
         - size: The size of the array.
        */
        printf("%s\n(array) Here is your array: ",WHITE);
        printf("%s[",GREEN);
        if(size > 0){
            printf("%d",arr[0]);
            for(int i=1;i<size;i++){
                printf(", %d",arr[i]);
            }
        }
        printf("]%s\n",RESET);
}
// Function to input array elements from the user and display the array.
int display_array(){
    int size;
    int arr[20];
    int num_valid;

    // Input validation loop for array size.
    do {
        printf("%s(array) Enter the size of the array (up to 20): %s",WHITE,RESET);
        num_valid = scanf("%d", &size);
        clear_input_buffer();
        if (num_valid != 1 || size <= 0 || size > 20) {
            printf("%s(array) Invalid size. Please enter a positive integer up to 20.%s\n\n",RED,RESET);
            continue;
        }
    } while (num_valid != 1 || size <= 0 || size > 20);

    // Input loop for array elements.
    printf("%s\n(array) Enter the elements of the array:\n%s",BLUE,RESET);
    for (int i = 0; i < size; i++) {
        do {
            printf("%s(array) Element %d%s: ", WHITE,i + 1,RESET);
            num_valid = scanf("%d", &arr[i]);
            clear_input_buffer();
            if(num_valid !=1){
                printf("%s(array) Invalid input. Please enter integers!\n\n%s",RED,RESET);
                continue;
            }
        } while(num_valid != 1);
    }// Calling the function to print the array.
    print_arr(arr,size);
}


//******************************************************************************************************************************************
// EX 2
/*
    1. Write a program to sort integers using selection sort.

*/

// Function to swap two integers of array.
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate a random unsorted array of length 15.
void generateRandomArray(int arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Generating random numbers between 0 and 99.
    }
}

// Function to perform selection sort.
void selection_sort(int arr[], int n) {
    int i, j, min_index;

    // Every time move the boundary of the unsorted sub-array.
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in initial, unsorted array.
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // Swap the minimum element with the first element.
        swap(&arr[min_index], &arr[i]);
    }
}

// Function to print the arrays.
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void array_sort() {
    int arr[15];
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array.

    generateRandomArray(arr, size);

    printf("%s\n(array-sort) Random unsorted array: \n",BLUE);
    printf("%s",WHITE);
    printArray(arr, size); // Print the unsorted array.

    selection_sort(arr, size);

    printf("\n%s(array-sort) Sorted array: \n",BLUE);
    printf("%s",GREEN);
    printArray(arr, size);
    printf("%s",RESET);
}

//****************************************************************************************************************************
// EX 3

void show_pw3_ex3_menu() {
    printf("\n\n");
    printf("%s************** PW 3 EX 3 MENU ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Length of a string\n");
    printf("2. Initialize one string from another\n");
    printf("3. Initialize a string from the n first characters of another string\n");
    printf("4. Compare two character strings)\n");
    printf("5. Concatenate two character strings\n");
    printf("%s7. Go back.%s\n",YELLOW,RESET);
    printf("%s8. Exit.%s\n",RED,RESET);
    printf("%s9. Clear screen%s",GREEN,RESET);
    printf("\n\n");
    printf("%sImportant*-> %sSource codes of these exercises are in 'pws_lib/pw3' directory.%s",YELLOW,WHITE,RESET);
    printf("%s", RESET);
}

// Function to generate a random string of random length between 8 and 20.
char* generateRandomString() {
    const char* charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // Character set.

    int min_length = 8;
    int max_length = 20;

    int length = min_length + rand() % (max_length - min_length + 1); // Generate random length between 8 and 20.

    char* randomString = malloc((length + 1) * sizeof(char)); // Allocate memory for the string.
    if (randomString == NULL) {
        return NULL; // Memory allocation failed.
    }

    int charsetLength = strlen(charset);

    srand(time(NULL)); // Seed the random number generator.

    for (int i = 0; i < length; i++) {
        randomString[i] = charset[rand() % charsetLength]; // Pick a random character from the charset.
    }
    randomString[length] = '\0'; // Null-terminate the string.

    return randomString;
}

/// Part 1 ****************************
// strlen: This function is used to calculate the length of a string
// Function to get the length of a string.
/**
* @param str --> A string to find the length.
* @return len --> The length of the string.
*/
int length(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Fuction to display the result of length() function.
void lengthFind(){
    char* rnd_string = generateRandomString();
    int len = length(rnd_string);
    printf("%s(length) The string -> %s%s%s has a length of %s%i%s\n",WHITE,GREEN,rnd_string,WHITE,GREEN,len,RESET);
}

/// Part 2 *****************************************

// Function to initialize one string from another.
// strcpy: This function is used to copy the contents of one string to another

char* initializeString(char* dest, const char* src) {
    char* result = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Add null terminator to end the string.
    return result;
}

void print_initilized_string(){
    char* dest_string;
    char* random_string = generateRandomString();
    char* dest_string = initializeString(dest_string,random_string);
    printf("%sSource string--> %s %s%s\n",WHITE,GREEN,random_string,RESET);
    printf("%sDestination string --> %s %s%s\n",WHITE,GREEN,dest_string,RESET);
}


/// Part 3 *****************************************************

// Function to initialize a string from the (at most) n first characters of another string
void initializeStringN(char* dest, const char* src, int n) {
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0'; // Add null terminator to end the string
}

/// Part 4 *********************************************************

// Function to compare two character strings lexicographically
int compareStrings(const char* str1, const char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

/// Part 5 **************************************************

// Function to concatenate two character strings
void concatenateStrings(char* dest, const char* src) {
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Add null terminator to end the concatenated string
}

int deto() {
    // Example usage and testing
    char str1[20] = "hello";
    char str2[20] = "world";
    char str3[20] = "";

    printf("Length of 'hello': %d\n", length(str1));
    
    initializeString(str3, str1);
    printf("Initialized string: %s\n", str3);

    initializeStringN(str3, str2, 3);
    printf("Initialized string with first 3 characters of 'world': %s\n", str3);

    printf("Comparison result: %d\n", compareStrings(str1, str2));

    concatenateStrings(str1, str2);
    printf("Concatenated string: %s\n", str1);

    return 0;
}



//*******************************************************************************************************************************
// EX 5

void show_pw3_ex5_menu() {
    printf("\n\n");
    printf("%s************** PW 3 EX 5 MENU ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Encode with Caesar Cipher.\n");
    printf("2. Encode with base64\n");
    printf("3. Encode with base32\n");
    printf("4. Install Enc\n");
    printf("%s7. Go back.%s\n",YELLOW,RESET);
    printf("%s8. Exit.%s\n",RED,RESET);
    printf("%s9. Clear screen%s",GREEN,RESET);
    printf("\n\n");
    printf("%sImportant*-> %sDid you know that, You can encrypt your files and folders with my tool 'Enc' :) type 4 and hit enter to get it%s",YELLOW,WHITE,RESET);
    printf("%s", RESET);
}

// 

/**
 * Encrypts the given text using the Caesar Cipher.
 * 
 * @param key --> The encryption key (an integer between 1 and 25).
 * @param text --> The text to encrypt (a string).
 * @return The encrypted text.
 */
char* caesarCipherEncrypt(int key, const char *text) {
    // Allocate memory for the encrypted text.
    char *encrypted_text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    if (encrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; text[i] != '\0'; i++) {
        // Encrypt uppercase letters.
        if (isupper(text[i])) {
            encrypted_text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        }
        // Encrypt lowercase letters.
        else if (islower(text[i])) {
            encrypted_text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        }
        // Keep non-alphabetic characters unchanged.
        else {
            encrypted_text[i] = text[i];
        }
    }
    encrypted_text[strlen(text)] = '\0'; // Null-terminate the encrypted text.

    return encrypted_text;
}

/**
 * Decrypts the given text using the Caesar Cipher.
 * 
 * @param key --> The decryption key (an integer between 1 and 25).
 * @param text --> The text to decrypt (a string).
 * @return decrypted_text --> The decrypted text.
 */
char* caesarCipherDecrypt(int key, const char *text) {
    // Allocate memory for the decrypted text.
    char *decrypted_text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    if (decrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; text[i] != '\0'; i++) {
        // Decrypt uppercase letters.
        if (isupper(text[i])) {
            decrypted_text[i] = ((text[i] - 'A' - key + 26) % 26) + 'A';
        }
        // Decrypt lowercase letters.
        else if (islower(text[i])) {
            decrypted_text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
        }
        // Keep non-alphabetic characters unchanged.
        else {
            decrypted_text[i] = text[i];
        }
    }
    decrypted_text[strlen(text)] = '\0'; // Null-terminate the decrypted text.

    return decrypted_text;
}

/**
 * Validates the input to ensure it's a positive integer within the specified range.
 * 
 * @param input The input to validate.
 * @param min The minimum value allowed.
 * @param max The maximum value allowed.
 * @return true if the input is valid, false otherwise.
 */
bool validateInput(int input, int min, int max) {
    return input >= min && input <= max;
}

/**
 * Validates the input text to ensure it's not empty.
 * 
 * @param text The input text to validate.
 * @return true if the input text is not empty, false otherwise.
 */
bool validateText(const char *text) {
    return strlen(text) > 0;
}

void printSlowly(const char *text) {
    while (*text != '\0') {
        putchar(*text);
        fflush(stdout); 
        usleep(10000);  
        text++;
        }
}


int caesar() {
    const char *introText = "Hail, traveler, and welcome to the halls of Caesar's Cipher!\n\n"
    "I, Caesar, ruler of Rome, bring forth to you this tool of encryption and decryption known as the Caesar Cipher. Within these digital scrolls, you shall find the power to encode your messages with the strength of the Roman legions.\n\n";
    printSlowly(introText);
    int key;
    int d_key;
    char text[1000]; // Increased buffer size for text input.
    char choice;

     // Input validation is the key!.
    // Input key from the user with validation!.
    do {
        printf("%sEnter the key (an integer between 1 and 25): %s",WHITE,RESET);
        while (scanf("%d", &key) != 1 || !validateInput(key, 1, 25)) {
            printf("%s\nInvalid input--> %sPlease enter an integer between 1 and 25: %s",RED,WHITE,RESET);
            clear_input_buffer();
        }
        clear_input_buffer();
    } while (false);

    // Input text from the user with validation!.
    do {
        printf("%sEnter the text to encrypt (max 1000 chars): %s",WHITE,RESET);
        scanf(" %[^\n]", text);
        clear_input_buffer(); // Clear buffer after text input.
    } while (!validateText(text));

    // Encrypt the text using Caesar Cipher.
    char *encrypted_text = caesarCipherEncrypt(key, text);

    // Print the encrypted text.
    printf("%s\nEncrypted text:%s %s\n%s",WHITE,GREEN,encrypted_text,RESET);

    // Ask the user if they want to decrypt the message.
    printf("%sDo you want to decrypt the message? (y/n): %s",WHITE,RESET);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        // Input decryption key from the user with validation!.
        do {
            printf("%sEnter the decryption key (an integer between 1 and 25): %s",WHITE,RESET);
            while (scanf("%d", &d_key) != 1 || !validateInput(d_key, 1, 25) || d_key != key) {
                printf("%sBruhh, %syou already forgot the key :(? %sTry again: %s",RED,YELLOW,BLUE);
                clear_input_buffer();
            }
            clear_input_buffer();
        } while (false);
        // Decrypt the text using Ceasar Cipher.
        char *decrypted_text = caesarCipherDecrypt(key, encrypted_text);
        // Print the decrypted text.
        printf("\n%sDecrypted text:%s %s\n%s",WHITE,GREEN,decrypted_text,RESET);
        free(decrypted_text);
    } else if (choice == 'n' || choice == 'N') {
        printf("%sBye%s\n",BLUE,RESET);
    } else {
        printf("\n%sInvalid choice. Bye.%s\n",RED,RESET);
    }

    // Free the  allocated memory for the encrypted text.
    free(encrypted_text);

    return 0;
}
