#include <stdio.h>

#include "date.h"
#include "tree.h"

TreeNode* loadFile(TreeNode* root){
    Date loadedDate;
    int loadedCode;
    FILE *fp = fopen("data.txt", "r");
    
    int i = 0;
    printf("Loading entries from file...\n");
    while (!feof(fp)) //skräpdata om tom fil?
    {
        int control = fscanf(fp, "%d|%d.%d.%d ", &loadedCode, &loadedDate.day, &loadedDate.month, &loadedDate.year);
        if(control == 4){
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