#include <stdio.h>

int main (void){
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    printf("Skriv in ditt första bråktal(a/b): ");
    scanf("%d/%d", &a, &b);

    printf("Skriv in ditt andra bråktal(a/b): ");
    scanf("%d/%d", &c, &d);

    printf("Ditt nya bråktal är: %d/%d", a*c, b*d);

}