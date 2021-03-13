#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "date.h"

TreeNode* createNode(struct date date, int code){
    TreeNode* result = malloc(sizeof(TreeNode));
    if(result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->date = date;
        result->code = code;
    }
    return result;
}