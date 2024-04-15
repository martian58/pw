/*
  I'm not sure if i'm ever gonna use this. If i dont use and forget to remove, this was meant 
  to install python and flask and maybe other packages for better GUI(web).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/constants.h"

int is_python_installed() {
    char commnd[30];

    if (detect_os() == 0) {
        strcpy(commnd, "python3 --version");
    } else {
        strcpy(commnd, "python --version");
    }

    FILE *fp = popen(commnd, "r");
    if (fp == NULL) {
        printf("%sError: Unable to execute python%s\n",RED,RESET);
        return 0; 
    }

    char output[128];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    if (strstr(output, "Python") != NULL) {
        return 1; 
    } else {
        return 0;  
    }
}
int is_flask_installed() {
    char command[30];

    if (detect_os() == 0) {
        strcpy(command, "python3 -c \"import flask\"");
    } else {
        strcpy(command, "python -c \"import flask\"");
    }

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("%sError: Unable to execute the Python command%s\n", RED, RESET);
        return 0; 
    }

    char output[128];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    if (strstr(output, "ModuleNotFoundError") != NULL) {
        return 0; 
    } else {
        return 1;  
    }
}

int build_python() {
    if(detect_os()==0){
            if (is_python_installed()) {
                printf("%sPython is installed.%s\n",GREEN,RESET);
            } else {
                printf("%sPython needs to be installed!.%s\n",YELLOW,RESET);
                printf("%sLet's install........%s\n",BLUE,RESET);
                usleep(20000);
                printf("%s",WHITE);
                system("sudo apt install python3");

            }

     }else if(detect_os()==2){
        if(is_python_installed()){
            printf("%spython is installed.%s\n",GREEN,RESET);
        } else{
            printf("%sPython needs to be installed!%s\n",YELLOW,RESET);
            printf("%sYou have Mac Os, I am not able to install python :(%s\n",PINK,RESET);
            printf("%sBut you can download python from here --> https://www.python.org/downloads/%s\n",WHITE,RESET);
        }
     }

    return 0;
}
int install_flask() {
    if (detect_os() == 0) {
        if (is_flask_installed()) {
            printf("%sFlask is already installed.%s\n", GREEN, RESET);
        } else {
            printf("%sFlask needs to be installed!%s\n", YELLOW, RESET);
            printf("%sLet's install...%s\n", BLUE, RESET);
            usleep(20000);
            printf("%s",WHITE);
            system("sudo apt install python3-flask");
        }
    } else if (detect_os() == 2) { 
        printf("%sYou have macOS. I am not able to install Flask :(%s\n", PINK, RESET);
        printf("%sBut you can download Flask from here --> https://pypi.org/project/Flask/%s\n", WHITE, RESET);
    }
    return 0;
}
int is_dependencies_installed(){
    if(is_python_installed()!=1){
        return 0;
    }
    if(is_flask_installed()!=1){
        return 0;
    }
    return 1;
}

int install_dependencies(){
    if(is_dependencies_installed()!=1){
        build_python();
        install_flask();
    }else{
    }
    
    return 0;
}