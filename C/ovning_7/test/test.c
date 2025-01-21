#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Slump(void);
int Sju(void);
int AddTwo(int tal);

int main (void){
    int i = 5;
    int z = 7;
    Slump();
    i = Sju();

    z = AddTwo(z);
    printf("%d, %d", i, z);


}

void Slump(void){
    srand((unsigned) time(NULL));

}
int Sju(void){
    return 7;
}
int AddTwo(int tal){
    tal = tal+2;
    return tal;
}