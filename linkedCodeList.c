#include "linkedCodeList.h"
#include "unittest.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

node* makeNode(int code, Date date, node* head){
    node* temp = (node*)malloc(sizeof(node));
    temp->code = code;
    temp->date = date;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
    }
    else{
        node* p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }

    return head;
}


void printList(node* head){
    node* temp = head;

    if(head != NULL){
        while(temp != NULL){
        printf("Informing people with the following codes:\n");
        printf("%d\n", temp->code);
        temp = temp->next;
        }
    }
    else{
        printf("You haven't passed anyone recently\n");
    }
}

bool compareNodes(node* n1, node* n2){
    if(n1->code == n2->code &&
        n1->date.day == n2->date.day &&
        n1->date.month == n2->date.month &&
        n1->date.year == n2->date.year){
        return true;
    }
    return false;
}

node *deleteNode(node* toDelete, node *head){
    node* current = head->next;
    node* previous = head;

    if (compareNodes(toDelete, head))
    { //if removing the first node
        head = current;
        free(previous);
    }
    else{
        while(!compareNodes(current, toDelete)){
            previous = current;
            current = current->next;
        }
        if(current->next == NULL){
            previous->next = NULL;
        }
        else{
            previous->next = current->next;
        }
        free(current);
    }

    return head;
}

node* clearOldEntries(node* head){
    node* current = head;
    while(current != NULL){
        if (isExpired(current->date)){
            head = deleteNode(current, head);
        }
        current = current->next;
    }
    return head;
}
