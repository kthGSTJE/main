#include <stdio.h>

int main (void){
    int suitOfCard = 0;
    scanf("%d", &suitOfCard);

    switch (suitOfCard)
    {
        case 0:
            printf("Diamonds\n");
            break;
        case 1:
            printf("Clubs\n");
            break;
        case 2:
            printf("Spades\n");
            break;
        case 3:
            printf("Hearts\n");
            break;
        default:
            printf("What the fuck did you just say to me you little bitch?");
            break;
    }
}