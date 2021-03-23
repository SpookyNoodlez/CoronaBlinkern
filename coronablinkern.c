#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "date.h"
#include "tree.h"
#include "file.h"

#define MAX 256

//prototypes
void menu(TreeNode **rootPtr);
void open(TreeNode **rootPtr);
void contact(TreeNode **rootPtr);
void alarm();
void quit(TreeNode **rootPtr);

int main(int argc, char *argv[])
{
    printf("%s", argv[1]);
    if (argc > 1)
    { //command line mode
        if (strcmp(argv[1], "add") == 0)
        { //add entry
            int code = atoi(argv[2]);
            Date date;
            char *dateString = argv[3];
            int control = sscanf(dateString, "%d.%d.%d", &date.day, &date.month, &date.year);
       /*     if (control != 3)
            { //needs more datacheck
                exit(1);
            }*/
            FILE *fp = fopen("data.txt", "a");
            fprintf(fp, "%d|%d.%d.%d", code, date.day, date.month, date.year);
            fclose(fp);
            exit(0);
        }
        else if (strcmp(argv[1], "sick") == 0)
        {
            printf("code %s received\n", argv[2]);
            exit(0);
        }
        else if (strcmp(argv[1], "check") == 0)
        {
            int code;
            Date date;
            FILE *fp = fopen("data.txt", "r");
            fscanf(fp, "%d|%d.%d.%d", &code, &date.day, &date.month, &date.year);
            if (code == atoi(argv[2]))
            {
                printf("Code is in file\n");
            }
            else
            {
                printf("Code is not in file\n");
            }
            fclose(fp);
            exit(0);
        }
        else if (strcmp(argv[1], "help") == 0)
        {
            printf("COMMANDS\n");
            printf("add code|year.month.day - Adds an entry to the file\n");
            printf("sick opencode - Nothing really\n");
            printf("check code - Checks if the code is in the file\n");
            exit(0);
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    //Skapa ett binärt träd med utgångsdatumet som rot
    Date currentDate = getCurrentDate();
    Date expirationDate = goBack(currentDate);
    TreeNode *root = NULL;
    root = insertNode(root, expirationDate, 0);
    //Ladda all existerande data från filen till trädet
    root = loadFile(root);

    menu(&root); //hmmmmm
}

//main menu
void menu(TreeNode **rootPtr)
{
    while (true)
    {
        int menuChoice;

        printf("\nCORONA BLINKERN\n");
        printf("1. I have an initialisation code\n");
        printf("2. Receive bluetooth code\n");
        printf("3. Infection alarm\n");
        printf("4. Quit\n");
        printf("5. Print tree (debug)\n");
        scanf("%d", &menuChoice);

        bool bad = false;
        switch (menuChoice)
        {
        case 1:
            open(rootPtr); //hmmmmm
            break;
        case 2:
            contact(rootPtr); //hmmmmm
            break;
        case 3:
            alarm();
            break;
        case 4:
            quit(rootPtr); //hmmmmm
            break;
        case 5:
            printBranch(*rootPtr);
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
void open(TreeNode **rootPtr)
{
    int openCode;
    printf("Enter code:");
    while (scanf("%d", &openCode) != 1)
    {
        printf("Bad input!\n");
        fflush(stdin);
    }
    printf("Code %d received\n\n", openCode);

    deleteBranch((*rootPtr)->left);
    (*rootPtr)->left = NULL;
    printBranch((*rootPtr)->right);
}

//For when passing anyone
void contact(TreeNode **rootPtr)
{
    int code;
    Date date;

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

//Save and quit
void quit(TreeNode **rootPtr)
{
    FILE *fp = fopen("data.txt", "w");
    saveToFile((*rootPtr)->right, fp);
    fclose(fp);
    exit(0);
}