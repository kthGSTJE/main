#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define METER 1000;

int main (void) {
    int diameter = 0;
    int length = 0;
    int numberOfTurns = 0;

    float newDiam = 0.0;
    float newLength = 0.0;

    float ans = 0.0;
    int inputChoice = -1;

    do
    {
        printf("Enter diameter in mm: ");
        scanf("%d", &diameter);

        printf("Enter length in mm: ");
        scanf("%d", &length);

        printf("Number of turns: ");
        scanf("%d", &numberOfTurns);
        
        newDiam = (float)diameter/METER;
        newLength = (float)length/METER;

        ans = newDiam*newDiam*numberOfTurns*numberOfTurns/(newLength+0.45*newDiam);

        printf("%.2f uH\n", ans);
        
        printf("Another calc? :");
        scanf("%d", &inputChoice);
    } while (inputChoice);
    


}