#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main (void){
    FILE *pFile;
    int count = 0;
    char msg[30];
    if ((pFile = fopen("data.txt", "r")))
    {
        do
        {
            count = fscanf(pFile, "%s", msg);
            printf("%d %s \n", count, msg);
        } while (count >-1);  
    }
    
    if ((pFile=fopen("data.txt", "w")))
    {
        fprintf(pFile, "Nevermind!\n");
    }
    fclose(pFile);


}