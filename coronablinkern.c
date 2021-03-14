#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "date.h"
#include "tree.h"
#include "file.h"

#define MAX 256

//prototypes
void menu();
void open();
void contact();
void alarm();

int main()
{
    //Skapa ett binärt träd med utgångsdatumet som rot
    date currentDate = getCurrentDate();
    date expirationDate = goBack(currentDate);
    TreeNode *root = insertNode(root, expirationDate, 0);
    //Ladda all existerande data från filen till trädet
    root = loadFile(root);

    menu(root);
}

//main menu
void menu(TreeNode **rootPtr)
{
    bool loop = true;
    while (loop)
    {
        int menuChoice;

        printf("\nCORONA BLINKERN\n");
        printf("1. I have an initialisation code\n");
        printf("2. Receive bluetooth code\n");
        printf("3. Infection alarm\n");
        printf("4. Quit\n");
        scanf("%d", &menuChoice);

        bool bad = false;
        switch (menuChoice)
        {
        case 1:
            open();
            break;
        case 2:
            contact(rootPtr);
            break;
        case 3:
            alarm();
            break;
        case 4:
            //saveToFile();
            loop = false;
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
}

//For when sick
void open()
{
    int openCode;
    printf("Enter code:");
    while (scanf("%d", &openCode) != 1)
    {
        printf("Bad input!\n");
        fflush(stdin);
    }
    printf("Code %d received\n\n", openCode);

    //JOBBAR HÄR
}

//For when passing anyone
void contact(TreeNode **rootPtr)
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

    printf("Year:\n");
    while (scanf("%d", &date.year) != 1)
    {
        printf("Bad input!\n");
        fflush(stdin);
    }

    while (bad)
    {
        bad = false;
        printf("Month:\n");
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
                if (date.year % 4 == 0)
                { //leap year
                    if (date.day > 29)
                    {
                        bad = true;
                    }
                }
                else
                {
                    if (date.day > 28)
                    {
                        bad = true;
                    }
                }
                break;
            }
        }

        if (!bad)
        {
            (*rootPtr) = insertNode((*rootPtr), date, code);
        }
        else
        {
            printf("Bad input!\n");
            fflush(stdin);
        }
    }
}

//For when passing infected
void alarm()
{
    printf("VARNING\nKONTAKTA LÄKARE\n");
}