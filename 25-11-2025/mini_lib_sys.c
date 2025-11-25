#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// -------- Node Structure --------
typedef struct Node {
    char title[100];
    char author[100];
    struct Node* next;
} Node;

// -------- Hash Table --------
Node* hashTable[TABLE_SIZE];

// -------- Hash Function --------
unsigned int hash(char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % TABLE_SIZE;
}

// -------- Insert or Update Book --------
void addBook(char* title, char* author) {
    unsigned int index = hash(title);
    Node* curr = hashTable[index];

    // If book already exists → update
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            strcpy(curr->author, author);
            printf("Updated: \"%s\" now by %s\n", title, author);
            return;
        }
        curr = curr->next;
    }

    // New book → insert at head
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("Added: \"%s\" by %s\n", title, author);
}

// -------- Search Book --------
char* searchBook(char* title) {
    unsigned int index = hash(title);
    Node* curr = hashTable[index];

    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            return curr->author;
        }
        curr = curr->next;
    }
    return "Book not found";
}

// -------- Main Function (Example) --------
int main() {
    addBook("Dune", "Frank Herbert");
    addBook("1984", "George Orwell");

    printf("Search Dune: %s\n", searchBook("Dune"));

    addBook("Dune", "F. Herbert");   // update
    printf("Search Dune: %s\n", searchBook("Dune"));

    return 0;
}
