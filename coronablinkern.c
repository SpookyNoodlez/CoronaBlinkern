#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "date.h"
#include "tree.h"

#define MAX 256

//prototypes
void menu();
void open();
void contact();
void alarm();

int main()
{
    //TODO
    //Skapa ett binärt träd med utgångsdatumet som rot
    //Ladda in från fil
    //Sortera gamla datum till vänster nya till höger

    //Skapa ett binärt träd med utgångsdatumet som rot
    date currentDate = getCurrentDate();
    date expirationDate = goBack(currentDate);
    TreeNode *root = createNode(expirationDate, 000000);

    //Ladda in data från filen på rätt sida om trädet
    FILE *fp = fopen("data.txt", "r");
    int loadedCode;
    date loadedDate;
    int i = 0;
    TreeNode *checkNode = root;
    while (!feof(fp))
    {
        fscanf(fp, "%d|%d.%d.%d ", &loadedCode, &loadedDate.day, &loadedDate.month, &loadedDate.year);
        if (!isExpired(loadedDate))
        {
            i++;
            while (checkNode != NULL)//USE addData() here
            {
                if (dateRelation(checkNode->date, loadedDate) == -1)
                {
                    checkNode = checkNode->left;
                }
                else
                {
                    checkNode = checkNode->right;
                }
            }
            checkNode = createNode(loadedDate, loadedCode);

            printf("Entry %d:\n", i);
            printf("Code: %d\n", loadedCode);
            printf("Date: %d.%d.%d\n\n", loadedDate.day, loadedDate.month, loadedDate.year);
        }
    }
    printf("%d entries loaded from file\n", i);

    fclose(fp);
    fp = fopen("data.txt", "w");


    menu(root);
}

//main menu
void menu(TreeNode* root)
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
            contact(root);
            break;
        case 3:
            alarm();
            break;
        case 4:
            saveToFile();
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

    //Delete old entries
    FILE *fp = fopen("data.txt", "r+");
    int trashCode;
    date checkDate;
    bool toRemove[100];
    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%d|%d.%d.%d ", &trashCode, &checkDate.day, &checkDate.month, &checkDate.year);
        bool expired = isExpired(checkDate);
        if (expired)
        {
            toRemove[i] = true;
        }
        i++;
    }
    fclose(fp);

    //deleteAtPositions(toRemove);

    //print remaining
    fp = fopen("data.txt", "r");
    int code, day, month, year;
    i = 1;
    while (!feof(fp))
    {
        fscanf(fp, "%d|%d.%d.%d ", &code, &day, &month, &year);
        printf("Entry %d:\n", i);
        printf("Code: %d\n", code);
        printf("Date: %d.%d.%d\n\n", day, month, year);

        i++;
    }

    fclose(fp);
}

//For when passing anyone
void contact(TreeNode* root)
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

        if (!bad)//ÄNDRA HÄR
        {
            TreeNode* checkNode = root;
            while (checkNode != NULL)//USE addData() here
            {
                if (dateRelation(checkNode->date, date) == -1)
                {
                    checkNode = checkNode->left;
                }
                else
                {
                    checkNode = checkNode->right;
                }
            }
            checkNode = createNode(date, code);
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