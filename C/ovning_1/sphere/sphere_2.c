#include <stdio.h>
#define PI 3.14159f

int main (void){

    printf("Volymen för en sfär med bestämd radie\n");
    float radius = 0.0;
    float sphere_volume = 0.0;

    printf("Sfärens radie: ");
    scanf("%f", &radius);

    sphere_volume = (4.0/3.0)*PI*radius*radius*radius;

    printf("Volymen är för sfären med radien %f: %f\n", radius, sphere_volume);
    printf("Färdigt.");

}