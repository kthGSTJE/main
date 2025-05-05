#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAXPATIENTS 1000
#define NAMELENGTH 30+1
#define SSNLENGTH 11+1
#define MAXIMAGES 10
#define FILENAMELENGTH 40+1

typedef struct 
{
   char name[NAMELENGTH];
   char personNummer[SSNLENGTH];
   int images[MAXIMAGES];
   int numberOfImages;
} Patient;
typedef struct 
{
    int results[MAXPATIENTS];
    int totalResults;
} Search;


void printMenu(void);
void addPatient(Patient patRegister[], int *pSize);
void registerPatient(Patient patRegister[], int *pSize, char personNummer[]);

void printPatients(Patient patientsPrint[], int size);
void printPrintLabel(void);
void viewPatient(Patient thePatient);

void searchPatient(Patient patientsPrint[], int size);
Search searchModule(Patient patRegister[], int size, char input);
Search searchRegisterSSN(Patient patRegister[], int size, char query[]);
Search searchRegisterString(Patient patRegister[], int start, int size, char query[]);
Search searchRegisterImage(Patient patRegister[], int size, int query);

void addImage(Patient patRegister[], int size);
void sortPatients(Patient patRegister[], int size);
void sortSSN(Patient patRegister[], int size);
void sortName(Patient patRegister[], int size);

void unregisterPatient(Patient patRegister[], int *pSize);
void confirmUnregistration(Patient patRegister[], int *pSize, int unregIndex);

void loadRegister(Patient patRegister[], int *pSize, char fileName[]);
void saveRegister(Patient patRegister[], int size, char fileName[]);

