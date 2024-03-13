#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Local libs
#include "pws_lib/pw2/pw2.h"
#include "src/terminal_art/controller.h"

// Functions
void pws_menu();
void pw1_start();
void controler();
void pw2_start();

// PW 1
void pw1_start(){
    show_pw1_menu();
    bool ex_is_set=false;
    int ex_num;
    while(!ex_is_set){
        ex_num=get_int_input();
        if(ex_num==1){
            main_gcd();
        }
        else if(ex_num==2){
            quad();
        }
        else if(ex_num==3){
            abs_val();
        }
        else if(ex_num==4){
            conv();
        }
        else if(ex_num==5){
            pws_menu();
        }
        else if(ex_num==6){
            exit_program();
        }
        else if(ex_num==7){
            system("clear");
            pw1_start();
        }
        else{
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }
}

// PW 2

void pw2_start(){
    show_pw2_menu();
    bool ex_is_set=false;
    int ex_num;
    while(!ex_is_set){
        ex_num=get_int_input();
        if(ex_num==1){
            power();
        }
        else if(ex_num==2){
            is_prime();
        }
        else if(ex_num==3){
            days_in_month();
        }
        else if(ex_num==4){
            bank();
        }
        else if (ex_num==5){
            conv2();
        }
        else if(ex_num==6){
            array_func();
        }
        else if(ex_num==7){
            pws_menu();
        }
        else if(ex_num==8){
            exit_program();
        }
        else if(ex_num==9){
            system("clear");
            pw2_start();
        }
        else{
            
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }
}

// Terminal art
void terminal_art_start(){
    terminal_art_menu();
    bool ex_is_set=false;
    int ex_num;
    while(!ex_is_set){
        ex_num=get_int_input();
        if(ex_num==1){
            rick(); 
            system("clear");
            terminal_art_start();

        }
        else if(ex_num==2){
            parrot();
            system("clear");
            terminal_art_start();
        }
        else if(ex_num==3){
            donut();
            system("clear");
            terminal_art_start();

        }
        else if(ex_num==7){
            pws_menu();
        }
        else if(ex_num==8){
            exit_program();
        }
        else if(ex_num==9){
            system("clear");
            terminal_art_start();
        }
        else{
            
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }
}

//PWs menu
void pws_menu(){
    system("clear");
    show_main_menu();
    printf("\n\n");    
    bool option_is_set = false;
    int option;
    while (!option_is_set) { // Use !option_is_set instead of option_is_set == false
        option=get_int_input();
        if (option == 1) { // Check if the option is within the valid range
            option_is_set = true; // Set option_is_set to true if a valid option is entered
            system("clear");
            pw1_start();    
        }
        else if(option==8){
            controler();
        }
        else if(option==9){
            exit_program();
            option_is_set=true; 
        }
        else if(option==10){
            system("clear");
            terminal_art_start();
        }
        else if(option==2){
            system("clear");
            pw2_start();
        }
        else if(option>2 && option<8){
            printf("%sComing soon!%s\n",YELLOW,RESET);
        }
        else {
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }

}
//Controler function
void controler(){
    int answer;
    bool answer_is_set=false;
    srand(time(NULL)); // Seed the random number generator
    windows_os_detected();
    intro(); // Display the intro

    while(!answer_is_set){
        answer=get_int_input();
        if(answer == 2){
            exit_program();
            answer_is_set=true;
        }
        else if(answer==1){
            answer_is_set=true;
            pws_menu();
        }
        else if(answer==3){
            int os=detect_os();
            if(os==1){
                system("start https://github.com/martian58");
            }else if(os==2){
                system("open https://github.com/martian58");
            }else{
                system("xdg-open https://github.com/martian58");
            }
        }
        
        else{
            continue;
        }
    }
}
// Main function
int main() {
    controler();
    return 0;
}
