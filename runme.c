#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Local libs
#include "pws_lib/pw4/pw4.h"
#include "src/terminal_art/controller.h"

// Functions
void pws_menu();
void pw1_start();
void controller();
void pw2_start();
void pw3_start();

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

// PW 3 
void pw3_ex3_start(){
    show_pw3_ex3_menu();
    bool ex_is_set=false;
    int ex_num;
    while(!ex_is_set){
        ex_num=get_int_input();
        if(ex_num==1){
            lengthFind();
        }
        else if(ex_num==2){
            print_initilized_string();
        }
        else if(ex_num==3){
            initializeStringN_display();
        }
        else if(ex_num==4){
            comapare_strings_display();
        }else if(ex_num==5){
            concatenate_strings_display();
        }
        else if(ex_num==7){
            system("clear");
            pw3_start();
        }
        else if(ex_num==8){
            exit_program();
        }
        else if(ex_num==9){
            system("clear");
            pw3_ex3_start();
        }
        else{
            
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }
    
}

void pw3_ex5_start(){
    show_pw3_ex5_menu();
    bool ex_is_set=false;
    int ex_num;
    while(!ex_is_set){
        ex_num=get_int_input();
        if(ex_num==1){
            caesar();
        }
        else if(ex_num==2){
            system("xdg-open https://github.com/martian58/enc.git");
        }
        else if(ex_num==7){
            system("clear");
            pw3_start();
        }
        else if(ex_num==8){
            exit_program();
        }
        else if(ex_num==9){
            system("clear");
            pw3_ex5_start();
        }
        else{
            
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }
    
}

void pw3_start(){
    show_pw3_menu();
    bool ex_is_set=false;
    int ex_num;
    while(!ex_is_set){
        ex_num=get_int_input();
        if(ex_num==1){
            display_array();
        }
        else if(ex_num==2){
            array_sort();
        }
        else if(ex_num==3){
            system("clear");
            pw3_ex3_start();
        }
        else if(ex_num==4){
            test_length_function();
            test_initializeString_function();
            test_initializeStringN_function();
            test_compareStrings_function();
            test_concatenateStrings_function();
        }
        else if (ex_num==5){
            system("clear");
            pw3_ex5_start();
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
            pw3_start();
        }
        else{
            
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }
}

// PW 4

void pw4_start(){
    show_pw4_menu();
    bool ex_is_set=false;
    int ex_num;
    while(!ex_is_set){
        ex_num=get_int_input();
        if(ex_num==1){
            playGame_Againts_Friend();
            system("clear");
            pw4_start();
        }
        else if(ex_num==2){
            playGame_Againts_Computer();
            system("clear");
            pw4_start();
        }
        else if(ex_num==7){
            pws_menu();
        }
        else if(ex_num==8){
            exit_program();
        }
        else if(ex_num==9){
            system("clear");
            pw4_start();
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
        else if(ex_num==4){
            mr_robot();
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

// Standard Deviation
void standard_deviation_start(){
    show_standard_deviation_menu();
    bool ex_is_set=false;
    int ex_num;
    while(!ex_is_set){
        ex_num=get_int_input();
        if(ex_num==1){
            period_theoretical();
        }
        else if(ex_num==2){
            period_practical();
        }
        else if(ex_num==3){
            mean_value();
        }
        else if(ex_num==4){
            standard_deviation();
        }
        else if(ex_num==5){
            relative_difference();
        }
        else if(ex_num==7){
            pws_menu();
        }
        else if(ex_num==8){
            exit_program();
        }
        else if(ex_num==9){
            system("clear");
            standard_deviation_start();
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
    while (!option_is_set) { 
        option=get_int_input();
        if (option == 1) { 
            option_is_set = true; 
            system("clear");
            pw1_start();    
        }
        else if(option==8){
            controller();
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
        else if(option==3){
            system("clear");
            pw3_start();
        }
        else if(option==4){
            system("clear");
            pw4_start();
        }
        else if(option==15){
            system("clear");
            standard_deviation_start();

        }
        else if(option>4 && option<8){
            printf("%sComing soon!%s\n",YELLOW,RESET);
        }
        else {
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }

}
//Controller function.
void controller(){
    int answer;
    bool answer_is_set=false;
    srand(time(NULL)); 
    windows_os_detected(); // Detect Windows OS.
    intro(); // Display the intro.

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
// Main function.
int main() {
    controller();
    return 0;
}