int main (void){
    char fileName[FILENAMELENGTH];

    Patient patients[MAXPATIENTS];
    int lastPatient = 0;
    char inputCLI = '*';
    //Startup - Val av lagringsfil
    printf("\nPATIENTJOURNALSYSTEM\n\n");
    printf("Vilken fil vill du anvanda: ");
    scanf("%s", fileName);
    loadRegister(patients, &lastPatient, fileName);
    printMenu();
    do
    {
        printf("Ange alternativ: ");
        scanf(" %c", &inputCLI);
        switch (inputCLI)
        {
        case '1':
            addPatient(patients, &lastPatient);
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
            sortPatients(patients, lastPatient);
            break;
        case '6':
            unregisterPatient(patients, &lastPatient);
            break;
        case '7':
            printf("Avslutar programmet...\n");
            break;
        
        default:
            printMenu();
            break;
        }
    } while (inputCLI!='7');

    saveRegister(patients, lastPatient, fileName);
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
void addPatient(Patient patRegister[], int *pSize){
    printf("\nREGISTERING\n\n");
    char inputString[SSNLENGTH];
    Search checkDB;
    if (*pSize<MAXPATIENTS)
    {
        do
        {
            printf("Ange personnummer (q for att avsluta): ");
            scanf(" %[^'\n']%*c", inputString);
            checkDB  = searchRegisterSSN(patRegister, *pSize, inputString);
            if (strcmp(inputString, "q"))
            {
                if (!checkDB.totalResults)
                {
                    registerPatient(patRegister, pSize, inputString);
                }
                else{
                    printf("Personnummeret redan registrerat!\n");
                }
            }
        } while (strcmp(inputString, "q") && *pSize<MAXPATIENTS);
    }
    else{
        printf("Max antal patienter i registret!\n");
    }
}
void registerPatient(Patient patRegister[], int *pSize, char personNummer[]){
    int input = 0;
    int checkLocal = 0;
    Search checkDB;
    Patient newPatient;
    strcpy(newPatient.personNummer, personNummer);
    printf("Ange Namn: ");
    scanf("%[^'\n']%*c", newPatient.name);
    newPatient.numberOfImages = 0;
    do
    {   
        do
        {
            printf("Ange bildreferens %d (0 for att avsluta): ", newPatient.numberOfImages+1);
            scanf("%d", &input);
            checkDB = searchRegisterImage(patRegister, *pSize, input);
            checkLocal=0;
            for (int i = 0; i < newPatient.numberOfImages; i++)
            {
                if (input == newPatient.images[i])
                {
                    checkLocal = 1;
                }  
            }
            if (checkDB.totalResults || checkLocal)
            {
                printf("Referensen existerar redan!\n");
            }
        
        } while ((checkDB.totalResults || checkLocal) && input);
        if (input)
        {
            newPatient.images[newPatient.numberOfImages] = input;
            newPatient.numberOfImages++;
        }
    } while (input!=0 && newPatient.numberOfImages<10);
    patRegister[*pSize] = newPatient;
    (*pSize)++;
}
//Skriver ut size antal patienter i en Patient array
void printPatients(Patient patientsPrint[], int size){
    printf("\nREGISTER\n\n");
    printPrintLabel();
    for (int p = 0; p < size; p++)
    {
       viewPatient(patientsPrint[p]);
    }
    printf("\n");
}
void printPrintLabel(void){
    printf("\nPersonnummer      Namn                           Bildreferenser\n");
    printf("__________________________________________________________________________________________\n");
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
    printf("\nSOKNING\n\n");
    char searchCLI = '*';
    Search searchDB;
    if (size<=0)
    {
        printf("Patientregister tomt!\n");
    }
    else{
        do
        {
            printf("Sok pa personnummer(1), namn(2), bildreferens(3), avsluta(4): ");
            scanf(" %c", &searchCLI);
            searchModule(patRegister, size, searchCLI);
        } while (searchCLI!='4');
    }
}
Search searchModule(Patient patRegister[], int size, char input){
    char searchString[NAMELENGTH];
    int searchInt = -55;
    Search searchDB;
    switch (input)
    {
    case '1':
        printf("Ange personnummer: ");
        scanf("%s", searchString);
        searchDB = searchRegisterSSN(patRegister, size, searchString);
        printPrintLabel();
        if (searchDB.totalResults)
        {
            viewPatient(patRegister[searchDB.results[0]]);
        }
        printf("\n");
        break;
    case '2':
        printf("Ange sokstrang: ");
        scanf(" %[^'\n']%*c", searchString);
        searchDB = searchRegisterString(patRegister, 0, size, searchString);
        printPrintLabel();
        for (int i = 0; i < searchDB.totalResults; i++)
        {
            viewPatient(patRegister[searchDB.results[i]]);
        }
        printf("\n");
        break;
    case '3':
        printf("Ange bildreferens: ");
        scanf("%d", &searchInt);
        searchDB = searchRegisterImage(patRegister, size, searchInt);
        printPrintLabel();
        if (searchDB.totalResults)
        {
            viewPatient(patRegister[searchDB.results[0]]);
        }
        printf("\n");
        break;
    case '4':
        printf("Avslutar sokning\n");
        break;
    
    default:
        break;
    }
    return searchDB;
}
Search searchRegisterSSN(Patient patRegister[], int size, char query[]){
    Search newSearch;
    newSearch.totalResults=0;
    for (int i = 0; i < size; i++)
    {
        if (!(strcmp(query, patRegister[i].personNummer)))
        {
            newSearch.results[0]=i;
            newSearch.totalResults=1;
        }       
    }
    return newSearch;
}
Search searchRegisterString(Patient patRegister[], int start, int size, char query[]){
    Search newSearch;
    newSearch.totalResults=0;
    for (int i = start; i < size; i++)
    {
        if (strstr(patRegister[i].name, query))
        {
            newSearch.results[newSearch.totalResults]=i;
            newSearch.totalResults++;
        }       
    }
    return newSearch;
}
Search searchRegisterImage(Patient patRegister[], int size, int query){
    Search newSearch;
    newSearch.totalResults=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < patRegister[i].numberOfImages; j++)
        {
            if (query == patRegister[i].images[j])
            {
                newSearch.results[0]=i;
                newSearch.totalResults=1;
            } 
        }  
    }
    return newSearch;
}

void addImage(Patient patRegister[], int size){
    printf("\nLAGG TILL BILD\n\n");
    char searchCLI = '*';
    int imageRef = 0;
    Search searchDB; 
    Search checkDB;
    do
    {
        printf("Sok pa personnummer(1), namn(2), bildreferens(3), avsluta(4): ");
        scanf(" %c", &searchCLI);
        searchDB = searchModule(patRegister, size, searchCLI);
        if (searchDB.totalResults!=1 && searchCLI!='4')
        {
            printf("Du fick inte exakt 1 traff\n");
        }
    } while ((searchDB.totalResults!=1) && searchCLI!='4');
    if (patRegister[searchDB.results[0]].numberOfImages<10 && searchCLI!='4')
    {
        do
        {   
            do
            {
                printf("Ange bildreferens %d (0 for att avsluta): ", patRegister[searchDB.results[0]].numberOfImages+1);
                scanf("%d", &imageRef);
                checkDB = searchRegisterImage(patRegister, size, imageRef);
                if (checkDB.totalResults)
                {
                    printf("Referensen existerar redan!\n");
                }
            
            } while (checkDB.totalResults && imageRef);
            if (imageRef)
            {
                patRegister[searchDB.results[0]].images[patRegister[searchDB.results[0]].numberOfImages] = imageRef;
                patRegister[searchDB.results[0]].numberOfImages++;
            }

        } while (imageRef!=0 && patRegister[searchDB.results[0]].numberOfImages<10);
    }
    else if(searchCLI == '4'){
        printf("Atergar till huvudprogram\n");
    }
    else{
        printf("Max antal bilder finns redan!\n");
    }
}

