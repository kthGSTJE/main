#include <stdio.h>

int main (void){
    int antalBen = 0;
    
    printf("Skriv in antal ben: ");
    scanf("%d", &antalBen);

    printf("Mammal: %d\n", antalBen<5);
    printf("Insect: %d\n", antalBen>4 && antalBen<8);
    printf("Spider: %d\n", antalBen==8);
    printf("Creepy: %d\n", antalBen>8);

    return 0;
}