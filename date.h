#ifndef DATE_H
#define DATE_H


#include <stdbool.h>

typedef struct date{
    int day;
    int month;
    int year;
}date;

/**
 * Function returns true if the date given is older than 21 days
 * @param date the date to be checked
 * */
bool isExpired(date date);


/**
 * Function returns a date a 21 days in the past
 * @param date The date to go back from
 * @returns The new date
 * */
date goBack(date date);

#endif