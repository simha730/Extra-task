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
// Insert a ticket into the BST
TicketNode* insertTicket(TicketNode *root, int id, const char *issue) {
if (root == NULL) {
printf("Ticket Created: ID=%d, Issue=%s\n", id, issue);
return createNode(id, issue);
}


if (id < root->ticketID)
root->left = insertTicket(root->left, id, issue);
else if (id > root->ticketID)
root->right = insertTicket(root->right, id, issue);
else
printf("Ticket ID %d already exists!\n", id);


return root;
}