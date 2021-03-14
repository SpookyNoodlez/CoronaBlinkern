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

void addData(TreeNode* checkNode){//JOBBAR HÄR
    while (checkNode != NULL)
            {
                if (dateRelation(checkNode->date, loadedDate) == -1)
                {
                    checkNode = checkNode->left;
                }
                else
                {
                    checkNode = checkNode->right;
                }
            }
            checkNode = createNode(loadedDate, loadedCode);

}