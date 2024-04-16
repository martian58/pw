#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

char *RED = "\033[1;31m"; 
char *GREEN = "\033[1;32m"; 
char *YELLOW = "\033[1;33m"; 
char *WHITE = "\033[1;37m"; 
char *PINK = "\033[1;35m"; 
char *BLUE = "\033[1;34m"; 
char *RESET = "\033[0m";

char* generateRandomString() {
    const char* charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 

    int min_length = 8;
    int max_length = 20;

    int length = min_length + rand() % (max_length - min_length + 1); 

    char* randomString = malloc((length + 1) * sizeof(char)); 
    if (randomString == NULL) {
        return NULL; 
    }

    int charsetLength = strlen(charset);

    srand(time(NULL)); 

    for (int i = 0; i < length; i++) {
        randomString[i] = charset[rand() % charsetLength];
    }
    randomString[length] = '\0'; 

    return randomString;
}

int compareStrings(const char* str1, const char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

void comapare_strings_display(){
    char* str1 = generateRandomString();
    char* str2 = generateRandomString();
    printf("%s(strcmp) First string --> %s %s%s\n",WHITE,GREEN,str1,RESET);
    printf("%s(strcmp) Second string --> %s %s%s\n\n",WHITE,GREEN,str2,RESET);
    int result = compareStrings(str1,str2);
    if(result == 0){
        printf("%s compareStrings() function returns %s0%s, which means strings are %sequal.%s\n",WHITE,GREEN,WHITE,GREEN,RESET);
    } else if(result < 0){
        printf("%s compareStrings() function returns %s%d%s, which means string 2 is %sgreater%s than string 1.%s\n",WHITE,GREEN,result,WHITE,GREEN,WHITE,RESET);
    }else{
        printf("%s compareStrings() function returns %s%d%s, which means string 1 is %sgreater%s than string 2.%s\n",WHITE,GREEN,result,WHITE,GREEN,WHITE,RESET);
    }
}

int main(){
    comapare_strings_display();
    return 0;
}