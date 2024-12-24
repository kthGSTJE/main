#include<stdio.h>

int main (void){
    int stones = 0;

    scanf("%d", &stones);

    /*for (int i = 1; i < stones; i++)
    {
        
    }
    */
   if (stones%2 == 0)
   {
    printf("Bob");
   }
   else{
    printf("Alice");
   }
   
}