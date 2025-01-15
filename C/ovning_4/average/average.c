#include<stdio.h>

int main(void){
    int totalSum = 0;
    int inputNumber = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Skriv in tal %d: ", i+1);
        scanf("%d", &inputNumber);
        totalSum = totalSum+inputNumber;
    }
    
    totalSum= totalSum/5;
    printf("Medelvärdet är: %d", totalSum);
        
}