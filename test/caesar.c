#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * Encrypts the given text using the Caesar Cipher.
 * 
 * @param key The encryption key (an integer between 1 and 25).
 * @param text The text to encrypt (a string).
 * @return The encrypted text.
 */
char* caesarCipherEncrypt(int key, const char *text) {
    // Allocate memory for the encrypted text
    char *encrypted_text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    if (encrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; text[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (isupper(text[i])) {
            encrypted_text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(text[i])) {
            encrypted_text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        }
        // Keep non-alphabetic characters unchanged
        else {
            encrypted_text[i] = text[i];
        }
    }
    encrypted_text[strlen(text)] = '\0'; // Null-terminate the encrypted text

    return encrypted_text;
}

/**
 * Decrypts the given text using the Caesar Cipher.
 * 
 * @param key The decryption key (an integer between 1 and 25).
 * @param text The text to decrypt (a string).
 * @return The decrypted text.
 */
char* caesarCipherDecrypt(int key, const char *text) {
    // Allocate memory for the decrypted text
    char *decrypted_text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    if (decrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; text[i] != '\0'; i++) {
        // Decrypt uppercase letters
        if (isupper(text[i])) {
            decrypted_text[i] = ((text[i] - 'A' - key + 26) % 26) + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(text[i])) {
            decrypted_text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
        }
        // Keep non-alphabetic characters unchanged
        else {
            decrypted_text[i] = text[i];
        }
    }
    decrypted_text[strlen(text)] = '\0'; // Null-terminate the decrypted text

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

/**
 * Clears the input buffer.
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int key;
    int d_key;
    char text[1000]; // Increased buffer size for text input
    char choice;

    // Input key from the user with validation
    do {
        printf("Enter the key (an integer between 1 and 25): ");
        while (scanf("%d", &key) != 1 || !validateInput(key, 1, 25)) {
            printf("Invalid input. Please enter an integer between 1 and 25: ");
            clearInputBuffer();
        }
        clearInputBuffer(); // Clear buffer after successful input
    } while (false);

    // Input text from the user with validation
    do {
        printf("Enter the text to encrypt (max 1000 chars): ");
        scanf(" %[^\n]", text);
        clearInputBuffer(); // Clear buffer after text input
    } while (!validateText(text));

    // Encrypt the text using Caesar Cipher
    char *encrypted_text = caesarCipherEncrypt(key, text);

    // Print the encrypted text
    printf("Encrypted text: %s\n", encrypted_text);

    // Ask the user if they want to decrypt the message
    printf("Do you want to decrypt the message? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        // Input decryption key from the user with validation.
        do {
            printf("Enter the decryption key (an integer between 1 and 25): ");
            while (scanf("%d", &d_key) != 1 || !validateInput(key, 1, 25) && d_key !=key) {
                printf("Bruhh, you already forgot the key :(? Try agagin: ");
                clearInputBuffer();
            }
            clearInputBuffer(); // Clear buffer after successful input
        } while (false);
        // Decrypt the text using Caesar Cipher
        char *decrypted_text = caesarCipherDecrypt(key, encrypted_text);
        // Print the decrypted text
        printf("Decrypted text: %s\n", decrypted_text);
        free(decrypted_text);
    } else if (choice == 'n' || choice == 'N') {
        printf("Bye\n");
    } else {
        printf("Invalid choice. Bye.\n");
    }

    // Free allocated memory
    free(encrypted_text);

    return 0;
}
