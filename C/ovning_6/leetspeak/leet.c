#include<stdio.h>
#define SIZE 20

int main (void){

    char input[SIZE] = {0};
    char letter = '*';
    
    do
    {
        scanf("%c", &letter);
        if (letter >= 'a')
        {
            letter = letter -'a'+'A';
        }
        switch (letter)
        {
        case 'A':
            letter = '4';
            break;
        case 'B':
            letter = '8';
            break;
        case 'E':
            letter = '3';
            break;
        case 'I':
            letter = '1';
            break;
        case 'O':
            letter = '0';
            break;
        case 'S':
            letter = '5';
            break;
        
        default:
            break;
        }
        printf("%c", letter);
    } while (letter!='\n');
    

}