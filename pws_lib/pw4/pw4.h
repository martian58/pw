/*
 * File:        pw4.h
 * Authors:     Fuad Alizada, Mehdi Hasanli, Tural Gadirov
 * Date:        April 16, 2024
 * Description: CLI (Command Line Interface) version of PW 4 (Connect 4 game). 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Local libs.
#include "../../src/standard_deviation/standard_deviation.h"

/*
   o --> Yellow Player
   * --> Red Player
*/

// Define the Rows and Columns for the board.
#define ROWS 6
#define COLUMNS 7

// Declare functions.
void playGame_Againts_Computer();
void playGame_Againts_Friend();
void intro_connect4();
void you_won();
void you_lost();


// Function to show the menu of pw 4.
void show_pw4_menu() {
    intro_connect4();
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Play with friend.\n");
    printf("2. Play against computer. \n");
    printf("%s7. Go back.%s\n",YELLOW,RESET);
    printf("%s8. Exit.%s\n",RED,RESET);
    printf("%s9. Clear screen%s",GREEN,RESET);
    printf("\n\n");
    printf("%sImportant*-> %sSource codes of these exercises are in 'pws_lib/pw4' directory.%s",YELLOW,WHITE,RESET);
    printf("%s", RESET);
}

// Define the grid.
char grid[ROWS][COLUMNS];

/**
 * @brief Function to clear the grid.
 */
void clearGrid() {

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLUMNS; j++) {

            grid[i][j] = ' '; // Replace every cell with ' '.
        }
    }
}

/**
 * @brief Function for playing again.
 */
void playAgain(){

    printf("Wanna play again?(y/n): ");

    char opt = get_char_input();

    if(opt == 'y'){

        playGame_Againts_Computer(); // Run the function.

    }
}

/**
 * @brief Function to print out the grid.
 */
void showGrid() {

    printf("%s\n",WHITE);

    printf("%s********** CONNECT 4 **********%s\n\n", GREEN,BLUE);

    printf("--1---2---3---4---5---6---7--\n"); // Show the column numbers.

    for (int i = 0; i < ROWS; i++) {

        printf("|"); // Print '|' between cells.

        for (int j = 0; j < COLUMNS; j++) {

            if(grid[i][j] == 'o'){

                printf(" %s%c%s |", YELLOW,grid[i][j],BLUE); // Print Yellow player's disks in yellow color.
            }
            else if(grid[i][j] == '*'){

                printf(" %s%c%s |", RED,grid[i][j],BLUE); // Print Red player's disks in red color.
            }
            else{
                printf(" %c |", grid[i][j]); // Empty cells stays as they are. 
            }
        }
        printf("\n");
    }
    printf("--1---2---3---4---5---6---7--\n\n"); // Close the grid.
}

/**
 * @brief Function for deciding if a move is possible.
 * @param column --> The column to check for playability.
 * @return true --> if the column is playable, false otherwise.
 */
bool isColumnPlayable(int column) {
    /*
    * A column is playable if it has empty cell.
    */
    return grid[0][column] == ' ';
}

/**
 * @brief Function for dropping the discs.
 * @param column --> The column where the disc is to be dropped.
 * @param color --> The color of the disc to be dropped.
 */
void dropDisc(int column, char color) {

    for (int i = ROWS - 1; i >= 0; i--) {

        if (grid[i][column] == ' ') {

            grid[i][column] = color;

            break;
        }
    }
}

/**
 * @brief Function for counting the aligned discs.
 * @param row --> The row index of the current cell.
 * @param column -->  The column index of the current cell.
 * @param deltaRow --> The change in row index for checking alignment.
 * @param deltaColumn --> The change in column index for checking alignment.
 * @param color --> The color of the disc to check alignment for.
 * @return  count -->  The count of aligned discs in the specified direction.
 */
int countAlignedDisc(int row, int column, int deltaRow, int deltaColumn, char color) {

    int count = 0;

    while (row >= 0 && row < ROWS && column >= 0 && column < COLUMNS && grid[row][column] == color) {

        count++;

        row += deltaRow;

        column += deltaColumn;
    }
    return count;
}

