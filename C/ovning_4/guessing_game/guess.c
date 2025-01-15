#include<stdio.h>

int main(void){
    int number = 7;
    int guess = 0;
    int angerCounter = 0;

    printf("Jag tänker på ett tal mellan 0-10\n");
    do
    {
        if (angerCounter<5){
            printf("Kom igen du har det här!\n");
        }
        else if (angerCounter<10){
            printf("Skärp dig!\n");
        }
        else {
            printf("Är du helt retarded eller?\n");
        }
        printf("Gissa på ett tal: ");
        scanf("%d", &guess);

        if(guess < number){
            printf("Högre\n");
        }
        else if (guess > number){
            printf("Lägre\n");
        }
        angerCounter++;
    } while (guess!=number);

    printf("Rätt svar!");
    
}