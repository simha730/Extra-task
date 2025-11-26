#include <stdio.h>
#include <string.h>

#define MAX 1000

// Stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline (if present)
    str[strcspn(str, "\n")] = '\0';

    // Push all characters onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop characters to form the reversed string
    printf("Reversed string: ");
    while (top != -1) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}
