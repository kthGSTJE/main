#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define HEIGHT 5
#define WIDTH 5
#define BOMBS 7

int main (void){

    char matrix[HEIGHT][WIDTH];
    srand((unsigned) time(NULL));

    char decending  = 'A';
    char across = '1';
    char inputLetter = '*';
    char inputNumber = '*';

    //skriv ut index för bredd
    printf("  ");
    for (int a = 0; a < WIDTH; a++)
    {
        printf("%c ", across+a);
    }
    printf("\n");

    //Rutnät
    for (int i = 0; i < HEIGHT; i++)
    {
        //bokstavs index för höjd
        printf("%c ", decending+i);
        for (int j = 0; j < WIDTH; j++)
        {
            int temp = rand()%10;
            if (temp!= 9)
            {
                matrix[i][j] = '0';
            }
            else{
                matrix[i][j] = '9';
            }
            printf("* ");
        }
        printf("\n");
    }
    printf("Tile to press (eg. E3): ");
    
    scanf("%c", &inputLetter);
    scanf("%c", &inputNumber);
    printf("%c.%c", inputLetter, inputNumber);
}