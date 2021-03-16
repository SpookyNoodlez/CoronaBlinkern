#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "date.h"

TreeNode *createNode(struct Date date, int code)
{
    TreeNode *result = malloc(sizeof(TreeNode));
    if (result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
        result->date = date;
        result->code = code;
    }
    return result;
}

TreeNode* insertNode(TreeNode* root, Date date, int code)
{
    if(root == NULL){ //landed in an empty node
        root = createNode(date, code);
    }
    else if(isEarlier(date, root->date)){
        root->left = insertNode(root->left, date, code); //recursive funktion call
    }
    else{
        root->right = insertNode(root->right, date, code); //recursive funktion call
    }

    return root;
}

TreeNode* deleteOld(TreeNode* root){
    
}