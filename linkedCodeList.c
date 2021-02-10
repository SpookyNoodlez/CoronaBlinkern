#include "linkedCodeList.h"

#include <stddef.h>




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

void printList(node* head){
    node* temp = head;

    while(temp != NULL){
        printf("%d\n", temp->code);
        temp = temp->next;
    }
}