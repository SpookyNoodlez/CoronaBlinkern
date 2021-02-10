#include <stdbool.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} date;


/**
 * Function returns true if the date given is older than 21 days
 * @param date the date to be checked
 * */
bool isExpired(date date);


/**
 * Function returns a date a certain amount of days in the past
 * @param days Amount of days to go back
 * @param date The date to go back from
 * @returns The new date
 * */
date goBack(int days, date date);