#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Local libs
#include "pws_lib/pw1/pw1.h"
void pws_menu();
void pw1_start();
void controler();


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
            printf("%s%s%s",RED,"Invalid option!\n",RESET);
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
        else if(option>1 && option<8){
            printf("%s%s%s",YELLOW,"Coming soon!\n",RESET);
        }
        else {
            printf("%s%s%s",RED,"Invalid option!\n",RESET);
        }
    }

}
//Controler function
void controler(){
    int answer;
    bool answer_is_set=false;
    srand(time(NULL)); // Seed the random number generator
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
            printf("%s%s",RED,"Wrong Input!\n");
        }
    }
}
// Main function
int main() {
    controler();
    return 0;
}