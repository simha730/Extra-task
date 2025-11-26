#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int capacity;
    int *array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top];
}


/* Insert element into sorted stack (ascending order) */
void sortedInsert(Stack* stack, int item) {
    // Base case: stack empty OR top <= item
    if (isEmpty(stack) || peek(stack) <= item) {
        push(stack, item);
        return;
    }

    // Otherwise pop the top and recurse
    int temp = pop(stack);
    sortedInsert(stack, item);

    // Push the stored element back
    push(stack, temp);
}


/* Recursively sort the whole stack */
void sortStack(Stack* stack) {
    if (isEmpty(stack))
        return;

    int temp = pop(stack);
    sortStack(stack);

    sortedInsert(stack, temp);
}


/* Utility function to print a stack */
void printStack(Stack* stack) {
    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->array[i]);
    printf("\n");
}


/* Example usage */
int main() {
    Stack* stack = createStack(10);

    push(stack, 3);
    push(stack, 1);
    push(stack, 4);
    push(stack, 2);

    printf("Original stack:\n");
    printStack(stack);

    sortStack(stack);

    printf("Sorted stack (ascending):\n");
    printStack(stack);

    return 0;
}
