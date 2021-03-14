#ifndef FILE_H
#define FILE_H

#include "date.h"

/**
 * Inserts all entries from the data.txt file into the binary tree
 * @param root a pointer to the root of the tree
 * @returns a pointer to the root of the tree
 * */
TreeNode* loadFromFile(TreeNode* root);

#endif