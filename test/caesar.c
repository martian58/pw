#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
char* caesarCipherEncrypt(int key, const char *text) {
    char *encrypted_text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    if (encrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            encrypted_text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        }
        else if (islower(text[i])) {
            encrypted_text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        }
        else {
            encrypted_text[i] = text[i];
        }
    }
    encrypted_text[strlen(text)] = '\0'; 

    return encrypted_text;
}

char* caesarCipherDecrypt(int key, const char *text) {
    char *decrypted_text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    if (decrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            decrypted_text[i] = ((text[i] - 'A' - key + 26) % 26) + 'A';
        }
        else if (islower(text[i])) {
            decrypted_text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
        }
        else {
            decrypted_text[i] = text[i];
        }
    }
    decrypted_text[strlen(text)] = '\0';

    return decrypted_text;
}

bool validateInput(int input, int min, int max) {
    return input >= min && input <= max;
}

bool validateText(const char *text) {
    return strlen(text) > 0;
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int key;
    int d_key;
    char text[1000]; 
    char choice;

    do {
        printf("Enter the key (an integer between 1 and 25): ");
        while (scanf("%d", &key) != 1 || !validateInput(key, 1, 25)) {
            printf("Invalid input. Please enter an integer between 1 and 25: ");
            clearInputBuffer();
        }
        clearInputBuffer(); 
    } while (false);
    do {
        printf("Enter the text to encrypt (max 1000 chars): ");
        scanf(" %[^\n]", text);
        clearInputBuffer(); 
    } while (!validateText(text));

    char *encrypted_text = caesarCipherEncrypt(key, text);

 
    printf("Encrypted text: %s\n", encrypted_text);

    printf("Do you want to decrypt the message? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        do {
            printf("Enter the decryption key (an integer between 1 and 25): ");
            while (scanf("%d", &d_key) != 1 || !validateInput(key, 1, 25) && d_key !=key) {
                printf("Bruhh, you already forgot the key :(? Try agagin: ");
                clearInputBuffer();
            }
        } while (false);
        char *decrypted_text = caesarCipherDecrypt(key, encrypted_text);
        printf("Decrypted text: %s\n", decrypted_text);
        free(decrypted_text);
    } else if (choice == 'n' || choice == 'N') {
        printf("Bye\n");
    } else {
        printf("Invalid choice. Bye.\n");
    }

    free(encrypted_text);

    return 0;
}
