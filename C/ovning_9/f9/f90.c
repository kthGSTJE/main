#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void TimesTwo(int *pNum);

int main (void){
    int tal = 5;
    int tal2 = 89;

    printf("%d\n", tal);
    TimesTwo(&tal);
    printf("%d\n", tal);
    printf("%d", tal2/10);

}
void TimesTwo(int *pNum){
    *pNum = *pNum*2;
    
}