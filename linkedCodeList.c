#include "linkedCodeList.h"
#include "unittest.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

node* makeNode(int code, date date){
    node* result = malloc(sizeof(node));
    result->code = code;
    result->date = date;
    result->next = NULL;
    return result;
}

void addNodeToList(node* temp, node* head){
    temp->next = head;
    head = temp;
}

/*
void removeNode(node* temp){

}*/

void printList(node* head){
    node* temp = head;

    while(temp != NULL){
        printf("Informing people with the following codes:\n");
        printf("%d\n", temp->code);
        temp = temp->next;
    }
}


void clearOldEntries(node* head){
    node* current = head;
    node* previous = NULL;

    while(current != NULL){
        if (isExpired(current->date)){
            node* temp;
            if(previous == NULL){ //if removing the first node
                temp = head;
                head = head->next;
            }
            else{
                temp = current;
                previous->next = current->next;
            }
            free(temp);
        }

        previous = current;
        current = current->next;
    }
}
