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

/**
 * Function should probably be combined with makeNode but it adds a node to a list
 * @param temp The new node to add
 * @param head Current head of the list
 * */
void addNodeToList(node* temp, node* head);


/**
 * Function removes entries in a list older than 21 days
 * @param head Current head of the list
 * */
void clearOldEntries(node* head);

/**
 * Function displays the codes of all saved nodes to stdout
 * @param head Current head of the list
 * */
void printList(node* head);