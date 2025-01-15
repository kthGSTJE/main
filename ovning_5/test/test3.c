#include<stdio.h>
#define MONTH 1

int main (void){
    unsigned int i = 1;
    int userInput = 0;

    i = 4000000000;
    printf("%u\n", i);

    i = -1;
    printf("%u\n", i);

    i = 4000000000;
    printf("%u\n", i);


    scanf("%d", &userInput);

    char q = (char)userInput;
    printf("%c\n", q);
}