#include<stdio.h>
#define WORDSIZE 20

int main (void) {
    char word[WORDSIZE] = {'*','*','*','*','*','*','*','*','*','*','*','*'};
    char reverseWord[WORDSIZE] = {'*','*','*','*','*','*','*','*','*','*','*','*'};

    int wordLength = -1;
    int temp = 0;

    //Läs in ett ord i en array
    printf("Enter a word: ");
    do{
        wordLength++;
        scanf("%c", &word[wordLength]);
        //Enbart stora bokstäver
        if (word[wordLength]>'Z')
        {
            word[wordLength]= word[wordLength]-'a'+'A';
        }
    }while (word[wordLength]!= '\n');

    //Skriv ut ordet och samtidigt spara ordet baklänges i en annan array
    for (int i = 0; i < WORDSIZE; i++)
    {
        reverseWord[wordLength] = word[i];
        printf("%c", word[i]);
        wordLength--;
    }

    //Skriv ut ordet baklänges
    for (int i = 0; i < WORDSIZE; i++)
    {
        printf("%c", reverseWord[i]);
    }

    //Sista check
    printf("\n");
    if (1)
    {
        printf("Inte palindrom");
    }
    else{
        printf("Palindrom");
    }
}