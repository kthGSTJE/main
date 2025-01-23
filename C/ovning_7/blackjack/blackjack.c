#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DECKVALUES 13
#define DECKSUITS 4
#define DECKSIZE 52
#define FACE 10
#define BUST 22
#define STAND 17

void InitializeRandom(void);
void ShowRandomCard(void);
int RandomNumber(int num);
int GetRank(int aCard);
void PrintCard(int aCard);

int main (void) {

    int currentCard = -1;
    int yourSum = 0;
    int dealerSum = 0;
    char choice = '*';

    InitializeRandom();

    printf("Blackjack Game\n");

    //förfrågning av stand/hit i loop
    do
    {
        printf("Stand or hit? (s/h): ");
        scanf("%c", &choice);
        if (choice == 'h')
        {
            //skriv ut kortet och summan av din poäng
            currentCard = RandomNumber(DECKSIZE);
            PrintCard(currentCard);
            yourSum = yourSum + GetRank(currentCard);
            printf("Your score: %d\n", yourSum);
        }
        //slumpa random kort tills stand väljs eller över 21
    } while (choice!='s' && yourSum<BUST);


    //dealern drar sitt tills 17 eller över eller bust
    printf("Dealers turn. Stands on 17 or higher\n");
    do
    {
        currentCard = RandomNumber(DECKSIZE);
        PrintCard(currentCard);
        dealerSum = dealerSum + GetRank(currentCard);
        printf("Dealer score: %d\n", dealerSum); 
        printf("Your score: %d\n", yourSum);   
    } while (dealerSum<=STAND || dealerSum<yourSum && yourSum<BUST);
    
    //jämför med dealern och bust finale
    if (yourSum>dealerSum)
    {
        if (dealerSum>=BUST)
        {
            printf("Draw\n");
        }
        else if(yourSum<BUST){
            printf("You Win!\n");
        }
        else{
            printf("The house wins\n");
        }
    }
    else if (yourSum<dealerSum)
    {  
        if (yourSum>=BUST)
        {
            printf("Draw\n");
        }
        else if(dealerSum<BUST){
            printf("The house wins\n");
        }
        else{
            printf("You win\n");
        }
        
    }
    else{
        printf("Draw final\n");
    }
    

    

}
/*int deck[DECKSUITS][DECKVALUES];
    for (int i = 0; i < DECKSIZE; i++)
    {
        deck[i/DECKVALUES][i%DECKVALUES] = i;
    }
*/

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