/*
 * File:        pw5.h
 * Authors:     Fuad Alizada, Mehdi Hasanli, Tural Gadirov, Togrul Abdullazada
 * Date:        April 27, 2024
 * Description: Exercises of the practical work 5. 
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


// Local libs.
#include "../pw4/pw4.h"

// Functions
void human_guess();
void computer_guess();


// Function to show the menu of pw 4.
void show_pw5_menu() {
    printf("\n\n");
    printf("%s************** PW 5  MENU ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Ex_1 (Square root).\n");
    printf("2. Ex_2 (Number Guessing Game). \n");
    printf("3. Ex_3 (Bastra Game). \n");
    printf("%s7. Go back.%s\n",YELLOW,RESET);
    printf("%s8. Exit.%s\n",RED,RESET);
    printf("%s9. Clear screen%s",GREEN,RESET);
    printf("\n\n");
    printf("%sImportant*-> %sSource codes of these exercises are in 'pws_lib/pw5' directory.%s",YELLOW,WHITE,RESET);
    printf("%s", RESET);
}

//************************************************************************************************************************************
// EX 1


/**
 * @brief Calculates the square root of a real number using a specific sequence.
 * @param num The real number for which the square root is to be calculated.
 * @return u0 The square root of the input real number.
 */
double squareRoot(double num) {

    double precis = 0.00001; // Precision here.

    double u0 = num; // Initial.
    
    // Iterate until the difference is less than precis.
    while (true) {  

        double u1 = (u0 + num / u0) / 2.0;
        
        // If the differences is less than precis.

        if (u0 - u1 < precis && u1 - u0 < precis) {

            return u1;
        }
        
        u0 = u1;
    }
}


int sqr_root() {

    double num; 

    bool validInput;
    
    // Get the input.
    do {

        printf("%sEnter a real number: %s", WHITE,RESET);

        if (scanf("%lf", &num) == 1) {

            validInput = true; 

        } else {

            printf("%sInvalid input. Please enter a valid real number.%s\n",RED,RESET);

            // Clear the input buffer.

            clear_input_buffer();
        }
    } while (!validInput);
    
    // Calculate the root.

    printf("%s\nSquare root of %s%lf %sis %s%lf\n%s",WHITE,GREEN, num,WHITE,GREEN, squareRoot(num),RESET);
    
    return 0;
}


//************************************************************************************************************************************************
// EX 2

