#include <stdbool.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} date;


/**
 * Function returns true if the date given is older than 21 days
 * @param date the dateto be checked
 * */
bool isExpired(date date);