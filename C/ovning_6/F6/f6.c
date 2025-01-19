#include<stdio.h>
#define SIZE 4

int main (void) {
    int i[SIZE] = {1, 2 ,3, 0};

    printf("%u\n", SIZE);

    for (int j = 0; j < SIZE; j++)
    {
        printf("%d\n", i[j]);
    }
    
    i[3] = 4;

    for (unsigned int j = 0; j < SIZE; j++)
    {
        printf("%d\n", i[j]);
    }

}