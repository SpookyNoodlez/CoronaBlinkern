#ifndef FILE_H
#define FILE_H

#include "date.h"

/**
 * Inserts all entries from the data.txt file into the binary tree
 * @param root a pointer to the root of the tree
 * @returns a pointer to the root of the tree
 * */
TreeNode* loadFile(TreeNode* root);

/**
 * Saves all entries from the node onward to the data.txt file
 * @param treePtr The node to start saving from
 * @param filePtr A file opened in write mode
 * */
void saveToFile(TreeNode* treePtr, FILE* filePtr);

#endif