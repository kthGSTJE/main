#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define TITLESIZE 50+1
#define AUTHORSIZE 50+1
#define LOCATIONSIZE 20+1
typedef struct
    {
        char title[TITLESIZE];
        char author[AUTHORSIZE];
        float price;
        char location[LOCATIONSIZE];
    } Book;

void printBook (Book *pBook);
Book initBook (char initTitle[], char initAuthor[], float initPrice, char initLocation[]);

int main (void){
    srand((unsigned) time(NULL));

    Book newBook = initBook("Mikrodatorteknik", "Anders Cajander", 399.50, "Väskan");
    printBook(&newBook);

}

void printBook (Book *pBook){
    printf("%s\n", pBook->title);
    printf("%s\n", pBook->author);
    printf("%.2f\n", pBook->price);
    printf("%s\n", pBook->location);
}
Book initBook (char initTitle[], char initAuthor[], float initPrice, char initLocation[]){
    Book funcBook;
    strcpy(funcBook.title, initTitle);
    strcpy(funcBook.author, initAuthor);
    funcBook.price = initPrice;
    strcpy(funcBook.location, initLocation);

    return funcBook;
}