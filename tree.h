#ifndef TREE_H
#define TREE_H

#include "date.h"

typedef struct TreeNode{
    date date;
    int code;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;


/**
 * Creates a new tree node without any connections
 * @param date The date to add to the tree
 * @param code The code to add to the tree
 * @returns A pointer to the created node
 * */
TreeNode* createNode(struct date date, int code);

#endif