#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define STRINGSIZE 40
#define TEAMS 6

int main (void){
    char msg[] = "Hej jag heter Gustav";
    char cup[TEAMS][STRINGSIZE] = {"RED", "BLUE", "GREEN", "YELLOW", "MAGENTA", "ORANGE"};
    char firstString[STRINGSIZE];
    char secondString[STRINGSIZE];

    printf("%s\n", msg);

    scanf("%s%s", firstString, secondString);
    printf("%s %s", secondString, firstString);
    int antal = strlen(firstString);
    printf("%d", antal);
    printf("\nTEAMS \n");
    for (int i = 0; i < TEAMS; i++)
    {
        printf("%s\n", cup[i]);
    }
    

}