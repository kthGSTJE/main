#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define WORDS 5
#define WORDLENGTH 20+1



int main (void){
    char input = '*';
    char password[] = "hejsan";
    char passInput[WORDLENGTH];
    char quizInput[WORDLENGTH];
    
    int examiner = 0;

    char wordsSwe[WORDS][WORDLENGTH];
    char wordsEng[WORDS][WORDLENGTH];
    int usedWords = 0;

    int score = 0;

    printf("\nGLOSOR\n\n");
    printf("Commands: t(ake), q(uit), e(xaminer login)\n");
    printf("Examiner commands: m(ake)\n\n");
    do
    {
        if(examiner)
        {
            printf("EXM:: ");
        }
        else{
            printf("USR:: ");
        }
        printf("Enter command: ");
        scanf(" %c", &input);
        switch (input)
        {
        case 'v':
            for (int i = 0; i < usedWords; i++)
            {
                printf("%s %s\n", wordsSwe[i], wordsEng[i]);
            }
            break;
        case 't':
                printf("Take quiz\n");
                if (usedWords)
                {
                    score=0;
                    for (int i = 0; i < usedWords; i++)
                    {
                        printf("Word %d, %s-", i+1, wordsSwe[i]);
                        scanf("%s", quizInput);
                        if (!strcmp(quizInput, wordsEng[i]))
                        {
                            score++;
                        }
                    }
                    printf("Your score was %d/%d\n", score, usedWords);
                }
                
            break;
        case 'e':
            if (!examiner)
            {
                printf("Examiner login\n");
                printf("Password: ");
                scanf("%s", passInput);
                if (strcmp(password, passInput))
                {
                    printf("Wrong password\n");
                }
                else{
                    printf("Correct password!\n");
                    examiner = 1;
                }
            }
            else{
                printf("Already logged in\n");
            }
            
            break;
        case 'm':
            if (!examiner)
            {
                printf("Please login using the e(xaminer) command\n");
            }
            else{
                printf("Make quiz\n");
                if (usedWords<WORDS)
                {
                    do
                    {
                        printf("Enter the swedish word followed by the enlish word %d:\n", usedWords+1);
                        scanf("%s%s", wordsSwe[usedWords], wordsEng[usedWords]);
                        usedWords++;
                    } while (usedWords<WORDS);
                }
                else{
                    printf("Maximum words reached \n");
                }  
            }
            break;
        case 'q':
            printf("You have quit \n");
            break;
    
        default:
            printf("Enter a valid command (t, e, m, q): ");
            break;
    }
    } while (input!='q');
}