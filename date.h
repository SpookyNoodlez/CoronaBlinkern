#ifndef DATE_H
#define DATE_H


#include <stdbool.h>

typedef struct Date{
    int day;
    int month;
    int year;
}Date;


/**
 * Function checks if date1 is earlier than date2
 * @param date1 first date to check
 * @param date2 second date to check
 * @returns true if date1 is earlier and false otherwise
 * */
bool isEarlier(Date date1, Date date2);

/**
 * Function returns today's date
 * @returns The current date
 * */
Date getCurrentDate();

/**
 * Function returns a date 21 days earlier that the given date
 * @param date The date to go back from
 * @returns The new date
 * */
Date goBack(Date date);

#endif