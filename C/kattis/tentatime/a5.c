#include<stdio.h>
#include<stdlib.h>


int find(char word[], char searchString[]);

int main (void){

    printf("%d\n", find("Bergsskreva","rgsskr"));
    printf("%d\n", find("Bergsskreva","rgs$kr"));
    printf("%d\n", find("Jag satt i en sjo och sjong","s$$t i"));
    printf("%d\n", find("Jag satt i en sjo och sjong","sa$tt i"));
}


int find (char word[], char searchString[]){
    int searchLength = 0;
    int returnIndex = -7;
    while (searchString[searchLength]!= '\0')
    {
        searchLength++;
    }
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (searchString[0] == word[i] && returnIndex<0)
        {
            for (int j = 0; j < searchLength; j++)
            {
                if (word[i+j]!=searchString[j] && searchString[j]!='$')
                {
                    //printf("MISSMATCH %c %c\n", word[i+j], searchString[j]);
                    returnIndex = -1;
                    j = searchLength;
                }
                else{
                    returnIndex = i;
                }
                
            }

        }
    }


    
    return returnIndex;
}