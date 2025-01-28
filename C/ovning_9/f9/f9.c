#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 6
int RandomNumber(int num);
void InitializeRandom(void);
void ViewFreqTable(int freqTabell[], int size);
void FillTable(int fillTable[], int size, int amount);
void ResetTable(int resetTable[], int size);

int main (void) {
    int input = 0;
    int freq[SIZE] = {0};
    int falsent = 0;
    int attempts = 0;
    InitializeRandom();

    printf("How many attempts: ");
    scanf("%d", &input);

    FillTable(freq, SIZE, input);
    ViewFreqTable(freq, SIZE);
    
}

int RandomNumber(int num){
    return rand()%num;
}
void InitializeRandom(void){
    srand((unsigned) time(NULL));

}
void ViewFreqTable(int freqTabell[], int size){
    printf(" x : n\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%2d : %d\n", i+1, freqTabell[i]);
    }
    
}
void FillTable(int fillTable[], int size, int amount){
    int temp = 0;
    for (int i = 0; i < amount; i++)
    {
        temp = RandomNumber(SIZE);
        fillTable[temp]++;
    }
}
void ResetTable(int resetTable[], int size){
    for (int i = 0; i < size; i++)
    {
        resetTable[i] = 0;
    }
    
}