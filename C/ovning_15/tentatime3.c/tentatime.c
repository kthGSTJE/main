#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define NAMELENGTH 20+1

typedef struct 
{
    float x;
    float y;
    char name[NAMELENGTH];
} Person;

float calculateDistance (Person person1, Person person2);

int main (void){
    float distance = 0;
    Person anna = {1, 3, "Anna"};
    Person evin = {4, 7, "Evin"};

    distance  = calculateDistance(anna, evin);

    printf("Avståndet mellan personerna är %.2f", distance);

}


float calculateDistance (Person person1, Person person2){
    float distance = 0;
    distance = sqrt((person2.x-person1.x)*(person2.x-person1.x)+(person2.y-person1.y)*(person2.y-person1.y));

    return distance;

}