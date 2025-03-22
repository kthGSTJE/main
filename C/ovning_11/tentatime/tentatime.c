#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIDES 6

int RandomNumber(int num);
void InitializeRandom(void);
void ThrowDice(int amount, int size, int *pRollSum);

int main (void){
    int alive = 1;
    int lastRoll = 0;
    int rollSum = 0;
    int input = -1;
    int score = 0;
    InitializeRandom();

    do
    {
        printf("Hur många tärningar 1-10: ");
        scanf("%d", &input);
        rollSum = 0;
        if (input>0 && input<=10)
        {
            ThrowDice(input, SIDES, &rollSum);
            if (rollSum>lastRoll)
            {
                lastRoll = rollSum;
                printf(". Bravo!\n");
                score++;
            }
            else{
                alive= 0;
                printf(". Du suger!\n");
            }
        }
        else{
            printf("Felaktig indata\n");
        }
    } while (alive && input!=99);
    printf("Score: %d", score);
}

int RandomNumber(int num){
    return rand()%num;
}
void InitializeRandom(void){
    srand((unsigned) time(NULL));
}
void ThrowDice(int amount, int size, int *pRollSum){
    int rollVal;
    printf("Du fick: ");
    for (int i = 0; i < amount; i++)
    {
        rollVal = RandomNumber(size)+1;
        printf(" %d,", rollVal);
        *pRollSum += rollVal;

    }
    printf(" och summan %d", *pRollSum);
}