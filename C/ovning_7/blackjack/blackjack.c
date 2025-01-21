#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DECKVALUES 13
#define DECKSUITS 4
#define DECKSIZE 52
#define FACE 10

void InitializeRandom(void);
void ShowRandomCard(void);
int RandomNumber(int num);
int GetRank(int aCard);
void PrintCard(int aCard);
//hej alfred
//hej hej

int main (void) {

    int currentCard = -1;
    InitializeRandom();
    /*int deck[DECKSUITS][DECKVALUES];
    for (int i = 0; i < DECKSIZE; i++)
    {
        deck[i/DECKVALUES][i%DECKVALUES] = i;
    }
    */
    for (int i = 0; i < 5; i++)
    {
        currentCard = RandomNumber(DECKSIZE);
        PrintCard(currentCard);
        printf("%d", GetRank(currentCard));
    }
    
    ShowRandomCard();

}

void PrintCard(int aCard){
    int suit = aCard/DECKVALUES;
    int value = aCard%DECKVALUES;

    switch (value)
    {
    case 0:
        printf("A of ");
        break;
    case 10:
        printf("J of ");
        break;
    case 11:
        printf("Q of ");
        break;
    case 12:
        printf("K of ");
        break;
    
    default:
        printf("%d of ", value+1);
        break;
    }
    switch (suit)
    {
    case 0:
        printf("Clubs\n");
        break;
    case 1:
        printf("Diamonds\n");
        break;
    case 2:
        printf("Spades\n");
        break;
    case 3:
        printf("Hearts\n");
        break;
    default:
        break;
    }
}
int GetRank(int aCard){
    if (aCard%DECKVALUES>=FACE)
    {
        return FACE;
    }
    else{
        return aCard%DECKVALUES+1;
    }
    
}
int RandomNumber(int num){
    return rand()%num;
}
void InitializeRandom(void){
    srand((unsigned) time(NULL));

}
void ShowRandomCard(void){
    int card = RandomNumber(DECKSIZE);
    int suit = card/DECKVALUES;
    int value = card%DECKVALUES;

    switch (value)
    {
    case 0:
        printf("A of ");
        break;
    case 10:
        printf("J of ");
        break;
    case 11:
        printf("Q of ");
        break;
    case 12:
        printf("K of ");
        break;
    
    default:
        printf("%d of ", value+1);
        break;
    }
    switch (suit)
    {
    case 0:
        printf("Clubs\n");
        break;
    case 1:
        printf("Diamonds\n");
        break;
    case 2:
        printf("Spades\n");
        break;
    case 3:
        printf("Hearts\n");
        break;
    default:
        break;
    }
    

}