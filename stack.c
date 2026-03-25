#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push operation
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Error: Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->items[++(s->top)] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Pop operation
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack underflow! Cannot pop from empty stack\n");
        return -1;
    }
    int value = s->items[s->top--];
    printf("Popped %d from the stack\n", value);
    return value;
}

// Peek operation
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Cannot peek at empty stack\n");
        return -1;
    }
    return s->items[s->top];
}

// Display stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Get stack size
int size(Stack *s) {
    return s->top + 1;
}

// Main function to demonstrate
int main() {
    Stack stack;
    initStack(&stack);
    
    printf("--- Pushing elements ---\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);
    
    printf("\n--- Peeking ---\n");
    printf("Top element is: %d\n", peek(&stack));
    
    printf("\n--- Popping elements ---\n");
    pop(&stack);
    display(&stack);
    
    pop(&stack);
    display(&stack);
    
    printf("\n--- Popping from empty stack ---\n");
    pop(&stack);
    pop(&stack);
    
    printf("\nIs stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");
    printf("Stack size: %d\n", size(&stack));
    
    return 0;
}