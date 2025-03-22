#include <stdio.h>
#define WORD 20

int main (void){
    char input = '*';
    int lastVal = 0;
    int palindromBool = 1;

    printf("Hello World!\n");
    char word[WORD] = "";

    do
    {
        scanf("%c", &input);
        if (input!= '\n')
        {
            word[lastVal] = input;
            lastVal++;
        }
        
    } while (input!= '\n');
    
    for (int i = 0; i < lastVal; i++)
    {
        printf("%c, %c\n", word[i], word[lastVal-i-1]);
        if (word[i] != word[lastVal-i-1])
        {
            palindromBool=0;
        }
        
        
    }
    printf("%d", palindromBool);
    
}