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
int searchPatient(Patient patientsPrint[], int size);
int searchRegisterSSN(Patient patRegister[], int size, char query[], int print);
int searchRegisterString(Patient patRegister[], int size, char query[], int print);
int searchRegisterImage(Patient patRegister[], int size, int query, int print);

void addImage(Patient patRegister[], int size);
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

Patient addPatient(Patient patRegister[], int size){
    int input = 0;
    int check = 0;
    char stoff = '*';
    Patient newPatient;
    do
    {
        printf("Ange personnummer: ");
        scanf("%s%c", newPatient.personNummer, &stoff);
        check  = searchRegisterSSN(patRegister, size, newPatient.personNummer, NOPRINT);
        if (check)
        {
            printf("Personnummeret existerar redan!\n");
        }
        
    } while (check);
    
    
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
            check = searchRegisterImage(patRegister, size, input, NOPRINT);
            if (check)
            {
                printf("Referensen existerar redan!\n");
            }
        
        } while (check && input);
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
    printf("\nPersonnummer      Namn                           Bildreferenser\n");
    printf("_____________________________________________________________________\n");
    for (int p = 0; p < size; p++)
    {
       printf("%-18s", patientsPrint[p].personNummer);
       printf("%-31s", patientsPrint[p].name);
       printf("[ ");
       for (int imageNumber = 0; imageNumber+1 < patientsPrint[p].numberOfImages; imageNumber++)
       {
            printf("%d, ", patientsPrint[p].images[imageNumber]);
       }
       if (patientsPrint[p].numberOfImages)
       {
        printf("%d ", patientsPrint[p].images[patientsPrint[p].numberOfImages-1]);
       }
       
       
       printf("]\n");
    }
    printf("\n");
}

int searchPatient(Patient patientsPrint[], int size){
    char searchCLI = '*';
    char searchString[NAMELENGTH];
    int searchInt = -55;
    int hits = 0;
    if (size<=0)
    {
        printf("Patientregister tomt!\n");
    }
    else{
        do
        {
            printf("Sok pa personnummer(1), namn(2), bildreferens(3), avsluta(4): ");
            scanf(" %c", &searchCLI);
            switch (searchCLI)
            {
            case '1':
                printf("Ange personnummer: ");
                scanf("%s", searchString);
                hits = searchRegisterSSN(patientsPrint, size, searchString, PRINT);
                break;
            case '2':
                printf("Ange sokstrang: ");
                scanf(" %[^'\n']%*c", searchString);
                hits = searchRegisterString(patientsPrint, size, searchString, PRINT);
                break;
            case '3':
                printf("Ange bildreferens: ");
                scanf("%d", &searchInt);
                hits = searchRegisterImage(patientsPrint, size, searchInt, PRINT);
                break;
            case '4':
                printf("Avslutar sokning\n");
                break;
            
            default:
                break;
            }
        } while (searchCLI!='4');
    }
    return hits;
}
int searchRegisterSSN(Patient patRegister[], int size, char query[], int print){
    Patient result[1];
    int hit = 0;
    for (int i = 0; i < size; i++)
    {
        if (!(strcmp(query, patRegister[i].personNummer)))
        {
            hit=1;
            result[0] = patRegister[i];
        }       
    }
    if (print)
    {
        if (hit)
        {
            printPatients(result, hit);
        }
        else{
            printf("Ingen traff!\n");
        }
    }
    return hit;
}
int searchRegisterString(Patient patRegister[], int size, char query[], int print){
    Patient result[MAXPATIENTS];
    int hits = 0;
    for (int i = 0; i < size; i++)
    {
        if (strstr(patRegister[i].name, query))
        {
            result[hits] = patRegister[i];
            hits++;
        }       
    }
    if (print)
    {
        if (hits)
        {
            printPatients(result, hits);
        }
        else{
            printf("Ingen traff!\n");
        }
    }
    return hits;
}
int searchRegisterImage(Patient patRegister[], int size, int query, int print){
    Patient result[1];
    int hit = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < patRegister[i].numberOfImages; j++)
        {
            if (query == patRegister[i].images[j])
            {
                hit=1;
                result[0] = patRegister[i];
            } 
        }
              
    }
    if (print)
    {
        if (hit)
        {
            printPatients(result, hit);
        }
        else{
            printf("Ingen traff!\n");
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