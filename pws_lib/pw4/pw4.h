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
int countMaxAlignedDisc(int row, int column, char color);
int calculateMaxAlignment(char color);


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
void playAgain(int mode){

    int valid_answer; 

    char opt;
    
    do{
        printf("Wanna play again?(y/n): ");

        valid_answer = scanf(" %c", &opt);

        clear_input_buffer(); // Clear the input buffer.

        if(tolower(opt) == 'y'){

            if(mode == 1){

                playGame_Againts_Computer(); // Run the function to play the first mode.

            }else{

                playGame_Againts_Friend(); // Run the function to play second mode.
            }


        }else if(tolower(opt) == 'n'){

            continue; // Continue to the rest of the code.

        }else{
            
            printf("%sWrong Input%s\n",RED,RESET);
        }

    }while(!valid_answer == 1);
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
    return grid[0][column] == ' '; // Returns true if column is playable.
}

/**
 * @brief Function for dropping the discs.
 * @param column --> The column where the disc is to be dropped.
 * @param color --> The color of the disc to be dropped.
 */
void dropDisc(int column, char color) {

    for (int i = ROWS - 1; i >= 0; i--) {

        if (grid[i][column] == ' ') {

            grid[i][column] = color; // Color represents the Yellow and Red players.

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


int checkFour(char *grid, int a, int b, int c, int d) {

    return (grid[a] != ' ' && grid[a] == grid[b] && grid[b] == grid[c] && grid[c] == grid[d]);
}

/**
 * @brief Checks for a win condition horizontally on the game board.
 * @param grid The game board represented as a character array.
 * @return 1 if a win condition is found horizontally, 0 otherwise.
 */
int checkHorizontal(char *grid) {

    for (int row = 0; row < ROWS; row++) {

        for (int col = 0; col < COLUMNS - 3; col++) {

            int idx = COLUMNS * row + col;

            if (checkFour(grid, idx, idx + 1, idx + 2, idx + 3)) {

                return 1;
            }
        }
    }
    return 0;
}

/**
 * @brief Checks for a win condition vertically on the game board.
 * @param grid The game board represented as a character array.
 * @return 1 if a win condition is found vertically, 0 otherwise.
 */
int checkVertical(char *grid) {

    for (int row = 0; row < ROWS - 3; row++) {

        for (int col = 0; col < COLUMNS; col++) {

            int idx = COLUMNS * row + col;

            if (checkFour(grid, idx, idx + COLUMNS, idx + 2 * COLUMNS, idx + 3 * COLUMNS)) {

                return 1;
            }
        }
    }
    return 0;
}

/**
 * @brief Checks for a win condition diagonally on the game board.
 * @param grid The game board represented as a character array.
 * @return 1 if a win condition is found diagonally, 0 otherwise.
 */
int checkDiagonal(char *grid) {

    for (int row = 0; row < ROWS - 3; row++) {

        for (int col = 0; col < COLUMNS - 3; col++) {

            int idx = COLUMNS * row + col;

            if (checkFour(grid, idx, idx + COLUMNS + 1, idx + 2 * COLUMNS + 2, idx + 3 * COLUMNS + 3)) {

                return 1;
            }

            if (checkFour(grid, idx + 3, idx + COLUMNS + 2, idx + 2 * COLUMNS + 1, idx + 3 * COLUMNS)) {

                return 1;
            }
        }
    }
    return 0;
}

/**
 * @brief Checks for a win condition on the game board.
 * @param board The game board represented as a character array.
 * @return 1 if a win condition is found, 0 otherwise.
 */
int checkWin(char *grid) {

    return (checkHorizontal(grid) || checkVertical(grid) || checkDiagonal(grid));
}

/**
 * @brief Function to recommend a column (random) to play in Easy level.
 * @return The recommended column number.
 */
int recommendColumnRandom() {

    return rand() % (COLUMNS); // return a random number between 1 and 7.
}

/**
 * @brief Function to recommend a column to play in Medium level, considering the longest alignment.
 * @param color --> The color of the player for which the recommendation is made.
 * @return column --> The recommended column number.
 */
int recommendColumnLongestAlign(char color) {

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
 * @brief Function to recommend a column to play in Hard level.
 * @param color The color of the player.
 * @return The recommended column number.
 */
int recommendColumnHard(char color) {

    int maxAlignment = 0;

    int bestColumns[COLUMNS];

    int numBestColumns = 0;

    for (int col = 0; col < COLUMNS; col++) {

        if (isColumnPlayable(col)) {

            for (int row = ROWS - 1; row >= 0; row--) {

                if (grid[row][col] == ' ') {

                    // Simulate placing a disc for the opponent in this column for cheching.

                    grid[row][col] = (color == 'o') ? '*' : 'o';

                    // Check if the opponent wins with this move.

                    if (checkWin(*grid)) { // Check if the player wins with this move.

                        // Reset the grid to its original state.

                        grid[row][col] = ' ';

                        return col; // Block the opponent's winning move.
                    }

                    // Calculate the maximum alignment for the opponent after this move.

                    int alignment = calculateMaxAlignment(color);
                    
                    // Undo the simulated move.

                    grid[row][col] = ' ';

                    if (alignment > maxAlignment) {

                        maxAlignment = alignment;

                        numBestColumns = 0;

                        bestColumns[numBestColumns++] = col;

                    } else if (alignment == maxAlignment) {

                        // Add this column to the list of best columns.

                        bestColumns[numBestColumns++] = col;
                    }

                    // If the computer has three discs in a row, complete the row.
                    if (alignment == 3) {

                        if (rand() % 100 < 10) {

                            return recommendColumnRandom();
                        }
                        return col;
                    }

                    break;
                }
            }
        }
    }

    // Randomly choose one of the best columns.
    if (numBestColumns > 0) {

        int randomIndex = rand() % numBestColumns;

        return bestColumns[randomIndex];
    }

    // If no best columns were found choose a ramdom column.
    return recommendColumnRandom();
}



/**
 * @brief Function to recommend a column to prevent player from winning in Impossible level.
 * @param color The color of the player.
 * @return bestColumn The recommended column number to prevent the player's winning move.
 */
int recommendColumnImpossible(char color) {

    int maxAlignment = 0;

    int bestColumn = 0;

    for (int col = 0; col < COLUMNS; col++) {

        if (isColumnPlayable(col)) {

            for (int row = ROWS - 1; row >= 0; row--) {

                if (grid[row][col] == ' ') {

                    // Simulate placing a disc for the oponent in this column for cheching.

                    grid[row][col] = (color == 'o') ? '*' : 'o';

                    // Check if the opponent wins with this move.

                    if (checkWin(*grid)) {

                        // Reset the grid to its orginal state.

                        grid[row][col] = ' ';

                        return col; // Block the opponent's winning move.
                    }

                    // Calculate the maximum alignment for the opponent after this move.
                    int alignment = calculateMaxAlignment(color);

                    if (alignment > maxAlignment) {

                        maxAlignment = alignment;

                        bestColumn = col;
                    }

                    // Reset the grid to its orginal state.

                    grid[row][col] = ' ';

                   // If the computer has three discs in a row, complete the row to win.
                    if (alignment == 3) {
                        return col;
                    }

                    break;
                }
            }
        }
    }

    return bestColumn;
}

/**
 * @brief Function to calculate the maximum alignment for the opponent after making a move.
 * @param color The color of the player.
 * @return maxAlignment The maximum alignment for the opponent.
 */
int calculateMaxAlignment(char color) {

    int maxAlignment = 0;

    for (int col = 0; col < COLUMNS; col++) {

        if (isColumnPlayable(col)) {

            for (int row = ROWS - 1; row >= 0; row--) {

                if (grid[row][col] == ' ') {

                    // Simulate placing a disc for the oponent in this column.

                    grid[row][col] = (color == 'o') ? '*' : 'o';
                    
                    // Calculate alignment for the opponent after this move.

                    int alignment = countMaxAlignedDisc(row, col, (color == 'o') ? '*' : 'o');

                    if (alignment > maxAlignment) {

                        maxAlignment = alignment;
                    }

                    // Reset the grid to its orginal state.
                    grid[row][col] = ' ';

                    break;
                }
            }
        }
    }
    return maxAlignment;
}

/**
 * @brief Function to count the maximum aligned discs for the opponent.
 * @param row The row index of the current cell.
 * @param column The column index of the current cell.
 * @param color The color of the opponent's disc.
 * @return The count of maximum aligned discs for the opponent.
 */
int countMaxAlignedDisc(int row, int column, char color) {

    int maxAlignment = 0;

    int deltas[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};

    for (int i = 0; i < 4; i++) {

        int aligned = countAlignedDisc(row + deltas[i][0], column + deltas[i][1], deltas[i][0], deltas[i][1], color) +
                      countAlignedDisc(row - deltas[i][0], column - deltas[i][1], -deltas[i][0], -deltas[i][1], color) - 1;
        if (aligned > maxAlignment) {

            maxAlignment = aligned;
        }
    }
    return maxAlignment;
}


/**
* @brief Function to choose the level of the game.
*/
int ChooseLevel(){
    int level_valid;
    int level; // Variable to store the level that the player want.
    system("clear");
    printf("%s**************** Connect 4 ******************%s\n\n",GREEN,RESET);
    printf(" %sChoose the level \n%s",PINK,RESET);
    printf("%s1. Easy (random)\n%s",GREEN,RESET);
    printf("%s2. Medium (longest alignment)\n%s",BLUE,RESET);
    printf("%s3. Hard (hahahahh) \n%s",YELLOW,RESET);
    printf("%s4. Impossible (magic :) )\n\n%s",RED,RESET);


    do{
        printf("%s(connect4) Enter the level number: %s",PINK,RESET);

        level_valid = scanf("%d", &level);

        clear_input_buffer();

        if(level_valid != 1 || (level > 4 || level < 1)){

            printf("%sWrong input!\n%s",RED,RESET);
        }

    }while(level_valid != 1 || level > 4 || level <1);

    return level;
}

/**
 * @brief Function to play a game against the computer.
 */
void playGame_Againts_Computer() {
    int level;
    char currentPlayer = 'o'; // Human player starts with yellow(o).

    system("clear"); // Clear the screen.

    level = ChooseLevel();

    system("clear");

    clearGrid(); // Clear the Game board (grid).

    showGrid(); // Show the boarrd.

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
            if(level == 1){

                column = recommendColumnRandom('*'); // For easy mode.

            }else if(level == 2){

                column = recommendColumnLongestAlign('*'); // For meduim mode.
            
            }else if(level ==3){

                column = recommendColumnHard('*'); // For hard mode.

            }else if(level == 4){

                column = recommendColumnImpossible('*'); // For impossible mode.
            }

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

        if (checkWin(*grid)) {

            if (currentPlayer == 'o') {

                you_won(); // Show win message.

                usleep(100000);

                playAgain(1);

            } else {

                you_lost(); // Show lost message.

                usleep(100000);

                playAgain(1);    
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
            
            fr_column--; 
        }

        if (fr_column < 0 || fr_column >= COLUMNS || !isColumnPlayable(fr_column)) {

            printf("%sInvalid move, try again.%s\n",RED,RESET);

            continue;
        }

        dropDisc(fr_column, fr_currentPlayer);

        system("clear");

        showGrid();

        if (checkWin(*grid)) {

            if (fr_currentPlayer == 'o') {

                printf("%s Yellow player won!\n%s",GREEN,RESET);

                playAgain(2);

            } else {

                printf("%s Red player won!%s\n",RED,RESET);

                playAgain(2);
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
        "@@@@@@@   @@@@@@   @@     @@  @@     @@  @@@@@@@   @@@@@@@   @@@@@@@@@       @@    ",
        "@@@@@@@  @@@@@@@@  @@@    @@  @@@    @@  @@        @@@@@@@   @@@@@@@@@      @@@      ",
        "@@       @@    @@  @@ @@  @@  @@ @@  @@  @@@@@@@   @@           @@        @@ @@    ",
        "@@       @@    @@  @@  @@ @@  @@  @@ @@  @@        @@           @@      @@@@@@@@@@   ",
        "@@@@@@@  @@@@@@@@  @@    @@@  @@    @@@  @@@@@@@   @@@@@@@      @@           @@     ",
        "@@@@@@@   @@@@@@   @@     @@  @@     @@  @@@@@@@   @@@@@@@      @@           @@     ",
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

    // Welcome message.
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

    // Print each line with color transition.
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

    // Print each line with color transition.
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