/**
 * @brief Function to check for a win condition.
 * @param row --> The row index of the last played disc.
 * @param column --> The column index of the last played disc.
 * @param color --> The color of the last played disc.
 * @return true --> if the last move resulted in a win, false otherwise.
 */
bool checkForWin(int row, int column, char color) {

    int deltas[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}}; // directions: right, down, diagonal down-right, diagonal up-right.

    for (int i = 0; i < 4; i++) {

        int count = 1; // Count the current disc.

        count += countAlignedDisc(row + deltas[i][0], column + deltas[i][1], deltas[i][0], deltas[i][1], color);

        count += countAlignedDisc(row - deltas[i][0], column - deltas[i][1], -deltas[i][0], -deltas[i][1], color);

        if (count >= 4) {

            return true; // Player won.
        }
    }
    return false; // Game continues.
}

/**
 * @brief Function to recommend a column (random) to play in Easy level.
 * @return The recommended column number.
 */
int recommendColumn() {

    return rand() % (COLUMNS); // return a random number between 1 and 7.
}

/**
 * @brief Function to recommend a column to play in Medium level, considering the longest alignment.
 * @param color --> The color of the player for which the recommendation is made.
 * @return column --> The recommended column number.
 */
int recommendColumnImproved(char color) {

    int maxAlignment = 0;

    int column = 0;

    for (int j = 0; j < COLUMNS; j++) {

        if (isColumnPlayable(j)) {

            for (int i = ROWS - 1; i >= 0; i--) {

                if (grid[i][j] == ' ') {

                    int alignment = 1;

                    alignment += countAlignedDisc(i, j, 0, 1, color);

                    alignment += countAlignedDisc(i, j, 1, 0, color);

                    alignment += countAlignedDisc(i, j, 1, 1, color);

                    alignment += countAlignedDisc(i, j, -1, 1, color);

                    if (alignment > maxAlignment) {

                        maxAlignment = alignment;

                        column = j;
                    }
                    break;
                }
            }
        }
    }
    return column;
}

/**
 * @brief Function to play a game against the computer.
 */
void playGame_Againts_Computer() {

    char currentPlayer = 'o'; // Human player starts with yellow(o).

    system("clear"); // Clear the screen.

    clearGrid(); // Clear the Game board (grid).

    showGrid(); // Show the board.

    while (true) {

        int column;

        int num_valid;

        if (currentPlayer == 'o') { 
            do {
                printf("%sYour turn (choose column 1-7): %s",PINK,RESET);

                num_valid = scanf("%d", &column);

                clear_input_buffer();

                if (num_valid != 1) {

                    printf("%sInvalid move, try again%s\n",RED,RESET);

                    continue;
                }
            } while (num_valid != 1);

            column--;

        } else {

            column = recommendColumn('*'); // Computer plays red(*).

            printf("%sComputer playing.........%s\n",YELLOW,RESET);

            usleep(1000000);   
        }

        if (column < 0 || column >= COLUMNS || !isColumnPlayable(column)) {

            printf("%sInvalid move, try again.%s\n",RED,RESET);

            continue;
        }

        dropDisc(column, currentPlayer);

        system("clear");

        showGrid();

        if (checkForWin(ROWS - 1, column, currentPlayer)) {

            if (currentPlayer == 'o') {

                you_won();

                usleep(300000);

            } else {

                printf("%sComputer wins!%s\n",RED,RESET);
            }

            break;
        }

        if (currentPlayer == 'o') {

            currentPlayer = '*'; // Switch to computer player.
        } else {

            currentPlayer = 'o'; // Switch to human player.
        }
    }
}

/**
 * @brief Function to play a game with your friend.
 */
