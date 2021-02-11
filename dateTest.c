#include "date.h"
#include "unittest.h"
int main(){
    date d1 = {1,1,2021};
    date d2 = {1,2,2021};


    


    TEST_CASE("Expired date")
    VERIFY(isExpired(d1), "Checking that 1.1.2021 is expired")

    TEST_CASE("Recent date")
    VERIFY(!isExpired(d2), "Checking that 1.2.2021 is not expired")
}