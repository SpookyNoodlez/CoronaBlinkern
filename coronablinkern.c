#include <stdio.h>
#include <time.h>
#include <stdbool.h>

//structs
struct Date
{
    int day;
    int month;
    int year;
} date;

struct DataPack
{
    struct Date contactDate;
    int idCode;
} dataPack;

//prototypes
int menu();
int open();
struct DataPack contact();
void alarm();

int main()
{
    while (true)
    {
        menu();
    }
}

int menu()
{
    int menuChoice;
    struct DataPack data;
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
        data = contact();
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

struct DataPack contact()
{
    struct DataPack pack;
    bool bad = true;

    printf("Code:\n");
    while (scanf("%d", &pack.idCode) != 1)
    {
        printf("Bad input!\n");
        fflush(stdin);
    }

    printf("År:\n");
    while (scanf("%d", &pack.contactDate.year) != 1)
    {
        printf("Bad input!\n");
        fflush(stdin);
    }

    while (bad)
    {
        bad = false;
        printf("Månad:\n");
        scanf("%d", &pack.contactDate.month);
        if (pack.contactDate.month > 12 || pack.contactDate.month < 1)
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
        scanf("%d", &pack.contactDate.day);

        if (pack.contactDate.day < 1)
        {
            bad = true;
        }
        else
        {
            switch (pack.contactDate.month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (pack.contactDate.day > 31)
                {
                    bad = true;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (pack.contactDate.day > 30)
                {
                    bad = true;
                }
                break;
            case 2:
                if (pack.contactDate.year % 4 == 0)
                { //skottår;
                    if (pack.contactDate.day > 29)
                    {
                        bad = true;
                    }
                }
                else
                {
                    if (pack.contactDate.day > 28)
                    {
                        bad = true;
                    }
                }
            default:
                break;
            }
        }

        if (bad)
        {
            printf("Bad input!\n");
            fflush(stdin);
        }
    }
}

void alarm()
{
    printf("VARNING\nKONTAKTA LÄKARE\n");
}