#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define WORDLENGTH 14+1
#define MAXGUESSES 12

int main (void){
    char word[WORDLENGTH] = "midsommarafton";
    char status[WORDLENGTH] = {0};
    int guesses = 0;
    char inputs[MAXGUESSES];

    do
    {
        for (int i = 0; i < strlen(word); i++)
        {
            status[i] = '*';
        }
        printf("%s %5d", status, guesses);
        printf("   Gissa en bokstav: ");
        scanf(" %c", &inputs[guesses]);
        if (inputs[guesses]<'a')
        {
            inputs[guesses]= inputs[guesses]-'A'+'a';
        }
        if (inputs[guesses]<='z' && inputs[guesses]>='a')
        {
            for (int i = 0; inputs[i]!= '\0'; i++)
            {
                /* code */
            }
            
            
            guesses++;
        }


    } while (guesses<=MAXGUESSES );
    
    
    

}