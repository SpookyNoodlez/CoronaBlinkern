#include "date.h"
#include "unittest.h"
int main(){
    bool good = false;

    date d3 = {31,1,2021};
    date d4 = goBack(d3);
    if(d4.day == 10){
        good = true;
    }

    TEST_CASE("Go back only days")
    VERIFY(good, "Checking that day is 10")
    good = false;


    date d5 = {10,2,2021};
    date d6 = goBack(d5);
    if(d6.day == 20 && d6.month == 1){
        good = true;
    }

    TEST_CASE("Go back passed a month line")
    VERIFY(good, "Checking that day is 20 and month 1")
    good = false;


    date d7 = {10,1,2021};
    date d8 = goBack(d7);
    if(d8.day == 20 && d8.month == 12 && d8.year == 2020){
        good = true;
    }

    TEST_CASE("Go back passed a year line")
    VERIFY(good, "Checking that day is 20, month 12 and year is 2020")
    good = false;


    date d9 = {10,3,2024};
    date d10 = goBack(d9);
    if(d10.day == 18 && d10.month == 2){
        good = true;
    }

    TEST_CASE("Go back to February when not a leap year")
    VERIFY(good, "Checking that day is 18 and month is 2")
    good = false;

    date d11 = {10,3,2024};
    date d12 = goBack(d11);
    if(d12.day == 18 && d12.month == 2){
        good = true;
    }

    TEST_CASE("Go back to February on a leap year")
    VERIFY(good, "Checking that day is 17 and month is 2")
    good = false;

    //goBack works

    date d1 = {1,1,2021};
    date d2 = {1,2,2021};

    TEST_CASE("Expired date")
    VERIFY(isExpired(d1), "Checking that 1.1.2021 is expired")

    TEST_CASE("Recent date")
    VERIFY(!isExpired(d2), "Checking that 1.2.2021 is not expired")
}