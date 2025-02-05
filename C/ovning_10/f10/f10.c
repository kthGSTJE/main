#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void SplitTime(int *pSeconds, int *pMinutes, int *pHours);
int main (void) {
    int seconds = 0;
    int minutes = 0;
    int hours = 0;

    printf("Enter amount of seconds: ");
    scanf("%d", &seconds);
    SplitTime(&seconds, &minutes, &hours);

    printf("%d hours %d minutes %d seconds", hours, minutes, seconds);

}

void SplitTime(int *pSeconds, int *pMinutes, int *pHours){
    *pHours = *pSeconds/3600;
    *pMinutes = (*pSeconds-(*pHours*3600))/60;
    *pSeconds = *pSeconds-(*pHours*3600)-(*pMinutes*60);
}