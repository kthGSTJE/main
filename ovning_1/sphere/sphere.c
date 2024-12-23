#include <stdio.h>
#define PI 3.14159f

int main (void){

    printf("Volymen för en sfär med radien 10\n");
    float radius = 10.0;
    float sphere_volume = 0.0;

    sphere_volume = (4.0/3.0)*PI*radius*radius*radius;

    printf("Volymen är: %f\n", sphere_volume);
    printf("Färdigt.");

}