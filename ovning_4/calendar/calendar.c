#include<stdio.h>

int main (void){
    int currentDay = 0;
    int currentMonth = 0;

    int totalDays = 31;
    printf("Skriv in månad i sifferformat: ");
    scanf("%d", &currentMonth);

    switch (currentMonth)
    {
    case 2:
        totalDays=28;
        break;
    case 4:
        totalDays=30;
        break;
    case 6:
        totalDays=30;
        break;
    case 9:
        totalDays=30;
        break;
    case 11:
        totalDays=30;
        break; 
    default:
        break;
    }
    printf("Skriv in dagen som månaden startar på i nummerform: ");
    scanf("%d", &currentDay);

    for (int i = 0; i < totalDays; i++)
    {
        switch (currentDay)
        {
        case 1:
            printf("Måndag den %02d\n", i+1);
            break;
        case 2:
            printf("Tisdag den %02d\n", i+1);
            break;
        case 3:
            printf("Onsdag den %02d\n", i+1);
            break;
        case 4:
            printf("Torsdag den %02d\n", i+1);
            break;
        case 5:
            printf("Fredag den %02d\n", i+1);
            break;
        case 6:
            printf("Lördag den %02d\n", i+1);
            break;
        case 7:
            printf("Söndag den %02d\n", i+1);
            break;
        
        default:
            break;
        }
        if (currentDay==7){
            currentDay=1;
        }
        else{
            currentDay++;
        }
        
    }
    
}