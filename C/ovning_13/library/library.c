#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define TITLESIZE 50+1
#define AUTHORSIZE 50+1
#define LOCATIONSIZE 20+1
#define MAXBOOKS 100

typedef struct
    {
        char title[TITLESIZE];
        char author[AUTHORSIZE];
        float price;
        char location[LOCATIONSIZE];
    } Book;

void printBook (Book *pBook);
void viewLibrary(Book library[], int size);
Book addBook(int *pLastBook);

int main (void){
    Book libraryBooks[MAXBOOKS];
    char input = '*';
    int lastBook = 0;

    printf ("\nBOOK LIBRARY\n\n");

    do
    {
        printf("Enter command: ");
        scanf(" %c", &input);
        switch (input)
        {
        case 'a':
            libraryBooks[lastBook] = addBook(&lastBook);
            break;
        case 'v':
            viewLibrary(libraryBooks, lastBook);
            break;
        
        default:
            break;
        }

    } while (input!='q');

    printf("You have quit\n");

}

void printBook (Book *pBook){
    printf("Title: %s\n", pBook->title);
    printf("Title: %s\n", pBook->author);
    printf("Price: %.2f\n", pBook->price);
    printf("Location: %s\n\n", pBook->location);
}

void viewLibrary(Book library[], int size){
    printf("\nVIEW LIBRARY\n\n");
    if (!size)
    {
        printf("Library is empty!\n");
    }
    else{
        for (int i = 0; i < size; i++)
        {
            printf("Book %d: \n", i+1);
            printBook(&library[i]);
        }
    }
    
}

Book addBook(int *pLastBook){
    Book newLibraryBook;

    printf("\nADD BOOK\n\n");
    printf("Book %d\n", *pLastBook+1);
    printf("Title: ");
    scanf("%s", newLibraryBook.title);
    printf("Author: ");
    scanf("%s", newLibraryBook.author);
    printf("Price: ");
    scanf("%f", &newLibraryBook.price);
    printf("Location: ");
    scanf("%s", newLibraryBook.location);

    (*pLastBook)++;

    return newLibraryBook;
}