#include <stdio.h>
#define MIN 40
#define MAX 80

int main (void){
    int beat = 50;
    int alarm = 0;

    
    while (beat)
    {
        printf("Skriv in puls: ");
        scanf("%d", &beat);
        if (beat<=MIN || beat>=MAX){
            alarm = 1;
            printf("DU HÅLLER PÅ ATT DÖ\n");
            if (beat<=MIN) {
                printf("puls under 40\n");
            }
            else{
                printf("puls över 80\n");
            }
        }
        else {
            printf("Det är lungt\n");
        }
    }
    printf("Du är död. Hejdå!");
    
    
    

}