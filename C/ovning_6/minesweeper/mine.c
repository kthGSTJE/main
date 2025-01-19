#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define HEIGHT 10
#define WIDTH 9

int main (void){

    int matrix[HEIGHT][WIDTH];
    srand((unsigned) time(NULL));
    char decending  = 'A';
    char across = '1';
    char input = '*';

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
            if (temp== 9)
            {
                matrix[i][j] = 9;
            }
            else{
                matrix[i][j] = 0;
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Tile to press (eg. E3): ");
    
    scanf("%c", &input);


}