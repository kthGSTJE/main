#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAXPATIENTS 1000
#define NAMELENGTH 30+1
#define SSNLENGTH 11+1
#define MAXIMAGES 10
#define FILENAMELENGTH 20+1

typedef struct 
{
   char name[NAMELENGTH];
   char personNummer[SSNLENGTH];
   int images[MAXIMAGES];
   int numberOfImages;
} Patient;

void printMenu(void);
Patient addPatient(void);

void printPatients(Patient patientsPrint[], int size);
void searchPatient(void);
void addImage(void);
void sortPatients(void);
void unregisterPatient(void);

int main (void){
    FILE *pFile;
    Patient patients[MAXPATIENTS];
    char inputCLI = '*';
    char inputFile[FILENAMELENGTH];
    int lastPatient = 0;
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
            if (lastPatient<MAXPATIENTS)
            {
                patients[lastPatient] = addPatient();
                lastPatient++;
            }
            else{
                printf("Max antal patienter i register\n");
            }
            break;
        case '2':
            printPatients(patients, lastPatient);
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
            printf("Avslutar programmet...\n");
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

Patient addPatient(void){
    int input = 0;
    char stoff = '*';
    Patient newPatient;
    printf("Ange personnummer: ");
    scanf("%s%c", newPatient.personNummer, &stoff);
    //kolla med databasen om pnummer existerar
    printf("Ange Namn: ");
    scanf("%[^'\n']%*c", newPatient.name);
    newPatient.numberOfImages =0;
    do
    {
        printf("Ange bildreferens %d (0 for att avsluta): ", newPatient.numberOfImages+1);
        scanf("%d", &input);
        //kolla om bildreferens existerar
        if (input)
        {
            newPatient.images[newPatient.numberOfImages] = input;
            newPatient.numberOfImages++;
        }
        
    } while (input!=0 && newPatient.numberOfImages<10);

    return newPatient;

}

void printPatients(Patient patientsPrint[], int size){
    printf("Skriver ut alla patienter\n");
    printf("\nPersonnummer      Namn                           Bildreferenser\n\n");
    printf("_____________________________________________________________________\n");
    for (int p = 0; p < size; p++)
    {
       printf("%-18s", patientsPrint[p].personNummer);
       printf("%-31s", patientsPrint[p].name);
       printf("[ ");
       for (int imageNumber = 0; imageNumber < patientsPrint[p].numberOfImages; imageNumber++)
       {
            printf("%d, ", patientsPrint[p].images[imageNumber]);
       }
       printf("]\n");
       
    }
    printf("\n");
    

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