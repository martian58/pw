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
// Function to install python.
int build_python() {
    if(detect_os()==0){
            if (is_python_installed()) {
                printf("%sPython is installed.%s\n",GREEN,RESET);
            } else {
                printf("%sPython needs to be installed!.%s\n",YELLOW,RESET);
                printf("%sLet's install........%s\n",BLUE,RESET);
                usleep(20000);
                printf(WHITE);
                system("sudo apt install python3");

            }

     }else if(detect_os()==2){
        if(is_python_installed()){
            printf("python is installed.\n");
        } else{
            printf("%sPython needs to be installed!%s\n",YELLOW,RESET);
            printf("%sYou have Mac Os, I am not able to install python :(%s\n",PINK,RESET);
            printf("%sBut you can download python from here --> https://www.python.org/downloads/%s\n",WHITE,RESET);
        }
     }

    return 0;
}

int is_dependencies_installed(){
    if(is_python_installed()!=1){
        return 0;
    }
    return 1;
}

int install_dependencies(){
    if(is_dependencies_installed()!=1){
        build_python();
    }else

    return 0;
}