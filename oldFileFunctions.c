#include <stdio.h>
#include <stdbool.h>

#define MAX 256

void deleteAtPositions(bool* toDelete){
        //FOR DELETING THE STUFF
        FILE *fptr1 = fopen("data.txt", "r");
        if (!fptr1)
        {
            printf(" File not found or unable to open the input file!!\n");
            return;
        }
        FILE *tempFptr = fopen("temp.txt", "w"); //open a temporary file in write mode
        if (!tempFptr)
        {
            printf("Unable to open a temporary file to write!!\n");
            fclose(fptr1);
            return;
        }

        //copy all contents to the temporary file except the old entries
        char str[80];
        int i = 0;
        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1))
            {
                //only transfer the recent entries
                if (!toDelete[i])
                {
                    fprintf(tempFptr, "%s", str);
                }
                i++;
            }
        }
        fclose(fptr1);
        fclose(tempFptr);

        //Both fail
        int removeStatus = remove("data.txt");              // remove the original file
        if(removeStatus == 0){
            printf("File deleted successfully\n");
        }
        else{
            printf("File NOT deleted\n");
        }
        int renameStatus = rename("temp.txt", "data.txt"); // rename the temporary file to original name
        if(renameStatus == 0){
            printf("File renamed successfully\n");
        }
        else{
            printf("File NOT renamed\n");
        }
        printf("\n");
    }