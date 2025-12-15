#include <stdio.h>

#define SIZE 5

int stack[SIZE], top = -1;
int queue[SIZE], front = 0, rear = -1;

/* Stack operations */
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

/* Queue operations */
void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int main() {
    // Push elements into stack
    push(10);
    push(20);
    push(30);
    push(40);

    printf("Original Stack:\n");
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    // Step 1: Stack → Queue
    while(top != -1)
        enqueue(pop());

    // Step 2: Queue → Stack
    while(front <= rear)
        push(dequeue());

    printf("\nReversed Stack:\n");
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}
