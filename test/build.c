#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "../src/constants.h"

int is_python_installed() {
    // Try running the Python interpreter
    FILE *fp = popen("python3 --version", "r");
    if (fp == NULL) {
        printf("Error: Unable to execute python command\n");
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

int build() {
    if(detect_os()==0){
            if (is_python_installed()) {
                printf("Python is installed.\n");
            } else {
                printf("Python needs to be installed!.\n");
                system("sudo apt install python3");

            }

     }else if(detect_os()==1){
        if(is_python_installed()){
            printf("python is installed.\n");
        } else{
            printf("Python needs to be installed!\n");
            printf("You have Windows Os, I am not able to install python :(");
            printf("But you can download python from here --> https://www.python.org/downloads/");
        }
     }



    return 0;
}
int main(){
    build();
    return 0;
}