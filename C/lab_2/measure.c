#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void){

    char input = '*';

    do
    {
        printf("Input command: ");
        scanf(" %c", &input);
        switch (input)
        {
        case 'h':
            
            break;
        
        default:
            printf("Not a valid command\n");
            break;
        }
    } while (input!='q');
    

}