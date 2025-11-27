#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ---------------- Queue Implementation ----------------

typedef struct {
    int arr[MAX];
    int front, rear, size;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int isFull(Queue *q) {
    return q->size == MAX;
}

void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue overflow\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = x;
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }

    int val = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return val;
}

int front(Queue *q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->front];
}

// ---------------- Stack Using Two Queues ----------------

typedef struct {
    Queue q1, q2;
} Stack;

void initStack(Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// Costly Push: O(n)
void push(Stack *s, int x) {
    enqueue(&s->q2, x);

    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap q1 and q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Pop: O(1)
int pop(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

int top(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    return front(&s->q1);
}

int empty(Stack *s) {
    return isEmpty(&s->q1);
}

// ---------------- Main (Demo) ----------------

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top = %d\n", top(&s));   // 30
    printf("Pop = %d\n", pop(&s));   // 30
    printf("Top = %d\n", top(&s));   // 20

    return 0;
}
