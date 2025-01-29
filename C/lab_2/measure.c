#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ViewValues();
void EnterValue();
void Compute();
void ResetValues();

int main (void){

    char input = '*';

    do
    {
        printf("Input command: ");
        scanf(" %c", &input);
        switch (input)
        {
        case 'v':
            ViewValues();
            break;
        case 'e':
            EnterValue();
            break;
        case 'c':
            Compute();
            break;
        case 'r':
            ResetValues();
            break;
        case 'q':
            break;
        
        default:
            printf("Not a valid command\n");
            break;
        }
    } while (input!='q');
    

}


void ViewValues(){
    printf("View not finished\n");
}
void EnterValue(){
    printf("Enter not finished\n");
}
void Compute(){
    printf("Compute not finished\n");
}
void ResetValues(){
    printf("Reset not finished\n");
}