void playGame_Againts_Friend(){
    char fr_currentPlayer = 'o'; // First friend starts with yellow(o).

    system("clear");

    clearGrid();

    showGrid();

    while (true) {
        int fr_column;

        int fr_num_valid;

        if (fr_currentPlayer == 'o') {
            
            do {
                printf("%sYour turn (choose column 1-7): %s",PINK,RESET);

                fr_num_valid = scanf("%d", &fr_column);

                clear_input_buffer();

                if (fr_num_valid != 1) {

                    printf("%sInvalid move, try again%s\n",RED,RESET);

                    continue;
                }
            } while (fr_num_valid != 1);

            fr_column--;

        } else {
            printf("%sRed player's turn (choose column 1-7): %s",PINK,RESET);

            scanf("%d", &fr_column);
            
            fr_column--; // adjust to 0-indexed  
        }

        if (fr_column < 0 || fr_column >= COLUMNS || !isColumnPlayable(fr_column)) {

            printf("%sInvalid move, try again.%s\n",RED,RESET);

            continue;
        }

        dropDisc(fr_column, fr_currentPlayer);

        system("clear");

        showGrid();

        if (checkForWin(ROWS - 1, fr_column, fr_currentPlayer)) {

            if (fr_currentPlayer == 'o') {

                printf("%s Yellow player won!\n%s",GREEN,RESET);

            } else {

                printf("%s Red player won!%s\n",RED,RESET);
            }
            break;
        }

        if (fr_currentPlayer == 'o') {

            fr_currentPlayer = '*'; // Switch to red player.

        } else {

            fr_currentPlayer = 'o'; // Switch to yellow player.
        }
    }
}


void intro_connect4() {

    // Define color codes.
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines.
    const char *lines[] = {
        "@@@@@@@   @@@@@@   @@     @@  @@     @@  @@@@@@@   @@@@@@@@@       @@    ",
        "@@@@@@@  @@@@@@@@  @@@    @@  @@@    @@  @@@@@@@   @@@@@@@@@      @@@      ",
        "@@       @@    @@  @@ @@  @@  @@ @@  @@  @@           @@        @@ @@    ",
        "@@       @@    @@  @@  @@ @@  @@  @@ @@  @@           @@      @@@@@@@@@@   ",
        "@@@@@@@  @@@@@@@@  @@    @@@  @@    @@@  @@@@@@@      @@           @@     ",
        "@@@@@@@   @@@@@@   @@     @@  @@     @@  @@@@@@@      @@           @@     ",
    };

    // Print each line with color transition and a random character.
    printf("\n\n");
    for (int i = 0; i < 6; i++) {
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

void you_won() {
    // Clear screen.
    printf("\033c");
    // Define color codes.
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines.
    const char *lines[] = {
    "@@       @@  @@@@@@@@  @@    @@     @@      @@   @@      @@  @@@@@@@@  @@      @@    @@ @@",
    " @@     @@   @@    @@  @@    @@      @@      @@ @@      @@   @@    @@  @@@     @@    @@ @@",
    "  @@   @@    @@    @@  @@    @@       @@      @@@      @@    @@    @@  @@ @@   @@    @@ @@",
    "   @@ @@     @@    @@  @@    @@        @@     @@      @@     @@    @@  @@  @@  @@    @@ @@",
    "    @@@      @@    @@  @@    @@         @@   @@ @@   @@      @@    @@  @@   @@ @@    @@ @@  ",
    "    @@@      @@@@@@@@  @@@@@@@@          @@ @@   @@ @@       @@@@@@@@  @@     @@@          ",
    "    @@@      @@@@@@@@  @@@@@@@@            @@      @@        @@@@@@@@  @@      @@    @@ @@  ",
    };

    // Print each line with color transition and a random character.
    printf("\n\n");
    for (int i = 0; i < 7; i++) {
        char line_copy[strlen(lines[i]) + 1];
        strcpy(line_copy, lines[i]);
        char rnd_char = '@';
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
    for (int i = 0; i < 7; i++) {
        char line_copy[strlen(lines[i]) + 1];
        strcpy(line_copy, lines[i]);
        char rnd_char = '@';
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