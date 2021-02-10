#include "date.h"

typedef struct node{
    int code;
    date date;
    struct node* next;
}node;

/**
 * Function adds a code to the end of the list
 * @param code The new code to add
 * @param date The date it was recorded on
 * @returns a pointer to the new head of the list
 * */
node* makeNode(int code, date date);


void addNodeToList(node* temp, node* head);


/**
 * Function removes entries in a list older than 21 days
 * */
void clearOldEntries();

/**
 * Function displays all saved entries to stdout
 * */
void printEntries();