// Intro for the Guess Num game.
void intro_number_guess() {

    // Define color codes.
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines.
    const char *lines[] = {
     "  ______                                                 __    __                         ",
    " /      \\                                               |  \\  |  \\                        ",
    "|  $$$$$$\\ __    __   ______    _______   _______       | $$\\ | $$ __    __  ______ ____  ",
    "| $$ __\\$$|  \\  |  \\ /      \\  /       \\ /       \\      | $$$\\| $$|  \\  |  \\|      \\    \\ ",
    "| $$|    \\| $$  | $$|  $$$$$$\\|  $$$$$$$|  $$$$$$$      | $$$$\\ $$| $$  | $$| $$$$$$\\$$$$\\ ",
    "| $$ \\$$$$| $$  | $$| $$    $$ \\$$    \\  \\$$    \\       | $$\\$$ $$| $$  | $$| $$ | $$ | $$ ",
    "| $$__| $$| $$__/ $$| $$$$$$$$ _\\$$$$$$\\ _\\$$$$$$\\      | $$ \\$$$$| $$__/ $$| $$ | $$ | $$  ",
    "\\$$    $$  \\$$    $$ \\$$     \\|       $$|       $$      | $$  \\$$$ \\$$    $$| $$ | $$ | $$  ",
    " \\$$$$$$    \\$$$$$$   \\$$$$$$$ \\$$$$$$$  \\$$$$$$$        \\$$   \\$$  \\$$$$$$  \\$$  \\$$  \\$$  "
    };

    // Print each line with color transition and a random character.
    printf("\n\n");

    for (int i = 0; i < 9; i++) {

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
    printf("Welcome to  Guess Num \n");
    printf("\033[0m");
    printf("%sVersion: %s\n",PINK,VERSION);
    printf("\033[1;33m");
    usleep(300000);
    printf("\033[0m");
}

// ex 2 menu
void show_pw5_ex2_menu() {
    intro_number_guess();
    printf("\n");
    printf("%s",WHITE);
    printf("1. Human player gueses.\n");
    printf("2. Computer gueses. \n");
    printf("%s7. Go back.%s\n",YELLOW,RESET);
    printf("%s8. Exit.%s\n",RED,RESET);
    printf("%s9. Clear screen%s",GREEN,RESET);
    printf("\n\n");
    printf("%sImportant*-> %sSource codes of these exercises are in 'pws_lib/pw5' directory.%s",YELLOW,WHITE,RESET);
    printf("%s", RESET);
}

int play_again(int mode){
    char response;

    // Ask if the user wants to continue playing.
    printf("Wanna play again? (y/n): ");

    scanf(" %c", &response);

    if(tolower(response) == 'y'){

        if(mode ==1){

            printf("\033c");

            human_guess();

        }else{

            printf("\033c");

            computer_guess();
        }
    }
}

void human_guess() {

    int target, guess;

    char response;

    int tries = 1;

    bool validInput;

    srand(time(NULL));

    // Generate a random number between 1 and 999.
    target = rand() % 999 + 1;
    
    intro_number_guess();
    // User guesses the number
    do {
         // Get the input.
        do {

            printf("\n%sEnter a number(1-999): %s",WHITE,RESET);

            if (scanf("%d", &guess) == 1) {

                validInput = true; 

            } else {

                printf("%sInvalid input. Please enter a valid real number.%s\n",RED,RESET);

                // Clear the input buffer.

                while (getchar() != '\n');
            }
        } while (!validInput);

        // Check if the guess is correct
        if (guess == target) {

            if(tries <=5){

                printf("\n\n%sYou lucky..... :)\n\n %s",PINK,RESET);

                printf("%sTries:%s %d %s\n",WHITE,GREEN, tries,RESET);

                printf("%sScore:%s Lucky%s\n",WHITE,PINK,RESET);

                break;
            }
            else if(tries <=10){

                printf("%s\nCongratulations! I see you know the Algorithm.\n\n%s",GREEN,RESET);

                printf("%sTries:%s %d %s\n",WHITE,GREEN, tries,RESET);

                printf("%sScore:%s Excellent%s\n",WHITE,GREEN,RESET);

                break;
            }
            else if(20>=tries>=10){

                printf("%s\nCongrats! You found the number, not bad, not bad :)\n\n%s",GREEN,RESET);

                printf("%sTries:%s %d %s\n",WHITE,GREEN, tries,RESET);

                printf("%sScore:%s Good%s\n",WHITE,BLUE,RESET);

                break;
            }
            else{

                printf("%s\nDont you dare to play this game again bruhhhh -_- %s\n\n",RED,RESET);

                printf("%sTries:%s %d %s\n",WHITE,RED, tries,RESET);

                printf("%sScore:%s Terrible%s\n",WHITE,RED,RESET);

                break;
            }
        } else if (guess < target) {

            printf("%sMy number is greater than %s%d.%s\n",WHITE,GREEN, guess,RESET);

        } else {

            printf("%sMy number is smaller than %s%d.%s\n",WHITE,PINK, guess,RESET);

        }
        
        tries++;

    } while (true);

    play_again(1);

}



// Function to play with computer.
void computer_guess() {

    int target, guess;

    int min = 1; 

    int max = 999; 

    int tries = 1;

    bool validInput;

    intro_number_guess();

    // Get the input (the number for the computer to guess).
    do {
        printf("\n%sEnter a number for the computer to guess (1-999): %s", WHITE, RESET);

        if (scanf("%d", &target) == 1 && target >= 1 && target <= 999) {

            validInput = true;

        } else {

            printf("%sInvalid input. Please enter a number between 1 and 999.%s\n", RED, RESET);

            // Clear the input buffer.
            clear_input_buffer();

            validInput = false;
        }
    } while (!validInput);

    // Computer's guessing algorithm (binary search-like).
    do {
        // Calculate the guess.
        guess = (min + max) / 2;
        
        // Display the guess.
        printf("\n%sComputer guesses:%s %d%s\n",WHITE,GREEN, guess,RESET);

        // Get the user's feedback.

        char feedback;

        //Prevent user from lying, because humans are well known for it :).

        do {
            
            printf("%sGive feedback 'f'(found),'g'(greater),'s'(smaller): %s",WHITE,RESET);

            scanf(" %c", &feedback);

            if(feedback != 'f' && guess == target){

                printf("%sAren't you a little lier?.%s\n",YELLOW,RESET);

                continue;

            }else if(feedback == 'g' && guess > target){

                printf("%sThat smells like a lie!%s\n",YELLOW,RESET);

                continue;

            }else if(feedback == 's' && guess < target){

                printf("%sWhen you gonna stop lying?%s\n",YELLOW,RESET);

                continue;
            }
        } while (feedback != 'f' && feedback != 'g' && feedback != 's');

        // Adjust the range based on user's feedback.
        if (feedback == 'f') {

            printf("%s\nI found the number %s%d%s in %s%d%s tries.%s\n\n",WHITE, GREEN,target,WHITE ,GREEN, tries,WHITE, RESET);

            printf("%sI already new it from the begining bruhhh%s\n", PINK, RESET);

            break;
        
        }else if(feedback != 'f' && guess == target){

            continue;
        }
        else if(feedback == 'g' && guess > target){

            continue;
        }else if(feedback == 's' && guess < target){

            continue;
        }
        else if (feedback == 'g') {

            min = guess + 1; // Adjust the minimum range

            tries++;

        } else {

            max = guess - 1; // Adjust the maximum range

            tries++;
        }
        

    } while (min <= max);

    play_again(2);
}




//**************************************************************************************************************************************
// Ex 3  Bastra Game


// Intro for the Bastra game.
void intro_bastra() {

    // Define color codes.
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines.
    const char *lines[] = {
    "░▒▓███████▓▒░ ░▒▓██████▓▒░ ░▒▓███████▓▒ ▒▓████████▓▒ ▒▓███████▓▒░ ░▒▓██████▓▒░  ",
    "░▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░         ░▒▓█▓▒░    ▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░░▒▓█▓▒░ ",
    "░▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░         ░▒▓█▓▒░    ▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░░▒▓█▓▒░ ",
    "░▒▓███████▓▒░ ▒▓████████▓▒ ░▒▓██████▓▒░   ░▒▓█▓▒░    ▒▓███████▓▒  ▒▓████████▓▒░ ",
    "░▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░░▒▓█▓▒       ░▒▓█▓▒░  ░▒▓█▓▒░    ▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░░▒▓█▓▒░ ",
    "░▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░░▒▓█▓▒       ░▒▓█▓▒░  ░▒▓█▓▒░    ▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░░▒▓█▓▒░ ",
    "░▒▓███████▓▒░ ▒▓█▓▒░░▒▓█▓▒ ▒▓███████▓▒░   ░▒▓█▓▒░    ▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒░░▒▓█▓▒░",
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

    // Welcome message.
    printf("\033[1;36m");
    printf("Welcome to  Bastra \n");
    printf("\033[0m");
    printf("%sVersion: %s\n",PINK,VERSION);
    printf("\033[1;33m");
    usleep(300000);
    printf("\033[0m");
}


#define DECK_SIZE 52

#define TARGET_SCORE 100

#define NUM_CARDS_PER_HAND 4

#define INITIAL_BOARD_SIZE 4

typedef struct {

    int num;

    enum {SPADES, HEARTS, DIAMONDS, CLUBS} suit;
} Card;

typedef struct {

    Card *cards;

    int num_cards;
} Hand;

/**
 * @brief Initializes the deck of cards with 52 cards.
 * 
 * @param deck Array to store the cards.
 */
void initializaDeck(Card deck[]) {

    int index = 0;

    for (int num = 1; num <= 13; num++) {

        for (int suit = SPADES; suit <= CLUBS; suit++) {

            deck[index].num = num;

            deck[index].suit = suit;

            index++;
        }
    }
}

/**
 * @brief Shuffles the deck of cards.
 * 
 * @param deck Array containing the cards to shuffle.
 */
void shuffle(Card deck[]) {

    for (int i = 0; i < DECK_SIZE; i++) {

        int j = rand() % DECK_SIZE;

        Card temp = deck[i];

        deck[i] = deck[j];

        deck[j] = temp;
    }
}

/**
 * @brief Deals cards to a player's hand and the board.
 * 
 * @param deck Array containing the full deck of cards.
 * @param hand Pointer to the player's hand structure.
 * @param board Array representing the board.
 * @param num_cards Number of cards to deal to the player's hand.
 */
void dis_cards(Card deck[], Hand *hand, Card board[], int num_cards) {

    hand->cards = (Card *)malloc(num_cards * sizeof(Card));

    hand->num_cards = num_cards;

    for (int i = 0; i < num_cards; i++) {

        hand->cards[i] = deck[i];
    }
    for (int i = 0; i < INITIAL_BOARD_SIZE; i++) {

        board[i] = deck[num_cards + i];
    }
}

/**
 * @brief Prints a card.
 * 
 * @param card The card to print.
 */
void print_pl_card(Card card) {

    const char *nums[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    const char *suits[] = {"S", "H", "D", "C"};

    printf("%s%s ", nums[card.num], suits[card.suit]);
}

/**
 * @brief Prints a player's hand.
 * 
 * @param hand Pointer to the player's hand structure.
 */
void print_pl_hand(Hand *hand) {

    for (int i = 0; i < hand->num_cards; i++) {

        print_pl_card(hand->cards[i]);
    }
    printf("\n");
}

/**
 * @brief Prints the board.
 * 
 * @param board Array representing the board.
 * @param size Size of the board.
 */
void print_board(Card *board, int size) {

    printf("%sCurrent board: %s",BLUE,RESET);

    for (int i = 0; i < size; i++) {

        print_pl_card(board[i]);
    }
    printf("\n");
}

/**
 * @brief Allows a player to choose a card to play.
 * 
 * @param hand Pointer to the player's hand structure.
 * @return The chosen card.
 */
Card chooseCard(Hand *hand) {

    printf("%s\nChoose a card to play (1-%d): %s",PINK, hand->num_cards,RESET);

    int choice;

    scanf("%d", &choice);

    return hand->cards[choice - 1];
}

/**
 * @brief Plays a card.
 * 
 * @param card The card to play.
 * @param hand Pointer to the player's hand structure.
 * @param board Array representing the board.
 * @param size_of_board Pointer to the size of the board.
 */
void play(Card card, Hand *hand, Card *board, int *size_of_board) {

    int collect = 0;

    for (int i = 0; i < *size_of_board; i++) {

        if (board[i].num != 0 && board[i].num + card.num == 10) {

            board[i].num = 0;

            collect = 1;

            break;
        }
    }
    if (!collect) {

        board[*size_of_board] = card;

        (*size_of_board)++;
    }
    for (int i = 0; i < hand->num_cards; i++) {

        if (hand->cards[i].num == card.num && hand->cards[i].suit == card.suit) {

            for (int j = i; j < hand->num_cards - 1; j++) {

                hand->cards[j] = hand->cards[j + 1];
            }
            hand->num_cards--;

            break;

        }
    }
}

/**
 * @brief Calculates points based on the cards on the board.
 * 
 * @param board Array representing the board.
 * @param size_of_board Size of the board.
 * @return The total points.
 */
int calc_points(Card *board, int size_of_board) {

    int points = 0;

    for (int i = 0; i < size_of_board; i++) {

        if (board[i].num != 0) {

            points++;
        }
    }
    return points;
}

/**
 * @brief This function ckecks if a player has reached the target score.
 * 
 * @param score The player's current score.
 * @return 1 if the player has won, otherwise 0.
 */
int check_Win(int score) {

    if (score >= TARGET_SCORE) {

        return 1;
    }
    return 0;
}

/**
 * @brief Main function fot the Bastra game.
 */
int play_bastra() {

    srand(time(NULL));

    Card deck[DECK_SIZE];

    initializaDeck(deck);

    shuffle(deck);

    Hand hand1, hand2;

    int size_of_board = 0;

    Card *board = (Card *)malloc(DECK_SIZE * sizeof(Card));

    int score1 = 0, score2 = 0;

    int round_num = 1;

    while (1) {

        dis_cards(deck, &hand1, board, NUM_CARDS_PER_HAND);

        dis_cards(deck + NUM_CARDS_PER_HAND, &hand2, board, NUM_CARDS_PER_HAND);

        size_of_board = INITIAL_BOARD_SIZE;

        while (hand1.num_cards > 0 || hand2.num_cards > 0) {

            printf("%sPlayer 1 hand: %s",WHITE,RESET);

            print_pl_hand(&hand1);

            printf("%sPlayer 2 hand: %s",WHITE,RESET);

            print_pl_hand(&hand2);

            print_board(board, size_of_board);

            printf("\nPlayer 1's turn:\n");

            Card played_card = chooseCard(&hand1);

            play(played_card, &hand1, board, &size_of_board);

            printf("\nBoard after player 1's turn:\n");

            print_board(board, size_of_board);

            score1 += calc_points(board, size_of_board);

            printf("Player 1's points in this round: %d\n", score1);

            if (check_Win(score1)) {

                printf("\nPlayer 1 wins with %d points!\n", score1);

                break;
            }
            
            printf("\nPlayer 2's turn:\n");

            played_card = chooseCard(&hand2);

            play(played_card, &hand2, board, &size_of_board);

            printf("\nBoard after player 2's turn:\n");

            print_board(board, size_of_board);

            score2 += calc_points(board, size_of_board);

            printf("Player 2's points in this round: %d\n", score2);

            if (check_Win(score2)) {

                printf("\nPlayer 2 wins with %d points!\n", score2);

                break;
            }
        }

        if (check_Win(score1) || check_Win(score2)) {

            break;
        }

        round_num++;
    }

    free(board);

    return 0;
}
