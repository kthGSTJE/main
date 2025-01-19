#include<stdio.h>
#define DIGITS 10

int main (void){

    //array[10]
    int freq[DIGITS] = {0};
    char num = '*';

    //läs in "ord" med siffror
    printf("Enter a number: ");
    do
    {
        scanf("%c", &num);
        //kovertera varje tecken till int
        int temp = (int)(num-'0');
        //ta array[int]++
        freq[temp]++;
    } while (num!='\n');
    
    for (int i = 0; i < DIGITS; i++)
    {
        printf("%d: %d\n", i, freq[i]);
    }
    
    
}