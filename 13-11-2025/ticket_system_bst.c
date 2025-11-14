#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure for a ticket node in the BST
typedef struct TicketNode {
int ticketID;
char issue[100];
struct TicketNode *left, *right;
} TicketNode;