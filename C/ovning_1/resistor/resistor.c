#include <stdio.h>

int main(void) {
    printf("Det här programmet räknar ut ersättningsresistans.\n");

    int r1 = 0;
    int r2 = 0;
    int new_r = 0;

    printf("Skriv in värdet på första resistansen: ");
    scanf("%d", &r1);

    printf("Skriv in värdet på andra resistansen: ");
    scanf("%d", &r2);

    new_r = (r1*r2)/(r1+r2);
    printf("Ersättningsresistansen för %d och %d är %d", r1, r2, new_r);

    
    return 0;
}