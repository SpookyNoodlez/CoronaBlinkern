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




//Här är felet tror jag
bool isExpired(date checkDate){
    time_t s, val = 1;
    struct tm* current_time;
    
    s = time(NULL);
    
    current_time = localtime(&s);

    date currentDate;
    currentDate.day = current_time->tm_mday;
    currentDate.month = current_time->tm_mon + 1;
    currentDate.year = current_time->tm_year + 1900;


    date expirationDate = goBack(currentDate);
    if(checkDate.year < expirationDate.year){
        return true;
    }
    else if(checkDate.month < expirationDate.month){
        return true;
    }
    else if(checkDate.day < expirationDate.day){
        return true;
    }
    return false;
}