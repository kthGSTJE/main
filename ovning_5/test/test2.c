#include<stdio.h>

int main (void){
    char bokstav = '*';
    int amount = 0;

    do
    {
        scanf("%c", &bokstav);
        amount++;
    } while (bokstav!='\n');
    printf("%d letters", amount-1);
    

    //printf("%c", bokstav-'A'+'a');
}