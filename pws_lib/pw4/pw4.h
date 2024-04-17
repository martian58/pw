/*
 * File:        cli.h
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
#include<assert.h>

// Local Libs
#include "../../src/standard_deviation/standard_deviation.h"


// Function to show the mwnu of pw 3.
void show_pw4_menu() {
    printf("\n\n");
    printf("%s************** PW 4  MENU ****************%s",GREEN,RESET);
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