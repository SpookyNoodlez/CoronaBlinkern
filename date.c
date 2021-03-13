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

int dateRelation(date date1, date date2){
    //same date
    if(date1.day == date2.day && 
    date1.month == date2.month &&
    date1.year == date2.year)
    {
        return 0;
    }
    //date1 later than date2


}





//Här är felet tror jag
bool isExpired(date checkDate){
    date currentDate = getCurrentDate();

    date expirationDate = goBack(currentDate);

    printf("Current date: %d.%d.%d\n", currentDate.day, currentDate.month, currentDate.year);
    printf("Expiration date: %d.%d.%d\n\n", expirationDate.day, expirationDate.month, expirationDate.year);

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