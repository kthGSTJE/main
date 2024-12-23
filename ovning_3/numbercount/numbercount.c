#include <stdio.h>

int main (void){
    int inputNumber = 0;
    int numberCounter = 0;
    int test = 0;
    

    while (inputNumber!=5959)
    {
        printf("Skriv in ett tal mellan 0-999: ");
        scanf("%d", &inputNumber);
        test = inputNumber;

        while (test>9)
        {
            test= test/10;
            numberCounter++;
        }
        
        
        
        
        printf("%d", numberCounter);
    }
     
}