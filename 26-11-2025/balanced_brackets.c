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
    return '\0';  // indicates underflow
}

// Function to check if brackets are matching pair
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        // If opening bracket, push to stack
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
        // If closing bracket, pop and check match
        else if (c == ')' || c == '}' || c == ']') {
            char topChar = pop();
            if (!isMatchingPair(topChar, c))
                return 0;  // mismatch or empty stack
        }
    }

    // Balanced if stack is empty in the end
    return (top == -1);
}

int main() {
    char str[MAX];

    printf("Enter a string of brackets: ");
    scanf("%s", str);

    if (isBalanced(str))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
