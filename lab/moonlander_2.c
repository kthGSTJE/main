#include<stdio.h>
#define GRAVITY 1.5f
#define THROTTLECOEFF 0.1f

int main(void){
    int time = 0;
    int throttle = 0;
    float fuel = 500.0;
    float velocity = -25.0;
    float height = 250.0;

    //inlevelse
    printf("\nLUNAR DECENT MISSION\n\n");
    printf("You are Neil Armstrong, about to be first man to\n");
    printf("ever set foot on the surface of the moon. Unless?\n\n");
    printf("It is your job to pilot the lander for the last 250m\n");
    printf("of the decent. You have full control of throttle (0-100%%).\n");
    printf("Each turn will represent 1 second in real time.\n");
    printf("Landing at any speed greater than 2.0 m/s will leave you\n");
    printf("stranded on the moon's surface forever. Good luck astronaut!\n\n");


    printf("TIME | HEIGHT | VELOCITY |   FUEL   | THROTTLE\n");
    printf("----------------------------------------------\n");

    do
    {
        if (fuel>0)
        {
            do
            {
                printf(" %02d  | %6.2f |  %+06.2f  |  %6.2f  | ", time, height, velocity, fuel);
                scanf("%d", &throttle);

                if (throttle>fuel)
                {
                    throttle = fuel;
                }
                
            } while (throttle<0 || throttle>100);
            
        }
        else{
            throttle = 0;
            printf(" %02d  | %6.2f |  %+06.2f  |  %6.2f  | %d\n", time, height, velocity, fuel, throttle);
        }

        //uträkningar 
        velocity = velocity+(throttle*THROTTLECOEFF-GRAVITY);
        height = height+velocity-(throttle*THROTTLECOEFF-GRAVITY)/2;
        fuel = fuel-throttle;
        
        time++;
    } while (height>0);
    printf("----------------------------------------------\n");

    //koll vid landning
    if (velocity>=-2.0)
    {
        printf("You have landed flawlessly on the moon!\n");
        printf("Time to think of something quotable to say...\n\n");
    }
    else
    {
        printf("You have crashed on the moon's surface with a speed of %.2f m/s\n", velocity);
        printf("May god have mercy on your soul!\n\n");
    }
}