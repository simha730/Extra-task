#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure for a ticket node in the BST
typedef struct TicketNode {
int ticketID;
char issue[100];
struct TicketNode *left, *right;
} TicketNode;
// Function to create a new ticket node
TicketNode* createNode(int id, const char *issue) {
TicketNode *newNode = (TicketNode*)malloc(sizeof(TicketNode));
newNode->ticketID = id;
strcpy(newNode->issue, issue);
newNode->left = newNode->right = NULL;
return newNode;
}