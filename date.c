#include "date.h"

//#include <dos.h> 


date goBack(int days, date date){
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



bool isExpired(date date){
    //Until I figure out time.h
    struct date currentDate = {11,2,2021};
    struct date expirationDate = goBack(21, currentDate); 
    if(date.year<expirationDate.year){
        return true;
    }
    else if(date.month<expirationDate.month){
        return true;
    }
    else if(date.day<expirationDate.day){
        return true;
    }
    return false;
}