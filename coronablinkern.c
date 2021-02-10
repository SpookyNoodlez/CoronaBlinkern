#include <stdio.h>
#include <stdbool.h>

#include "date.h"
#include "linkedCodeList.h"


//prototypes
int menu();
int open();
void contact();
void alarm();

int main()
{
    
    while (true)
    {
        menu();
    }
}

//main menu
int menu()
{
    node head;
    int menuChoice;
    int openCode;

    printf("\nCORONA BLINKERN\n");
    printf("1. Ange öppningskod\n");
    printf("2. Ta emot kod\n");
    printf("3. Smittalarm\n");
    scanf("%d", &menuChoice);

    bool bad = false;
    switch (menuChoice)
    {
    case 1:
        openCode = open();
        break;
    case 2:
        contact(&head);
        break;
    case 3:
        alarm();
        break;

    default:
        bad = true;
        break;
    }

    if (bad)
    {
        printf("Bad input!\n");
        fflush(stdin);
    }
}

//for when sick
int open()
{
    int code;
    printf("Code received:");
    while (scanf("%d", &code) != 1)
    {
        printf("Bad input!\n");
        fflush(stdin);
    }
    return code;
}

//for when passing anyone
void contact(node* headptr)
{
    int code;
    date date;

    bool bad = true;

    printf("Code:\n");
    while (scanf("%d", &code) != 1)
    {
        printf("Bad input!\n");
        fflush(stdin);
    }

    printf("År:\n");
    while (scanf("%d", &date.year) != 1)
    {
        printf("Bad input!\n");
        fflush(stdin);
    }

    while (bad)
    {
        bad = false;
        printf("Månad:\n");
        scanf("%d", &date.month);
        if (date.month > 12 || date.month < 1)
        {
            bad = true;
            printf("Bad input!\n");
            fflush(stdin);
        }
    }

    bad = true;

    while (bad)
    {
        bad = false;
        printf("Dag:\n");
        scanf("%d", &date.day);

        if (date.day < 1)
        {
            bad = true;
        }
        else
        {
            switch (date.month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (date.day > 31)
                {
                    bad = true;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (date.day > 30)
                {
                    bad = true;
                }
                break;
            case 2:
                if (date.year % 4 == 0){//leap year
                    if (date.day > 29)
                    {
                        bad = true;
                    }
                }
                else
                {
                    if (date.day > 28){
                        bad = true;
                    }
                }
                break;
            }
        }

        if (bad)
        {
            printf("Bad input!\n");
            fflush(stdin);
        }
    }

    addNodeToList(makeNode(code, date), headptr);
}

//for when passing infected
void alarm()
{
    printf("VARNING\nKONTAKTA LÄKARE\n");
}