#include<stdio.h>

int main (void){
    int input = 0;

    scanf("%d", &input);
    for (int i = 1; i <= input; i++)
    {
        printf("%-3d Abracadabra\n",i);
    }
    
}