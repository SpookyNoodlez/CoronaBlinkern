#ifndef TREE_H
#define TREE_H

#include "date.h"

typedef struct TreeNode{
    Date date;
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
TreeNode* createNode(struct Date date, int code);


/**
 * Puts a node in the right place in the tree
 * @param root The root of the tree
 * @param date The date to add to the tree
 * @param code The code to add to the tree
 * @returns The new root node
 * */
TreeNode* insertNode(TreeNode* root, Date date, int code);

/**
 * Deletes a branch of the tree starting with the given parameter
 * @param p a pointer to the node where the deletion should start
 * */
void deleteBranch(TreeNode* p);

#endif