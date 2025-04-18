#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define NAMELENGTH 30+1
#define MAXPLAYERS 36

typedef struct 
{
    char name[NAMELENGTH];
    int shirtNumber; 
} Player;


typedef struct 
{
    char name[NAMELENGTH];
    Player players[MAXPLAYERS];
    int totalPlayers;
} Team;

Team addTeam (void);

int main (void){
    Team teams[MAXPLAYERS];
    int totalTeams = 0;
    char input = '*';

    do
    {
        printf("Enter command (a)dd or (q)uit: ");
        scanf(" %c", &input);
        switch (input)
        {
        case 'a':
            teams[totalTeams] = addTeam();
            totalTeams++;
            break;
        case 'p': 
            for (int i = 0; i < totalTeams; i++)
            {
                printf("%s\n", teams[i].name);
                for (int j = 0; j < teams[i].totalPlayers; j++)
                {
                    printf("%10s %d\n", teams[i].players[j].name, teams[i].players[j].shirtNumber);
                }
                
            }
            
            break;
        default:
            break;
        }
    } while (input!='q');
    
    

}

Team addTeam (void){
    char input = '*';
    Team newTeam;
    newTeam.totalPlayers=0;
    printf("Team name: ");
    scanf("%s", newTeam.name);

    do
    {
        printf("Player %d name: ", newTeam.totalPlayers+1);
        scanf("%s", newTeam.players[newTeam.totalPlayers].name);
        printf("Player %d number: ", newTeam.totalPlayers+1);
        scanf("%d", &newTeam.players[newTeam.totalPlayers].shirtNumber);
        newTeam.totalPlayers++;
        printf("Add another? (y/n): ");
        scanf(" %c", &input);

    } while (input=='y');
    
    return newTeam;
}