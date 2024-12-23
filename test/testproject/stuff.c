#include<stdio.h>

int main (void){
    int heals = 3;
    int maxHp = 100;
    int hp = 100;
    int choice = 0;
    int level = 1;
    int damage = 3;
    int mobHP = 0;

    do
    {
        printf("Current status: | Level: %d | HP: %d/%d | Heals left: %d |\n", level, hp, maxHp, heals);
        printf("Possible choices: \n");
        printf("1. Next battle \n");
        printf("2. Heal \n");
        printf("3. Go home \n");

        do
        {
            printf("Next step: ");
            scanf("%d", &choice);
        } while (choice<0 || choice>3);

        switch (choice)
        {
        case 1: //fight
            mobHP = 5+level*10+(level*level/2);
            printf("Monster encountered |HP:%d|\n", mobHP);

            //actual fight
            do
            {

                mobHP = mobHP-damage;
            } while (mobHP>0 || hp>0);
            level++;
            
            
            break;
        case 2: //heal
            printf("You decide to heal\n");
            if (heals>0)
            {
                hp = hp+(maxHp/4);
                printf("You heal %d health\n",maxHp/4);
                heals--;
            }
            else {
                printf("You are out of heals\n");
            }

            break;
        case 3: //end game
            printf("You decide to go home\n");
            hp = 0;
            break;
        }
        
    }while (hp>0);

    printf("Game Over!");
    
}