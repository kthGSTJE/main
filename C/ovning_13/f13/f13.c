#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct
    {
        char id[7];
        char type[30];
        int year[3];
        char color[10];
    } Car;

void printCar (Car *pCar);

int main (void){
    srand((unsigned) time(NULL));

    Car nyVolvo = {"WOU039", "MAZDA", {1,2,3}, "RED"};
    printCar(&nyVolvo);
    printCar(&nyVolvo);
    
    strcpy(nyVolvo.id, "NNN666");
    strcpy(nyVolvo.type, "Volvo");
    nyVolvo.year[0] = 4;
    nyVolvo.year[1] = 5;
    nyVolvo.year[2] = 6;
    strcpy(nyVolvo.color, "Blue");

    printCar(&nyVolvo);


}

void printCar (Car *pCar){
    printf("%s\n", pCar->id);
    printf("%s\n", pCar->type);
    printf("%d\n", pCar->year[0]);
    printf("%d\n", pCar->year[1]);
    printf("%d\n", pCar->year[2]);
    printf("%s\n", pCar->color);
}