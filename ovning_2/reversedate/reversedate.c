#include <stdio.h>

int main (void){
    int day = 00;
    int month = 00;
    int year = 0000;

    printf("Skriv in datum på formen MM/DD/YYYY: ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("%02d%02d%02d är det konverterade datumet", year, month, day);

    return 0;
}