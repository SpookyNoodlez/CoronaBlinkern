#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "date.h"

treeNode* createNode(struct date date, int code){
    treeNode* result = malloc(sizeof(treeNode));
    if(result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->date = date;
        result->code = code;
    }
    return result;
}