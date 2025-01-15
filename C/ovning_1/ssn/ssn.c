#include <stdio.h>


int main(void){
    int yr = 0;
    int mnth = 0;
    int day = 0;

    printf("Skriv in födelsedatum YY.MM.DD: ");
    scanf("%d.%d.%d", &yr, &mnth, &day);
    
    printf("Year: %02d\n", yr);
    printf("Month: %02d\n", mnth);
    printf("Day: %02d\n", day);

    return 0;
}