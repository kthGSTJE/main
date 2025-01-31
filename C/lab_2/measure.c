#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define VALUES 10

void ViewValues(int values[], int *pLastVal);
void EnterValue(int values[], int *pLastVal);
void Compute(int values[], int *pLastVal);
void ResetValues(int values[], int *pLastVal);

int main (void){

    char input = '*';
    int measurements[VALUES] = {0};
    int latestValue = -1;
    
    //command prompt
    do
    {
        printf("Input command: ");
        scanf(" %c", &input);
        switch (input)
        {
        case 'v':
            ViewValues(measurements, &latestValue);
            break;
        case 'e':
            EnterValue(measurements, &latestValue);
            break;
        case 'c':
            Compute(measurements, &latestValue);
            break;
        case 'r':
            ResetValues(measurements, &latestValue);
            break;
        case 'q':
            break;
        
        default:
            printf("Not a valid command\n");
            break;
        }
    } while (input!='q');

}

//prints out values in the measurement array if any have been entered
void ViewValues(int values[], int *pLastVal){
    if (*pLastVal>-1)
    {
        printf("[ ");
        for (int i = 0; i <= *pLastVal; i++)
        {
            printf(" %2d ", values[i]);
        }
        printf(" ]\n");
    }
    else{
        printf("No values in data array\n");
    }
    
}
//allows user to enter up to 10 values into the measurement array
void EnterValue(int values[],int *pLastVal){
    int input = -1;
    //scan loop for measurements
    while (input && *pLastVal<9)
    {
        printf("Enter measurement #%d: ", *pLastVal+2);
        scanf("%d", &input);
        if (input)
        {
            *pLastVal = *pLastVal+1;
            values[*pLastVal] = input; 
        }
    }
    //max val check
    if (*pLastVal>8)
    {
        printf("WARNING: Maximum values reached\n");
    }
    
    
}
//WIP prints out highest, lowest, average and normalized values in measurement array
void Compute(int values[], int *pLastVal){
    printf("Compute not finished\n");
}
//resets measurement array and restores the counter to start value
void ResetValues(int values[], int *pLastVal){
    printf("Measurements have been reset!\n");
    //Reset array
    for (int i = 0; i < *pLastVal; i++)
    {
        values[i]=0;
    }
    //reset counter
    *pLastVal = -1;
    
}