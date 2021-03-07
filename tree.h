#include "date.h"

typedef struct treeNode{
    date date;
    int code;
    treeNode* left;
    treeNode* right;
}treeNode;


/**
 * Creates a new tree node without any connections
 * @param date The date to add to the tree
 * @param code The code to add to the tree
 * @returns A pointer to the created node
 * */
treeNode* createNode(struct date date, int code);