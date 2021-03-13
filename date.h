#ifndef DATE_H
#define DATE_H


#include <stdbool.h>

typedef struct date{
    int day;
    int month;
    int year;
}date;


/**
 * Function checks which date is earlier
 * @param date1 first date to check
 * @param date2 second date to check
 * @returns 0 if dates are the same, 1 if date1 is later, -1 if date1 is earlier
 * */
int dateRelation(date date1, date date2);

/**
 * Function returns true if the date given is older than 21 days
 * @param date the date to be checked
 * */
bool isExpired(date date);

/**
 * Function returns today's date
 * @returns The current date
 * */
date getCurrentDate();

/**
 * Function returns a date 21 days earlier that the given date
 * @param date The date to go back from
 * @returns The new date
 * */
date goBack(date date);

#endif