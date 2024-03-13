#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/constants.h"

int is_python_installed() {
    // Define the command string.
    char commnd[30];

    // Choose the appropriate command based on the OS.
    if (detect_os() == 0) {
        strcpy(commnd, "python3 --version");
    } else {
        strcpy(commnd, "python --version");
    }

    // Try running the Python interpreter.
    FILE *fp = popen(commnd, "r");
    if (fp == NULL) {
        printf("%sError: Unable to execute python%s\n",RED,RESET);
        return 0;  // Python is not installed or accessible
    }

    // Read the output of the Python command
    char output[128];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    // Check if the output contains "Python" (indicating Python is installed)
    if (strstr(output, "Python") != NULL) {
        return 1;  // Python is installed
    } else {
        return 0;  // Python is not installed
    }
}
int is_flask_installed() {
    // Define the command string.
    char command[30];

    // Choose the appropriate command based on the OS.
    if (detect_os() == 0) {
        strcpy(command, "python3 -c \"import flask\"");
    } else {
        strcpy(command, "python -c \"import flask\"");
    }

    // Try running the Python command.
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("%sError: Unable to execute the Python command%s\n", RED, RESET);
        return 0;  // Flask is not installed or Python is not accessible
    }

    // Read the output of the Python command.
    char output[128];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    // Check if the output contains "ImportError" (indicating Flask is not installed).
    if (strstr(output, "ModuleNotFoundError") != NULL) {
        return 0;  // Flask is not installed
    } else {
        return 1;  // Flask is installed
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
    if (detect_os() == 0) { // Assuming detect_os() returns 0 for Linux
        // Check if Flask is already installed
        if (is_flask_installed()) {
            printf("%sFlask is already installed.%s\n", GREEN, RESET);
        } else {
            printf("%sFlask needs to be installed!%s\n", YELLOW, RESET);
            printf("%sLet's install...%s\n", BLUE, RESET);
            usleep(20000);
            printf("%s",WHITE);
            system("sudo apt install python3-flask");
        }
    } else if (detect_os() == 2) { // Assuming detect_os() returns 2 for macOS
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