#include <time.h>

#include "date.h"
#include "unittest.h"

Date goBack(Date Date)
{
    const int days = 21;
    int dayCount = Date.day - days;
    if (dayCount > 0)
    {
        Date.day = dayCount;
        return Date;
    }

    Date.month--;
    if (Date.month == 0)
    {
        Date.year--;
        Date.month = 12;
    }

    switch (Date.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        Date.day = 31 + dayCount;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        Date.day = 30 + dayCount;
        break;
    case 2:
        //leap year
        if (Date.year % 4 == 0)
        {
            Date.day = 29 + dayCount;
        }
        else
        {
            Date.day = 28 + dayCount;
        }
        break;
    }
    return Date;
}

Date getCurrentDate()
{
    time_t s;
    struct tm *current_time;

    s = time(NULL);

    current_time = localtime(&s);

    Date currentDate;
    currentDate.day = current_time->tm_mday;
    currentDate.month = current_time->tm_mon + 1;
    currentDate.year = current_time->tm_year + 1900;

    return currentDate;
}

bool isEarlier(Date date1, Date date2)
{
    //date1 earlier than date2
    if (date1.year < date2.year)
    {
        return true;
    }
    else if (date1.month < date2.month)
    {
        return true;
    }
    else if (date1.day < date2.day)
    {
        return true;
    }
    //date1 is later than date2 or same
    return false;
}