void sortPatients(Patient patRegister[], int size){
    printf("\nSORTERING\n\n");
    char input = '*';
    printf("Sortera efter (1)personnummer, (2)namn: ");
    scanf(" %c", &input);
    switch (input)
    {
    case '1':
        sortSSN(patRegister, size);
        break;
    case '2':
        sortName(patRegister, size);
        break;
    default:
        break;
    }
}
void sortSSN(Patient patRegister[], int size){
    Patient temp;
    int unsorted = 0;
    for (int i = 1; i < size; i++)
    {
        if (strcmp(patRegister[i-1].personNummer, patRegister[i].personNummer)>0)
        {
            temp = patRegister[i-1];
            patRegister[i-1] = patRegister[i];
            patRegister[i] = temp;
            unsorted = 1;
        }
    }
    if (unsorted)
    {
        sortSSN(patRegister, size);
    }
}
void sortName(Patient patRegister[], int size){
    Patient temp;
    int unsorted = 0;
    for (int i = 1; i < size; i++)
    {
        if (strcmp(patRegister[i-1].name, patRegister[i].name)>0)
        {
            temp = patRegister[i-1];
            patRegister[i-1] = patRegister[i];
            patRegister[i] = temp;
            unsorted = 1;
        }
    }
    if (unsorted)
    {
        sortName(patRegister, size);
    }
}

void unregisterPatient(Patient patRegister[], int *pSize){
    printf("\nAVREGISTRERING\n\n");
    char searchCLI = '*';
    Search searchDB; 
    do
    {
        printf("Sok pa personnummer(1), namn(2), bildreferens(3), avsluta(4): ");
        scanf(" %c", &searchCLI);
        searchDB = searchModule(patRegister, *pSize, searchCLI);
        if (searchDB.totalResults!=1 && searchCLI!='4')
        {
            printf("Du fick inte exakt 1 traff\n");
        }
    } while ((searchDB.totalResults!=1) && searchCLI!='4');
    if (searchCLI!= '4')
    {
        char input = '*';
        printf("Vill du avregistrera patienten (j/n)? ");
        scanf(" %c", &input);
        switch (input)
        {
        case 'j':
            confirmUnregistration(patRegister, pSize, searchDB.results[0]);
            break;
        case 'n':

            break;
        default:
            break;
        }
    }
}
void confirmUnregistration(Patient patRegister[], int *pSize, int unregIndex){
    Patient empty;
    (*pSize)--;
    patRegister[unregIndex] = patRegister[*pSize];
    patRegister[*pSize] = empty;
    printf("Patienten avregistreras\n");
}

void loadRegister(Patient patRegister[], int *pSize, char fileName[]){
    FILE *pFile;
    int dud = 0;
    if ((pFile=fopen(fileName, "r")))
    {
        fscanf(pFile, "%d", &(*pSize));
        if (*pSize<=MAXPATIENTS)
        {
            for (int i = 0; i < *pSize; i++)
            {
                fscanf(pFile, " %[^'\n']%*c", patRegister[i].name);
                fscanf(pFile, "%s", patRegister[i].personNummer);
                fscanf(pFile, "%d", &patRegister[i].numberOfImages);
                if (patRegister[i].numberOfImages)
                {
                    for (int img = 0; img < patRegister[i].numberOfImages; img++)
                    {
                        fscanf(pFile, "%d", &patRegister[i].images[img]);
                    }
                }
                else{
                    fscanf(pFile, "%d", &dud);
                }
            }
        }
        else{
            printf("Error! For stor fil för att ladda\n");
            *pSize=0;
        }
    }
    else{
        printf("Error! Problem inlasning\n");
    }
    fclose(pFile);
}
void saveRegister(Patient patRegister[], int size, char fileName[]){
    FILE *pFile;
    if ((pFile=fopen(fileName, "w")))
    {
        fprintf(pFile, "%d\n", size);
        for (int i = 0; i < size; i++)
        {
            fprintf(pFile, "%s\n", patRegister[i].name);
            fprintf(pFile, "%s\n", patRegister[i].personNummer);
            fprintf(pFile, "%d\n", patRegister[i].numberOfImages);
            if (patRegister[i].numberOfImages)
            {
                for (int img = 0; img < patRegister[i].numberOfImages; img++)
                {
                    fprintf(pFile, "%d ", patRegister[i].images[img]);
                }
            }
            else{
                fprintf(pFile, "%d ", 0);
            }
            
            fprintf(pFile, "\n");
        }
        printf("Sparar i %s\n", fileName);
    }
    else{
        printf("ERROR Inlasning!\n");
    }
    fclose(pFile);
}