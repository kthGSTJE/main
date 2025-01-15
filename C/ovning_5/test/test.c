#include<stdio.h>
#define RANKS 13
#define SUITS 4

int main(void) {

    for (int suit = 0; suit < SUITS; suit++)
    {
        for (int value = 0; value < RANKS; value++)
        {
            switch (value)
            {
            case 0:
                printf("[A ");
                break;
            case 9:
                printf("[T ");
                break;
            case 10:
                printf("[J ");
                break;
            case 11:
                printf("[Q ");
                break;
            case 12:
                printf("[K ");
                break;
            
            default:
                printf("[%d ", value+1);
                break;
            }
            switch (suit)
            {
            case 0:
                printf("of Clubs]\n");
                break;
            case 1:
                printf("of Diamonds]\n");
                break;
            case 2:
                printf("of Hearts]\n");
                break;
            case 3:
                printf("of Spades]\n");
                break;
            
            default:
                break;
            }
        }
        printf("\n");
        
    }
   
}