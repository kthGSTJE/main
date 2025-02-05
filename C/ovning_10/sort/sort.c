#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void SortArray(int array[], int size);
void PrintArray(int array[], int size);

int main (void){

    int someNumbers[SIZE] = {2, 5, 1, 15, 3, 97, 64, 9, 8, 22};

    PrintArray(someNumbers, SIZE);
    SortArray(someNumbers, SIZE);
    PrintArray(someNumbers, SIZE);
}

void SortArray(int array[], int size){
    int temp = -3000;
    int unsorted = 0;

    for (int i = 1; i < size; i++)
    {
        if (array[i]<array[i-1])
        {
            temp = array[i];
            array[i] = array[i-1];
            array[i-1] = temp;
            unsorted = 1;
        }
        
    }
    if (unsorted)
    {
        SortArray(array, size);
    }
}
void PrintArray(int array[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
}