#include "linkedCodeList.h"
#include "unittest.h"

int main(){
    date d1 = {1,2,2021};
    bool good = false;
    struct node* node1 = makeNode(1234, d1);
    if(node1->code == 1234 &&
        node1->date.day == 1 &&
        node1->date.month == 2 &&
        node1->date.year == 2021){
            good = true;
        }

    TEST_CASE("Making a node")
    VERIFY(good, "Checking that the node holds the code 1234 and the date 1.2.2021")

    good = false;

    date d2 = {23,10,2001};
    struct node* node2 = makeNode(9876, d2);
    addNodeToList(node2, node1);
    if (node2->next->code == 9876){
        good = true;
    }
    
    TEST_CASE("Adding to list")
    VERIFY(good, "Checking that the node after the head holds the code 9876")
}