#include "linkedCodeList.h"

#include <stddef.h>




node* makeNode(int code, date date){
    node* result = malloc(sizeof(node));
    result->code = code;
    result->date = date;
    result->next = NULL;
    return result;
}