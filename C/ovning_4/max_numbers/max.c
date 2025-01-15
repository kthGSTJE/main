#include<stdio.h>

int main(void){
    int largestNumber = 0;
    int inputNumber = 0;

    do
    {
        printf("Skriv in ett tal: ");
        scanf("%d", &inputNumber);
        
        if (inputNumber>largestNumber){
            largestNumber = inputNumber;
        }
        
    } while (inputNumber!=0);
    printf("Ditt största tal sin du matade in var: %d", largestNumber);
    
}