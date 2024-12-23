#include <stdio.h>

int main (void) {
    int age = 25;
    printf("Vem är jag?\n");
    printf("Gustav Stjernlöf\n");

    printf("Ålder: %d\n", age);
    printf("Variabeln för ålder sparas i minneslåda %p\n", age);

    printf("Klart");
    return 0;
}