// Ascii codes for colors as a string
char *RED = "\033[1;31m"; 
char *GREEN = "\033[1;32m"; 
char *YELLOW = "\033[1;33m"; 
char *WHITE = "\033[1;37m"; 
char *PINK = "\033[1;35m"; 
char *BLUE = "\033[1;34m"; 
char *RESET = "\033[0m";


//Version information
char *VERSION="1.0";

// Function to show the main menu
void show_main_menu() {
    printf("\n\n");
    printf("%s%s%s",GREEN,"************** PWS MENU ****************",RESET);
    printf("\n\n");
    printf("%s%s%s",BLUE,"1. PW_1 (Available)\n",RESET);
    printf("%s", WHITE);
    printf("2. PW_2 (Coming soon)\n");
    printf("3. PW_3 (Coming soon)\n");
    printf("4. PW_4 (Coming soon)\n");
    printf("5. PW_5 (Coming soon)\n");
    printf("6. PW_6 (Coming soon)\n");
    printf("7. PW_7 (Coming soon)\n");
    printf("%s%s%s",YELLOW,"8. Go back\n",RESET);
    printf("%s%s%s",RED,"9. Exit",RESET);
    printf("%s", RESET);
}

// Function to exit the program
void exit_program(){
    printf("%s%s",YELLOW,"Exiting....\n");
    usleep(1000000);
    printf("%s%s",GREEN,"Have a good day!\n");
    usleep(2000000);
    system("clear");
    exit(0);
}
// Function to get an integer input from the user
int get_int_input() {
    printf("\n\n");
    int input;
    int success;  // Variable to hold the return value of scanf

    do {
        printf("%s%s%s",GREEN,"Enter the number of the option you choose.\n",RESET);
        printf("%s%s%s",PINK,"pw--> ",RESET);
        success = scanf("%d", &input);

        // Clear the input buffer in case of invalid input
        while (getchar() != '\n');

        if (success != 1) {
            printf("%s%s%s",RED,"Invalid option!\n\n",RESET);

        }
    } while (success != 1);

    return input;
}

// Function to get a character input from the user
char get_char_input() {
    printf("\n\n");
    char input;
    printf("%s%s%s",GREEN,"Enter the number of the option you choose.\n",RESET);
    printf("%s%s%s",PINK,"pw--> ",RESET);
    scanf(" %c", &input); //the space before %c to consume whitespace
    return input;
}

// Function to print a line with color transition
void print_colored_line(const char *line, const char *foreground_color, const char *background_color) {
    printf("\033[%s;%sm%s\033[0m\n", foreground_color, background_color, line);
}


// Function to print a line with padding from top and left
void print_padded_line(const char *text, int padding_top, int padding_left) {
    for (int i = 0; i < padding_top; i++) {
        printf("\n");
    }
    printf("%*s%s\n", padding_left, "", text);
}

// Function to generate a random character
char generate_random_char() {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int len = strlen(chars);
    return chars[rand() % len];
}

// PW1 ASCII art with color transition and padding
void intro() {
    // Clear the screen
    printf("\033c");

    // Define color codes
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines
    const char *lines[] = {
        "      @@@@@@@@@   @@                    @@       @@  ",
        "      @@     @@    @@        @@        @@        @@  ",
        "      @@     @@     @@      @@@@      @@         @@   ",
        "      @@@@@@@@@      @@    @@  @@    @@          @@   ",
        "      @@              @@  @@    @@  @@           @@   ",
        "      @@               @@@@      @@@@                 ",
        "      @@                @@        @@             @@   "
    };

    // Print each line with color transition and a random character
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
        usleep(200000); // Sleep for 0.2 seconds
    }

    printf("\n\n");

    // Welcome message,Author and GitHub reference
    printf("\033[1;36m");
    printf("Welcome to PW \n");
    printf("\033[0m");
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
    printf("Continue to the pws menu to explore them.Source codes are in 'pws_lib' directory.\n");
    printf("\n\n");
    printf("1. Continue \n");
    printf("%s%s%s",RED,"2. Exit \n",RESET);
    printf("%s%s%s",GREEN,"3. Visit my github :) \n",RESET);
}



int detect_os() {
    // Check if compiling on Windows
    #ifdef _WIN32
        return 1;
    // Check if compiling on macOS
    #elif defined(__APPLE__)
    printf("macOS detected.\n");
        return 2;
    #else
        // Assume Unix-like system
        return 0;
    #endif
}

