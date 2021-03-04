#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "date.h"

#define MAX 256

//prototypes
void menu();
void open();
void contact();
void alarm();
void deleteAtPositions(bool* toDelete);

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
        open();
        break;
    case 2:
        contact();
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

void deleteAtPositions(bool* toDelete){
    //FOR DELETING THE STUFF
    FILE *fptr1 = fopen("data.txt", "r");
    if (!fptr1)
    {
        printf(" File not found or unable to open the input file!!\n");
        return;
    }
    FILE *tempFptr = fopen("temp.txt", "w"); //open a temporary file in write mode
    if (!tempFptr)
    {
        printf("Unable to open a temporary file to write!!\n");
        fclose(fptr1);
        return;
    }

    //copy all contents to the temporary file except the old entries
    char str[80];
    int i = 0;
    while (!feof(fptr1))
    {
        strcpy(str, "\0");
        fgets(str, MAX, fptr1);
        if (!feof(fptr1))
        {
            //only transfer the recent entries
            if (!toDelete[i])
            {
                fprintf(tempFptr, "%s", str);
            }
            i++;
        }
    }
    fclose(fptr1);
    fclose(tempFptr);

    //Both fail
    int removeStatus = remove("data.txt");              // remove the original file
    if(removeStatus == 0){
        printf("File deleted successfully\n");
    }
    else{
        printf("File NOT deleted\n");
    }
    int renameStatus = rename("temp.txt", "data.txt"); // rename the temporary file to original name
    if(renameStatus == 0){
        printf("File renamed successfully\n");
    }
    else{
        printf("File NOT renamed\n");
    }
    printf("\n");
}


//For when sick
void open()
{
    //Krashar här av någon anledning
    int openCode;
    printf("Enter code:");
    while (scanf("%d", &openCode) != 1){
        printf("Bad input!\n");
        fflush(stdin);
    }
    printf("Code %d received\n\n", openCode);


    //Delete old entries
    FILE* fp = fopen("data.txt", "r+");
    int trashCode;
    date checkDate;
    bool toRemove[100];
    int i = 0;
    while (!feof(fp)){
        fscanf(fp, "%d|%d.%d.%d ", &trashCode, &checkDate.day, &checkDate.month, &checkDate.year);
        bool expired = isExpired(checkDate);
        if(expired){
            toRemove[i] = true;
        }
        i++;
    }
    fclose(fp);

    deleteAtPositions(toRemove);
    


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
void contact()
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
            //open file for appending
            FILE *fp = fopen("data.txt", "a");
            //add data to file
            int result = fprintf(fp, "%d|%d.%d.%d\n", code, date.day, date.month, date.year);
            if (result < 4)
            {
                printf("failed");
            }
            //close file
            fclose(fp);
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