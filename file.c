#include <stdio.h>

#include "date.h"
#include "tree.h"

TreeNode* loadFromFile(TreeNode* root){
    date loadedDate;
    int loadedCode;
    FILE *fp = fopen("data.txt", "r");
    
    int i = 0;
    printf("Loading entries from file...\n");
    while (!feof(fp))
    {
        fscanf(fp, "%d|%d.%d.%d ", &loadedCode, &loadedDate.day, &loadedDate.month, &loadedDate.year);

        root = InsertNode(root, loadedDate, loadedCode);
        i++;
        printf("Entry %d:\n", i);
        printf("Code: %d\n", loadedCode);
        printf("Date: %d.%d.%d\n\n", loadedDate.day, loadedDate.month, loadedDate.year);
    }
    printf("%d entries loaded from file\n", i);

    fclose(fp);

    return root;
}