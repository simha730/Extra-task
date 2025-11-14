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
// Search for a ticket by ID
TicketNode* searchTicket(TicketNode *root, int id) {
if (root == NULL || root->ticketID == id)
return root;


if (id < root->ticketID)
return searchTicket(root->left, id);


return searchTicket(root->right, id);
}
// Find the inorder successor (minimum value node)
TicketNode* findMin(TicketNode *node) {
while (node && node->left != NULL)
node = node->left;
return node;
}