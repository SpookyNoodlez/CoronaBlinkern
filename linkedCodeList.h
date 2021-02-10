#include "date.h"

typedef struct node{
    int code;
    date date;
    struct node* next;
}node_t;

/**
 * Function adds a code to the list
 * @param code The new code to add
 * */
void clearOldEntries(int code);

/**
 * Function removes entries in a list older than 21 days
 * */
void clearOldEntries();

/**
 * Function displays all saved entries to stdout
 * */
void printEntries();