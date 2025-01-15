#include<stdio.h>

int main(void){
    int inputNumber[4];
    int temp = 0;
    int unsorted = 1;

    printf("Skriv in 4 tal separerade med mellanslag: ");
    scanf("%d %d %d %d", inputNumber[0], inputNumber[1], inputNumber[2], inputNumber[3]);
    
    while (unsorted)
    {
        unsorted=0;
        for (int i = 1; i < sizeof(inputNumber); i++)
        {
            if (inputNumber[i]<inputNumber[i-1] )
            {
                temp = inputNumber[i];
                inputNumber[i] = inputNumber[i-1];
                inputNumber[i-1] = temp;
                unsorted++;
            }          
        }
        
    }
    for (int j = 0; j < sizeof(inputNumber); j++)
    {
        printf("%d ", inputNumber[j]);
    }
    
    
    


}