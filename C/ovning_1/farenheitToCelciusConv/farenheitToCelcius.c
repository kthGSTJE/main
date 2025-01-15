#include <stdio.h>

int main(void) {
    printf("Konverterar farenheit till celcius\n");
    float farenheit = 0.0;
    float celcius = 0.0;

    printf("Skriv in gradantal i farenheit: ");
    scanf("%f", &farenheit);

    celcius = (farenheit-32.0)*(5.0/9.0);

    printf("%-0.1f grader farenheit motsvarar %-0.1f grader celcius\n", farenheit, celcius);

    printf("Klart!");

}