#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "../src/constants.h"

void intro_connect4() {

    // Define color codes.
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines.
    const char *lines[] = {
    "@@       @@  @@@@@@@@  @@    @@           @@            @@@@@@@@   @@@@@@@@@@   @@@@@@@@@@@@    @@ @@    ",
    " @@     @@   @@    @@  @@    @@           @@            @@    @@   @@                @@         @@ @@    ",
    "  @@   @@    @@    @@  @@    @@           @@            @@    @@   @@@@@@@@@         @@         @@ @@   ",
    "   @@ @@     @@    @@  @@    @@           @@            @@    @@          @@         @@         @@ @@     ",
    "    @@@      @@    @@  @@    @@           @@            @@    @@          @@         @@         @@ @@     ",
    "    @@@      @@@@@@@@  @@@@@@@@           @@@@@@@@@@@   @@@@@@@@   @@@@@@@@@@        @@                 ",
    "    @@@      @@@@@@@@  @@@@@@@@           @@@@@@@@@@@   @@@@@@@@   @@@@@@@@@@        @@         @@ @@ :(",
    };

    // Print each line with color transition and a random character.
    printf("\n\n");
    for (int i = 0; i < 7; i++) {
        char line_copy[strlen(lines[i]) + 1];
        strcpy(line_copy, lines[i]);
        char rnd_char = 'O';
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
    printf("Welcome to Connect 4 \n");
    printf("\033[0m");
    printf("%sVersion: %s\n",PINK,VERSION);
    printf("\033[1;33m");
    usleep(300000);
    printf("\033[0m");
}

void you_lost() {
    // Clear screen.
    printf("\033c");
    // Define color codes.
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines.
    const char *lines[] = {
    "@@       @@  @@@@@@@@  @@    @@           @@            @@@@@@@@   @@@@@@@@@@   @@@@@@@@@@@@    @@ @@    ",
    " @@     @@   @@    @@  @@    @@           @@            @@    @@   @@                @@         @@ @@    ",
    "  @@   @@    @@    @@  @@    @@           @@            @@    @@   @@@@@@@@@         @@         @@ @@   ",
    "   @@ @@     @@    @@  @@    @@           @@            @@    @@          @@         @@         @@ @@     ",
    "    @@@      @@    @@  @@    @@           @@            @@    @@          @@         @@         @@ @@     ",
    "    @@@      @@@@@@@@  @@@@@@@@           @@@@@@@@@@@   @@@@@@@@   @@@@@@@@@@        @@                 ",
    "    @@@      @@@@@@@@  @@@@@@@@           @@@@@@@@@@@   @@@@@@@@   @@@@@@@@@@        @@         @@ @@ :(",
    };

    // Print each line with color transition and a random character.
    printf("\n\n");
    for (int i = 0; i < 8; i++) {
        char line_copy[strlen(lines[i]) + 1];
        strcpy(line_copy, lines[i]);
        char rnd_char = 'O';
        for (int j = 0; line_copy[j] != '\0'; j++) {
            if (line_copy[j] == '@') {
                line_copy[j] = rnd_char;
            }
        }
        print_colored_line(line_copy, colors[i % 5], colors[(i + 1) % 5]);
        usleep(200000); // Sleep for 0.2 seconds.
    }

    printf("\n\n");
}

int main(){
    intro_connect4();
    return 0;
}