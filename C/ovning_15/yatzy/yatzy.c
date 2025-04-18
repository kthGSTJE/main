#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DICE 6
#define HAND 5
#define NAMESIZE 10+1
#define TBLSIZE 10
#define MAXPLAYERS 5
#define MAXTHROWS 3

typedef struct {
   char name[NAMESIZE];
   int score[TBLSIZE];
} Player;

void initRandomGenerator(void);
int rndNumber(int nbs);
void viewHand(int aHand[], int size);
Player addPlayers(void);
void printBoard(Player currentPlayers[], int size);



int main(void){
   int hand[HAND];
   char dice;
   Player players[MAXPLAYERS];
   int totalPlayers;
   int input = 0;;
   printf("Yatzy 0.1\n");
   initRandomGenerator();

   printf("How many players? (1-5): ");
   scanf(" %d", &totalPlayers);
   for (int  i = 0; i < totalPlayers; i++)
   {  
      printf("PLAYER %d \n", i+1);
      players[i] = addPlayers();
   }
   
   

   for (int throw=0; throw<MAXTHROWS; throw++) {
      printBoard(players, totalPlayers);
      if (throw) {
         printf("NOWAY\n");
      } else {
        for (int i=0; i<HAND; i++)    //1:st turn
           hand[i]=rndNumber(DICE)+1;
      }
      viewHand(hand, HAND);
   }

   printf("done, bye!\n");
}

//*** Random Number Package ***************************
void initRandomGenerator(void) {
    srand((unsigned)time(NULL));
}

int rndNumber(int nbs){
    return rand()%nbs;
}
//*** End of RNP **************************************

void viewHand(int aHand[], int size){
   printf("[ ");
   for (int i=0; i<size; i++) {
     printf("%d ", aHand[i]);
   }
   printf("] ");
}

Player addPlayers(void){
   Player newPlayer;
   printf("Name: ");
   scanf(" %s", newPlayer.name);
   for (int i = 0; i < TBLSIZE; i++)
   {
      newPlayer.score[i] = 0;
   }
   

   return newPlayer;
}

void printBoard(Player currentPlayers[], int size){
   printf("PLAYERS      ");
   for (int i = 0; i < TBLSIZE; i++)
   {
      switch (i)
      {
      case 0:
         printf("  C");
         break;
      case 7:
         printf("  1P");
         break;
      case 8:
         printf(" 2P");
         break;
      case 9:
         printf(" TRI");
         break;
      
      default:
         printf("%3d", i);
         break;
      }
   }
   printf("\n");
   for (int i = 0; i < size; i++)
   {
      printf("%-8s     ", currentPlayers[i].name);
      for (int j = 0; j < TBLSIZE; j++)
      {
         printf("%3d", currentPlayers[i].score[j]);
      }
      printf("\n");
      
   }
   
}