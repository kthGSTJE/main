#include <stdio.h>

int main (void){

    printf("Räkna om km/h till meter/s och miles/h\n");

    float kmh = 0.0;
    float mps = 0.0;
    float milesph = 0.0;

    printf("Skriv in hastighet i km/h:");
    scanf("%f", &kmh);

    mps = kmh/3.6;
    milesph = kmh*0.6;

    printf("%f km/h motsvarar %f m/s eller %f miles/h\n", kmh, mps, milesph);
    printf("klart!");

}