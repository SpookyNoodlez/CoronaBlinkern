#include <stdio.h>

#include "date.h"
#include "tree.h"

TreeNode *loadFile(TreeNode *root)
{
    Date loadedDate;
    int loadedCode;
    FILE *fp = fopen("data.txt", "r");

    int i = 0;
    printf("Loading entries from file...\n");
    while (!feof(fp))
    {
        int control = fscanf(fp, "%d|%d.%d.%d ", &loadedCode, &loadedDate.day, &loadedDate.month, &loadedDate.year);
        if (control == 4)
        {
            root = insertNode(root, loadedDate, loadedCode);
            i++;
            printf("Entry %d:\n", i);
            printf("Code: %d\n", loadedCode);
            printf("Date: %d.%d.%d\n\n", loadedDate.day, loadedDate.month, loadedDate.year);
        }
    }
    printf("%d entries loaded from file\n", i);

    fclose(fp);

    return root;
}

void saveToFile(TreeNode *treePtr, FILE *filePtr)
{

    if (treePtr == NULL)
    {
        return;
    }
    saveToFile(treePtr->left, filePtr);
    saveToFile(treePtr->right, filePtr);

    fprintf(filePtr, "%d|%d.%d.%d\n", treePtr->code, treePtr->date.day, treePtr->date.month, treePtr->date.year);
}