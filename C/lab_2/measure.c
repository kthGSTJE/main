#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define VALUES 10

void ViewValues(int values[], int lastVal);
void EnterValue(int values[], int *pLastVal);
void Compute(int values[], int lastVal);
void ResetValues(int values[], int *pLastVal);
int GetMax(int values[], int lastVal);
int GetMin(int values[], int lastVal);
float GetAverage(int values[], int lastVal);
void PrintNormalized(int values[], int lastVal);

int main (void){

    char input = '*';
    int measurements[VALUES] = {0};
    int latestValue = -1;

    printf("\nMEASUREMENT TOOL\n\n");
    printf("Available commands: (e)Enter, (v)View,\n");
    printf("(c)Compute, (r)Reset, (q)Quit\n");
    //command prompt
    do
    {
        printf("Input command: ");
        scanf(" %c", &input);
        switch (input)
        {
        case 'v':
            ViewValues(measurements, latestValue);
            break;

        case 'e':
            EnterValue(measurements, &latestValue);
            break;

        case 'c':
            Compute(measurements, latestValue);
            break;

        case 'r':
            ResetValues(measurements, &latestValue);
            break;

        case 'q':
            printf("QUIT\n\n");
            printf("You have quit\n\n");
            break;
        
        default:
            printf("Not a valid command\n\n");
            break;
        }
    } while (input!='q');
}

//prints out values in the measurement array if any have been entered
void ViewValues(int values[], int lastVal){
    printf("VIEW\n\n");
    if (lastVal<0){
        printf("No values in data array\n\n");
    }
    else {
        printf("[ ");
        for (int i = 0; i <= lastVal; i++)
        {
            printf(" %2d ", values[i]);
        }
        printf(" ]\n\n");
    }
}
//allows user to enter up to 10 values into the measurement array
void EnterValue(int values[],int *pLastVal){
    printf("ENTER (0 to exit)\n\n");
    int input = -1;
    //scan loop for measurements
    while (input && *pLastVal<9)
    {
        printf("Enter measurement #%d: ", *pLastVal+2);
        scanf("%d", &input);
        if (input)
        {
            *pLastVal += 1;
            values[*pLastVal] = input; 
        }
    }
    //max val check
    if (*pLastVal>8)
    {
        printf("WARNING: Maximum amount of values reached\n");
    }
    printf("\n"); 
}
//prints out highest, lowest, average and normalized values in measurement array if possible
void Compute(int values[], int lastVal){
    printf("COMPUTE\n\n");
    if (lastVal<0)
    {
        printf("No values in data array\n");
    }
    else{
        printf("Maximum value: %d\n", GetMax(values, lastVal));
        printf("Minimum value: %d\n", GetMin(values, lastVal));
        printf("Average: %.2f\n", GetAverage(values, lastVal));
        printf("Normalized values: \n");
        PrintNormalized(values, lastVal);
    }
}
//resets measurement array and restores the counter to start value
void ResetValues(int values[], int *pLastVal){
    printf("RESET\n\n");
    for (int i = 0; i <= *pLastVal; i++)
    {
        values[i]=0;
    }
    //reset counter
    *pLastVal = -1;
    printf("Measurements have been reset!\n\n");
}
//presents the max value in array
int GetMax(int values[], int lastVal){
    int max = 0;
    for (int i = 0; i <= lastVal; i++)
    {
        if (!i)
        {
            max=values[i];
        }
        if (values[i]>max)
        {
             max=values[i];
        }
    }
    return max;
    
}
//presents the min value in array
int GetMin(int values[], int lastVal){
    int min = 0;
    for (int i = 0; i <= lastVal; i++)
    {
        if (!i)
        {
            min=values[i];
        }
        if (values[i]<min)
        {
            min=values[i];
        }
    }
    return min;

}
//calculates average of ints in array
float GetAverage(int values[], int lastVal){
    int total = 0;
    for (int i = 0; i <= lastVal; i++)
    {
        total += values[i];
    }
    return (float)total/(lastVal+1);

}
//prints out normalized values of array
void PrintNormalized(int values[], int lastVal){
    int tempNorm = 0;
    printf("[ ");
    for (int i = 0; i <= lastVal; i++)
        {
        tempNorm = (int)values[i]-GetAverage(values, lastVal);
        printf(" %d ", tempNorm);
    }
    printf(" ]\n\n");
}