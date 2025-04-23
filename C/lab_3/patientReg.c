#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAXPATIENTS 1000
#define NAMELENGTH 30+1
#define SSNLENGTH 11+1
#define MAXIMAGES 10
#define FILENAMELENGTH 20+1

#define PRINT 1
#define NOPRINT 0

typedef struct 
{
   char name[NAMELENGTH];
   char personNummer[SSNLENGTH];
   int images[MAXIMAGES];
   int numberOfImages;
} Patient;

void printMenu(void);
Patient addPatient(Patient patRegister[], int size);

void printPatients(Patient patientsPrint[], int size);
void printPrintLabel(void);
void viewPatient(Patient thePatient);

void searchPatient(Patient patientsPrint[], int size);
int searchRegisterSSN(Patient patRegister[], int size, char query[]);
int searchRegisterString(Patient patRegister[], int start, int size, char query[]);
int searchRegisterImage(Patient patRegister[], int size, int query);

void addImage(Patient patRegister[], int size);
void sortPatients(void);
void unregisterPatient(void);

int main (void){
    FILE *pFile;
    char inputFile[FILENAMELENGTH];

    Patient patients[MAXPATIENTS];
    int lastPatient = 0;

    char inputCLI = '*';
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
                patients[lastPatient] = addPatient(patients, lastPatient);
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
            searchPatient(patients, lastPatient);
            break;
        case '4':
            addImage(patients, lastPatient);
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
//Skapar ny Patient med unikt personnummer och unika bildreferenser
Patient addPatient(Patient patRegister[], int size){
    int input = 0;
    int check = 0;
    char stoff = '*';

    Patient newPatient;
    do
    {
        printf("Ange personnummer: ");
        scanf("%s%c", newPatient.personNummer, &stoff);
        check  = searchRegisterSSN(patRegister, size, newPatient.personNummer);
        if (check>=0)
        {
            printf("Personnummeret existerar redan!\n");
        }
        
    } while (check>=0);
    
    
    //kolla med databasen om pnummer existerar
    printf("Ange Namn: ");
    scanf("%[^'\n']%*c", newPatient.name);
    newPatient.numberOfImages = 0;
    do
    {   
        do
        {
            printf("Ange bildreferens %d (0 for att avsluta): ", newPatient.numberOfImages+1);
            scanf("%d", &input);
            check = searchRegisterImage(patRegister, size, input);
            if (check>=0)
            {
                printf("Referensen existerar redan!\n");
            }
        
        } while (check>=0 && input);
        if (input)
        {
            newPatient.images[newPatient.numberOfImages] = input;
            newPatient.numberOfImages++;
        }
        
    } while (input!=0 && newPatient.numberOfImages<10);

    return newPatient;

}
//Skriver ut size antal patienter i en Patient array
void printPatients(Patient patientsPrint[], int size){
    printPrintLabel();
    for (int p = 0; p < size; p++)
    {
       viewPatient(patientsPrint[p]);
    }
    printf("\n");
}
void printPrintLabel(void){
    printf("\nPersonnummer      Namn                           Bildreferenser\n");
    printf("_____________________________________________________________________\n");
}
void viewPatient(Patient thePatient){
    printf("%-18s", thePatient.personNummer);
    printf("%-31s", thePatient.name);
    printf("[ ");
    for (int imageNumber = 0; imageNumber+1 < thePatient.numberOfImages; imageNumber++)
    {
         printf("%d, ", thePatient.images[imageNumber]);
    }
    if (thePatient.numberOfImages)
    {
     printf("%d ", thePatient.images[thePatient.numberOfImages-1]);
    }
    
    
    printf("]\n");
}

void searchPatient(Patient patRegister[], int size){
    char searchCLI = '*';
    char searchString[NAMELENGTH];
    if (size<=0)
    {
        printf("Patientregister tomt!\n");
    }
    else{
        do
        {
            printf("Sok pa personnummer(1), namn(2), bildreferens(3), avsluta(4): ");
            scanf(" %c", &searchCLI);
            searchRegister();
        } while (searchCLI!='4');
    }
}
void searchRegister(Patient patRegister[], int size, char option, int results[], int *pTotalResults){
    char searchString[NAMELENGTH];
    int searchint = -1;
    int results[MAXPATIENTS];
    int totalResults = 0;

    switch (option)
    {
    case '1':
        printf("Ange personnummer: ");
        scanf("%s", searchString);
        searchRegisterSSN(patRegister, size, searchString);
        break;
    case '2':
        printf("Ange sokstrang: ");
        scanf(" %[^'\n']%*c", searchString);
        break;
    case '3':
        printf("Ange bildreferens: ");
        scanf("%d", &searchint);
        break;
    case '4':
        printf("Avslutar sokning\n");
        break;
    
    default:
        break;
    }
}
int searchRegisterSSN(Patient patRegister[], int size, char query[]){
    int hit = -1;
    for (int i = 0; i <= size; i++)
    {
        if (!(strcmp(query, patRegister[i].personNummer)))
        {
            hit=i;
        }       
    }
    return hit;
}
int searchRegisterString(Patient patRegister[], int start, int size, char query[]){
    int hit = -1;
    for (int i = start; i < size; i++)
    {
        if (strstr(patRegister[i].name, query))
        {
            hit=i;
            i=size;
        }       
    }
    return hit;
}
int searchRegisterImage(Patient patRegister[], int size, int query){
    int hit = -1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < patRegister[i].numberOfImages; j++)
        {
            if (query == patRegister[i].images[j])
            {
                hit=i;
            } 
        }  
    }
    return hit;
}

void addImage(Patient patRegister[], int size){
    printf("Lagg till bilder for en patient\n");
}

void sortPatients(void){
    printf("Sorterar patienter efter namn/personnummer\n");
}

void unregisterPatient(void){
    printf("Radera en patient\n");
}