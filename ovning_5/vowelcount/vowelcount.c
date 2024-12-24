#include<stdio.h>

int main (void) {
    char input = '*';
    int counter = 0;

    do
    {
        scanf("%c", &input);
        if (input>'Z')
        {
            input = input-'a'+'A';
        }
        
        switch (input)
        {
        case 'A':
        case 'E':
        case 'I': 
        case 'O': 
        case 'U': 

            counter++;
            break;
        
        default:
            break;
        }
        
    } while (input!='\n');

    printf("%d", counter);
    
}