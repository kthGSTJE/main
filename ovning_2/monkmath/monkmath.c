#include <stdio.h>

int main(void){
    int inmatadeTal[16];
    int i = 0;

    printf("Skriv in 16 stycken tal separerade med mellanslag: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &inmatadeTal[0], &inmatadeTal[1], &inmatadeTal[2], &inmatadeTal[3], &inmatadeTal[4], &inmatadeTal[5], &inmatadeTal[6], &inmatadeTal[7], &inmatadeTal[8], &inmatadeTal[9], &inmatadeTal[10], &inmatadeTal[11], &inmatadeTal[12], &inmatadeTal[13], &inmatadeTal[14], &inmatadeTal[15]);

    for (int i = 0; i < 16; i++)
    {
        printf("%d ", inmatadeTal[i]);
        if (i%4 == 0 && i!=0)
        {
            printf("\n");
        }
        
        
    }
    
}