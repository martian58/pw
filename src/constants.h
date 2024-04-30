#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>


/*
    **Functions in this library**:

    1. show_main_menu();
    2. exit_program();
    3. clear_input_buffer();
    4. get_int_input();
    5. get_char_input();
    6. print_colored_line();
    7. print_padded_line();
    8. generate_random_char();
    9. intro();
    10. detect_os();
    11. command_executer();
    12. windows_os_detected();

    **Variables in this library**:

    1. RED
    2. GREEN
    3. YELLOW
    4. WHITE
    5. PINK
    6. BLUE
    7. RESET
    8. VERSION
*/



// Ascii codes for colors as a string.
char *RED = "\033[1;31m"; 
char *GREEN = "\033[1;32m"; 
char *YELLOW = "\033[1;33m"; 
char *WHITE = "\033[1;37m"; 
char *PINK = "\033[1;35m"; 
char *BLUE = "\033[1;34m"; 
char *RESET = "\033[0m";


//Version information.
char *VERSION="1.4.9";

// Function to show the fancy main menu :).
void show_main_menu() {
    printf("\n\n");
    printf("%s************** PWS MENU ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s1. PW_1 (Available)\n",BLUE);
    printf("2. PW_2 (Available)\n");
    printf("3. PW_3 (Available)\n");
    printf("4. PW_4 (Available)\n");
    printf("%s5. PW_5 (new)%s\n",GREEN,RESET);
    printf("%s", WHITE);
    printf("6. PW_6 (Coming soon)\n");
    printf("7. PW_7 (Coming soon)\n");
    printf("%s8. Go back%s\n",YELLOW,RESET);
    printf("%s9. Exit%s\n",RED,RESET);
    printf("\n");
    printf("%s************** FUN STUFF ***************\n",GREEN);
    printf("\n");
    printf("%s10. Terminal Art%s",BLUE,RESET);
    printf("\n\n");
    printf("%s*********** SOME USEFUL STUFF **********\n\n",GREEN);
    printf("%s15. Standard deviation stuff%s",BLUE,RESET);
    printf("%s", RESET);
}
void terminal_art_menu() {
    printf("\n\n");
    printf("%s************** Terminal Art ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s1. Rick The Dancer%s\n",BLUE,RESET);
    printf("%s2. Parrot%s\n",YELLOW,RESET);
    printf("%s", WHITE);
    printf("3. Donut\n");
    printf("%s4. Mr Robot\n",PINK);
    printf("%s7. Go back%s\n",YELLOW,RESET);
    printf("%s8. Exit%s\n",RED,RESET);
    printf("%s9. Clear screen%s\n",GREEN,RESET);
    printf("%s", RESET);
}
// Function to exit the program.
void exit_program(){
    printf("%sExiting....\n",YELLOW);
    usleep(1000000);
    printf("%sHave a good day!\n",GREEN);
    usleep(2000000);
    system("clear");
    exit(0);
}

//Function to clear the buffer after invalid inputs.
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to get an integer input from the user.
int get_int_input() {
    printf("\n\n");
    int input;
    int success;  // Variable to hold the return value of scanf.

    do {
        printf("%sEnter the number of the option you choose.%s\n",GREEN,RESET);
        printf("%spw--> %s",PINK,RESET);
        success = scanf("%d", &input);

        // Clear the input buffer in case of invalid input.
        while (getchar() != '\n');

        if (success != 1) {
            printf("%sInvalid option!%s\n\n",RED,RESET);

        }
    } while (success != 1);

    return input;
}

// Function to get a character input from the user.
// Make sure there is space before '%c'.
char get_char_input() {
    printf("\n\n");
    char input;
    printf("%sEnter the number of the option you choose.%s\n",GREEN,RESET);
    printf("%spw--> %s",PINK,RESET);
    scanf(" %c", &input); //the space before %c to consume whitespace.
    return input;
}

// Function to print a line with color transitions.
void print_colored_line(const char *line, const char *foreground_color, const char *background_color) {
    printf("\033[%s;%sm%s\033[0m\n", foreground_color, background_color, line);
}


// Function to print a line with padding from top and left.
void print_padded_line(const char *text, int padding_top, int padding_left) {
    for (int i = 0; i < padding_top; i++) {
        printf("\n");
    }
    printf("%*s%s\n", padding_left, "", text);
}

// Function to generate a random character.
char generate_random_char() {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int len = strlen(chars);
    return chars[rand() % len];
}

// PW1 ASCII art with color transition and padding.
void intro() {
    // Clear the screen.
    printf("\033c");

    // Define color codes.
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines.
    const char *lines[] = {
        "      @@@@@@@@@   @@                    @@       @@  ",
        "      @@     @@    @@        @@        @@        @@  ",
        "      @@     @@     @@      @@@@      @@         @@   ",
        "      @@@@@@@@@      @@    @@  @@    @@          @@   ",
        "      @@              @@  @@    @@  @@           @@   ",
        "      @@               @@@@      @@@@                 ",
        "      @@                @@        @@             @@   "
    };

    // Print each line with color transition and a random character.
    printf("\n\n");
    for (int i = 0; i < 7; i++) {
        char line_copy[strlen(lines[i]) + 1];
        strcpy(line_copy, lines[i]);
        char rnd_char = generate_random_char();
        for (int j = 0; line_copy[j] != '\0'; j++) {
            if (line_copy[j] == '@') {
                line_copy[j] = rnd_char;
            }
        }
        print_colored_line(line_copy, colors[i % 5], colors[(i + 1) % 5]);
        usleep(200000); // Sleep for 0.2 seconds.
    }

    printf("\n\n");

    // Welcome message,Author and GitHub reference.
    printf("\033[1;36m");
    printf("Welcome to PW \n");
    printf("\033[0m");
    printf("%sVersion: %s\n",PINK,VERSION);
    printf("\033[1;33m");
    printf("Created by: Fuad Alizada\n");
    printf("GitHub: https://github.com/martian58\n");
    printf("\033[0m");
    printf("\033[1;33m");
    usleep(300000);
    printf("\033[0m");
    printf("\n");
    printf("%s", BLUE);
    printf("This program includes all the tasks of the Practical works.\n");
    printf("Continue to the pws menu to explore them. Source codes are in 'pws_lib' directory.\n");
    printf("\n\n");
    printf("1. Continue \n");
    printf("%s2. Exit%s \n",RED,RESET);
    printf("%s3. Visit my github :)%s \n",GREEN,RESET);
}


// Os detection.
int detect_os() {
    // Check Windows.
    #ifdef _WIN32
        return 1;
    // Check  macOS.
    #elif defined(__APPLE__)
        return 2;
    #else
        // Check Unix-like system.
        return 0;
    #endif
}

void windows_os_detected(){
    int num_valid;
    char option;
    if(detect_os()==1){
        printf("%sYou have Windows Os, I was programmed to run on Unix-like systems :(, Try running me on ubuntu :)%s\n",YELLOW,RESET);
        exit_program();
    }
}

// This function is for executing commands like 'pwd' 'ls' 'cd' inside this program.
// it is not available yet, coming soon :)
int command_executer(const char *command) {
    char buffer[1024];

    // Open a pipe to the command and capture its output.
    FILE *pipe = popen(command, "r");
    if (!pipe) {
        return 1;
    }

    // Read the output of the command from the pipe.
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
    }

    // Close the pipe.
    pclose(pipe);

    return 0;
}


