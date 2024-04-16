#include<stdio.h>
char* initializeString(char* dest, const char* src) {
    char* result = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Add null terminator to end the string.
    return result;
}

void main(){
    char random_string[20] = "djghskdghjdfsk";
    char* dest_string = initializeString(dest_string,random_string);
    printf("Source string--> %s\n",random_string);
    printf("Destination string --> %s\n",dest_string);
}
