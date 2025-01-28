#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void TimesTwo(int *pNum);

int main (void){
    int tal = 5;

    printf("%d\n", tal);
    TimesTwo(&tal);
    printf("%d\n", tal);

}
void TimesTwo(int *pNum){
    *pNum = *pNum*2;
    
}