#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 6
#define COLUMNS 7

// Define the grid structure
char grid[ROWS][COLUMNS];

// Exercise 2: Clear the grid
void clearGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = ' ';
        }
    }
}

// Exercise 3: Show the grid
void showGrid() {
    printf("\n");
    printf("-----------------------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLUMNS; j++) {
            printf(" %c |", grid[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

// Exercise 4: Deciding if a move is possible
bool isColumnPlayable(int column) {
    return grid[0][column] == ' ';
}

// Exercise 5: Drop a disc
void dropDisc(int column, char color) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (grid[i][column] == ' ') {
            grid[i][column] = color;
            break;
        }
    }
}

// Exercise 6: Count the aligned disc
int countAlignedDisc(int row, int column, int deltaRow, int deltaColumn, char color) {
    int count = 0;
    while (row >= 0 && row < ROWS && column >= 0 && column < COLUMNS && grid[row][column] == color) {
        count++;
        row += deltaRow;
        column += deltaColumn;
    }
    return count;
}

bool checkForWin(int row, int column, char color) {
    int deltas[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}}; // directions: right, down, diagonal down-right, diagonal up-right
    for (int i = 0; i < 4; i++) {
        int count = 1; // count the current disc
        count += countAlignedDisc(row + deltas[i][0], column + deltas[i][1], deltas[i][0], deltas[i][1], color);
        count += countAlignedDisc(row - deltas[i][0], column - deltas[i][1], -deltas[i][0], -deltas[i][1], color);
        if (count >= 4) {
            return true; // win
        }
    }
    return false; // no win
}

// Exercise 7: Recommend a column to play in (random)
int recommendColumn() {
    return rand() % COLUMNS;
}

// Exercise 8: Improve advice (longest alignment)
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

// Exercise 9: Play a game
void playGame() {
    char currentPlayer = 'Y'; // Human player starts with yellow
    system("clear");
    clearGrid();
    showGrid();

    while (true) {
        int column;
        if (currentPlayer == 'Y') {
            printf("Your turn (choose column 1-7): ");
            scanf("%d", &column);
            column--; // adjust to 0-indexed
        } else {
            column = recommendColumnImproved('R'); // Computer plays red
            printf("Computer playing.........\n");
            usleep(2000000);   
        }

        if (column < 0 || column >= COLUMNS || !isColumnPlayable(column)) {
            printf("Invalid move, try again.\n");
            continue;
        }

        dropDisc(column, currentPlayer);
        system("clear");
        showGrid();

        if (checkForWin(ROWS - 1, column, currentPlayer)) {
            if (currentPlayer == 'Y') {
                printf("Congratulations! You win!\n");
            } else {
                printf("Computer wins!\n");
            }
            break;
        }

        if (currentPlayer == 'Y') {
            currentPlayer = 'R'; // Switch to computer player
        } else {
            currentPlayer = 'Y'; // Switch to human player
        }
    }
}

int main() {
    playGame();
    return 0;
}
