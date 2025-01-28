#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ALPHABET 26
#define SENTENCE 200

void PrintResult(int meningen[], int bokstaverna[], int sizemMening, int sizeLetters);

int main (void) {
    char mening[SENTENCE] = {'*'};
    int letters[ALPHABET] = {0};
    char input = '*';
    int lettersUsed = -1;
    int currentLetter = 0;
    int mostFreqLetter = 0;

    //läs in mening i array
    printf("Enter a sentence: \n");
    do
    {
        scanf("%c", &input);
        if (input>='A' && input<='Z')
        {
            lettersUsed++;
            mening[lettersUsed] = input;
        }
    } while (input!='\n');
    //gå igenom array indexvis
    //om bokstav A-Z öka bokstavens index i letters med 1
    for (int i = 0; i <= lettersUsed; i++)
    {
        currentLetter = mening[i]-'A';
        letters[currentLetter]++;
    }

    //skriv ut letters
    for (int i = 0; i < ALPHABET; i++)
    {
        printf("%c ", i+'A');

    }
    printf("\n");
    for (int i = 0; i < ALPHABET; i++)
    {
        printf("%d ", letters[i]);
        //ta reda på högsta tal i letters
        if (mostFreqLetter<letters[i])
        {
            mostFreqLetter = i;
        }
    }
    printf("\nMost frequent letter %c, Used %d times", mostFreqLetter+'A', letters[mostFreqLetter]);

}