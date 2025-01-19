#include<stdio.h>
#define WORDSIZE 20

int main (void) {
    char word[WORDSIZE];

    int wordLength = 0;

    printf("Enter a word: ");
    do{
        scanf("%c", &word[wordLength]);
        wordLength++;

    }while (word[wordLength]!= '\n');
    

    for (int i = 0; i < WORDSIZE; i++)
    {
        printf("%c", word[i]);
    }
    

}