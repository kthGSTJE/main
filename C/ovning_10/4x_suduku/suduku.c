#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 4

void PrintBoard(int theBoard[SIZE][SIZE]);
void EnterPos(int theBoard[SIZE][SIZE]);

int main (void) {
    int board[SIZE][SIZE] = {{1,1,1,-1},
                             {-2,2,-2,2},
                             {3,-3,3,-3},
                             {4,4,-4,4}};
    char input = '*';

    do
    {
        printf("Command: ");
        scanf(" %c", &input);

        switch (input)
        {
        case 'v':
            PrintBoard(board);;
            break;
        case 'e':
            EnterPos(board);
            break;
        
        default:
            break;
        }
    } while (input!='q');
    
}

void PrintBoard(int theBoard[SIZE][SIZE]){
    printf(" ");
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %c", i+'a');
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++)
        {
            if (theBoard[i][j]>0)
            {
                printf("%d ", theBoard[i][j]);
            }
            else{
                printf("* ");
            }
        }
        printf("\n");
    }
}
void EnterPos(int theBoard[SIZE][SIZE]){
    char inputX = 'e';
    char inputY = 'e';

    printf("Input cordinates: ");
    scanf(" %c", &inputX);
    scanf("%c", &inputY);


    printf("%c %c\n", inputX, inputY);


}