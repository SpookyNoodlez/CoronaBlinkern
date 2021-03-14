#include <time.h>

#include "date.h"
#include "unittest.h"
//#include <dos.h> 

date goBack(date date){
    const int days = 21;
    int dayCount = date.day - days;
    if(dayCount > 0){
        date.day = dayCount;
        return date;
    }
    
    date.month--;
    if(date.month == 0){
        date.year--;
        date.month = 12;
    }

    switch (date.month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            date.day = 31 + dayCount;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            date.day = 30 + dayCount;
            break;
        case 2:
            //leap year
            if (date.year % 4 == 0)
            {
                date.day = 29 + dayCount;
            }
            else
            {
                date.day = 28 + dayCount;
            }
            break;
    }
    return date;
}

date getCurrentDate(){
    time_t s;
    struct tm* current_time;
    
    s = time(NULL);
    
    current_time = localtime(&s);

    date currentDate;
    currentDate.day = current_time->tm_mday;
    currentDate.month = current_time->tm_mon + 1;
    currentDate.year = current_time->tm_year + 1900;

    return currentDate;
}

bool isEarlier(date date1, date date2){
    //date1 earlier than date2
    if(date1.year < date2.year){
        return true;
    }
    else if(date1.month < date2.month){
        return true;
    }
    else if(date1.day < date2.day){
        return true;
    }
    //date1 is later than date2 or same
    return false;
}