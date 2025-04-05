#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAXPATIENTS 1000
#define NAMELENGTH 50+1
#define SSNLENGTH 11+1
#define MAXIMAGES 10
#define FILENAMELENGTH 20+1

typedef struct 
{
   char name[NAMELENGTH];
   char personNummer[SSNLENGTH];
   int images[MAXIMAGES];
} Patient;

void printMenu(void);
Patient addPatient(int *pLastPatient);

void printPatients(void);
void searchPatient(void);
void addImage(void);
void sortPatients(void);
void unregisterPatient(void);

int main (void){
    Patient patients[MAXPATIENTS];
    char inputCLI = '*';
    char inputFile[FILENAMELENGTH];
    int lastpatient = 0;
    //Startup - Val av lagringsfil
    printf("\nPATIENTJOURNALSYSTEM\n\n");
    printf("Vilken fil vill du anvanda: ");
    scanf("%s", inputFile);


    //CLI huvuddelen av programmet 
    printMenu();
    do
    {
        printf("Ange alternativ: ");
        scanf(" %c", &inputCLI);
        switch (inputCLI)
        {
        case '1':
            addPatient(&lastpatient);
            break;
        case '2':
            printPatients();
            break;
        case '3':
            searchPatient();
            break;
        case '4':
            addImage();
            break;
        case '5':
            sortPatients();
            break;
        case '6':
            unregisterPatient();
            break;
        case '7':
            printf("Quit\n");
            break;
        
        default:
            printMenu();
            break;
        }
    } while (inputCLI!='7');

    //Sparar patientdata i patienter.txt
    
}

//Skriver ut alternativen för huvudmenyn
void printMenu(void){
    int menuNum = 1;
    printf("Huvudmeny\n");
    printf("%11d) Registrera nya patienter\n", menuNum++);
    printf("%11d) Skriv ut alla patienter\n", menuNum++);
    printf("%11d) Soka efter patienter\n", menuNum++);
    printf("%11d) Lagg till bilder\n", menuNum++);
    printf("%11d) Sortera patienter\n", menuNum++);
    printf("%11d) Avregistrera patienter\n", menuNum++);
    printf("%11d) Avsluta programmet\n", menuNum++);
    
}

Patient addPatient(int *pLastPatient){
    Patient newPatient;

    printf("Ange personnummer: ");
    scanf("%s", newPatient.name);
    //kolla med databasen om pnummer existerar

}

void printPatients(void){
    printf("Skriver ut alla patienter\n");
}

void searchPatient(void){
    printf("Soka efter en patient\n");
}

void addImage(void){
    printf("Lagg till bilder for en patient\n");
}

void sortPatients(void){
    printf("Sorterar patienter efter namn/personnummer\n");
}

void unregisterPatient(void){
    printf("Radera en patient\n");
}