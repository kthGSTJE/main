#include<stdio.h>

int main (void){
    char input = '*';
    char firstNameLetter = '*';


    printf("Please input your first and last name: ");
    scanf("%c", &firstNameLetter);


    do
    {
        scanf("%c", &input);

    } while (input!=' ');
    do
    {
        scanf("%c", &input);
        if (input == '\n')
        {
            printf(", %c.", firstNameLetter);
        }
        else{
            printf("%c", input);
        }
    } while (input!='\n');
}