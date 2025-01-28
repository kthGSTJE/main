#include<stdio.h>
#define TICKET 35

void ViewTicket(int aTicket[], int size);
void Function2(void);
void Function3(void);
void Function4(void);
void Quit(void);


int main (void){
    char input = '*';
    int ticket[TICKET] = {0};
    ticket[1] = 1;

    do
    {
        printf("Input command: ");
        scanf(" %c", &input);

        switch (input)
        {
        case 'v':
            ViewTicket(ticket, TICKET);
            break;
        case 's':
            Function2();
            break;
        case 'c':
            Function3();
            break;
        case 'a':
            Function4();
            break;
        case 'q':
            Quit();
            break;
        case '\n':
            break;
        default:
            printf("Please input any command (1-5)\n");
            break;
        }
    } while (input != 'q');
    
}

void ViewTicket(int aTicket[], int size){
    printf("You have made it!\n");
    for (int i = 0; i < TICKET; i++)
    {
        if (aTicket[i])
        {
            printf(" %d", aTicket[i]+1);
        }
        else{
            printf(" *");
        }
        if ((i+1)%6 == 0)
        {
            printf("\n");
        }
        
    }
    printf("\n");

}
void Function2(void){
    printf("There is nothing to see here\n");
    
}
void Function3(void){
    printf("There is nothing to see here\n");
    
}
void Function4(void){
    printf("There is nothing to see here\n");
    
}
void Quit(void){
    printf("You have quit the application\n");
    
}