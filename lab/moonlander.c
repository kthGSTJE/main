#include<stdio.h>
#define GRAVITY 1.5f
#define THROTTLECOEFF 0.1f

int main(void){
    int time = 0;
    int throttle = 0;
    float fuel = 500.0;
    float velocity = -25.0;
    float height = 250.0;

    printf("TIME | HEIGHT | VELOCITY | FUEL | THROTTLE\n");

    do
    {
        printf("%2d  |  %3.2f  |  %3.2f  |  %3.2f  |  %d\n", time, height, velocity, fuel, throttle);

        if (fuel>0)
        {
            do
            {
                printf("Set throttle: ");
                scanf("%d", &throttle);
            } while (throttle<0 || throttle>100);
            
        }
        else{
            printf("Du har soppatorsk!\n");
            throttle=0;
        }
        
        
        velocity=velocity+(throttle*THROTTLECOEFF-GRAVITY);
        height=height+velocity-(throttle*THROTTLECOEFF-GRAVITY)/2;
        fuel= fuel-throttle;
        
        time++;
    } while (height>0);

    if (velocity>=-2.0){
        printf("Du har landat galant på månen");
    }
    else{
        printf("Du har krashlandat på månen med hastigheten %.2f m/s", velocity);
    }
}