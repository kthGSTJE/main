#include<stdio.h>

int main (void){
    char input = '*';
    printf("Input your 1-800 number: ");

    do
    {
        scanf("%c", &input);
        if (input>='A' && input<='R'){
            printf("%c", '2'+((input-'A')/3));
        }
        else if (input>='S' && input<='Y'){
            printf("%c", '2'+((input-1-'A')/3));
        }
        else if (input == 'Z'){
            printf("%c", '2'+((input-2-'A')/3));
        }
        else{
            printf("%c", input);
        }
    
    } while (input!='\n');
    
}