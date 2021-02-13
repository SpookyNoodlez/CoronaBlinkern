#include <stdio.h>
#include <stdbool.h>

#include "date.h"
#include "linkedCodeList.h"


//prototypes
void menu();
node* open();
node* contact();
void alarm();

int main()
{
    while (true)
    {
        menu();
    }
}

//main menu
void menu()
{
    node* head = NULL;
    int menuChoice;

    printf("\nCORONA BLINKERN\n");
    printf("1. I have an initialisation code\n");
    printf("2. Receive bluetooth code\n");
    printf("3. Infection alarm\n");
    scanf("%d", &menuChoice);

    bool bad = false;
    switch (menuChoice)
    {
    case 1:
        head = open(&head);
        break;
    case 2:
        head = contact(&head);
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

//For when sick
node* open(node* head)
{
    int openCode;
    printf("Enter code:");
    while (scanf("%d", &openCode) != 1){
        printf("Bad input!\n");
        fflush(stdin);
    }
    printf("Code %d received",openCode);

    head = clearOldEntries(head);
    printList(head);

    return head;
}

//For when passing anyone
node* contact(node* head)
{
    int code;
    date date;

    bool bad = true;

    printf("Code:\n");
    while (scanf("%d", &code) != 1){
        printf("Bad input!\n");
        fflush(stdin);
    }

    printf("Year:\n");
    while (scanf("%d", &date.year) != 1){
        printf("Bad input!\n");
        fflush(stdin);
    }

    while (bad)
    {
        bad = false;
        printf("Month:\n");
        scanf("%d", &date.month);
        if (date.month > 12 || date.month < 1){
            bad = true;
            printf("Bad input!\n");
            fflush(stdin);
        }
    }

    bad = true;

    while (bad){
        bad = false;
        printf("Day:\n");
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

        if (bad){
            printf("Bad input!\n");
            fflush(stdin);
        }
    }

    head = makeNode(code, date, head);
    return head;
}

//For when passing infected
void alarm()
{
    printf("VARNING\nKONTAKTA LÄKARE\n");
}