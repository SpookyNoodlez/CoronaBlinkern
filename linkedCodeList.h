#ifndef LINKEDCODELIST_H
#define LINKEDCODELIST_H

#include "date.h"

typedef struct node{
    int code;
    Date date;
    struct node* next;
}node;

/**
 * Function adds a code to the end of the list
 * @param code The new code to add
 * @param date The date it was recorded on
 * @param head Current head of the list
 * @returns a pointer to the new head of the list
 * */
node* makeNode(int code, Date date, node* head);

/**
 * Function removes entries in a list older than 21 days
 * @param head Current head of the list
 * */
node* clearOldEntries(node* head);

/**
 * Function displays the codes of all saved nodes to stdout
 * @param head Current head of the list
 * */
void printList(node* head);

#endif