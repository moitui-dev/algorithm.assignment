#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 1000000  // For large input testing

// Stack structure
typedef struct {
    int *items;      // Dynamic array
    int top;         // Index of top element
    int capacity;    // Maximum size
} Stack;

// Metrics tracking
typedef struct {
    int push_count;
    int pop_count;
    int peek_count;
    int comparisons;
} Metrics;

Metrics metrics = {0, 0, 0, 0};

// Function prototypes
Stack* createStack(int capacity);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
bool isEmpty(Stack *s);
bool isFull(Stack *s);
int size(Stack *s);
void display(Stack *s);
void freeStack(Stack *s);
void resetMetrics();
void printMetrics();
void runTests();

// Create a new stack
Stack* createStack(int capacity) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    s->items = (int*)malloc(capacity * sizeof(int));
    if (s->items == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = capacity;
    return s;
}

// Check if stack is empty
bool isEmpty(Stack *s) {
    metrics.comparisons++;
    return s->top == -1;
}

// Check if stack is full
bool isFull(Stack *s) {
    metrics.comparisons++;
    return s->top == s->capacity - 1;
}

// Push operation - O(1)
void push(Stack *s, int value) {
    metrics.push_count++;
    if (isFull(s)) {
        printf("Error: Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->items[++(s->top)] = value;
}

// Pop operation - O(1)
int pop(Stack *s) {
    metrics.pop_count++;
    if (isEmpty(s)) {
        printf("Error: Stack underflow! Cannot pop from empty stack\n");
        return -1;
    }
    return s->items[s->top--];
}

// Peek operation - O(1)
int peek(Stack *s) {
    metrics.peek_count++;
    if (isEmpty(s)) {
        printf("Error: Cannot peek at empty stack\n");
        return -1;
    }
    return s->items[s->top];
}

// Get stack size - O(1)
int size(Stack *s) {
    return s->top + 1;
}

// Display stack - O(n)
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

// Free stack memory
void freeStack(Stack *s) {
    free(s->items);
    free(s);
}

// Reset metrics
void resetMetrics() {
    metrics.push_count = 0;
    metrics.pop_count = 0;
    metrics.peek_count = 0;
    metrics.comparisons = 0;
}

// Print metrics
void printMetrics() {
    printf("\n--- Performance Metrics ---\n");
    printf("Push operations: %d\n", metrics.push_count);
    printf("Pop operations: %d\n", metrics.pop_count);
    printf("Peek operations: %d\n", metrics.peek_count);
    printf("Comparisons: %d\n", metrics.comparisons);
    printf("Total operations: %d\n", 
           metrics.push_count + metrics.pop_count + metrics.peek_count + metrics.comparisons);
}

// Step-by-step demonstration
void demonstrateStepByStep() {
    printf("\n========================================\n");
    printf("STEP-BY-STEP DEMONSTRATION\n");
    printf("========================================\n\n");
    
    Stack *s = createStack(10);
    resetMetrics();
    
    printf("Step 1: Initialize empty stack\n");
    printf("Stack: ");
    display(s);
    printf("Stack size: %d\n\n", size(s));
    
    printf("Step 2: Push 10 onto stack\n");
    push(s, 10);
    printf("Stack: ");
    display(s);
    printf("Top element (peek): %d\n", peek(s));
    printf("Stack size: %d\n\n", size(s));
    
    printf("Step 3: Push 20 onto stack\n");
    push(s, 20);
    printf("Stack: ");
    display(s);
    printf("Top element (peek): %d\n", peek(s));
    printf("Stack size: %d\n\n", size(s));
    
    printf("Step 4: Push 30 onto stack\n");
    push(s, 30);
    printf("Stack: ");
    display(s);
    printf("Top element (peek): %d\n", peek(s));
    printf("Stack size: %d\n\n", size(s));
    
    printf("Step 5: Pop element from stack\n");
    int popped = pop(s);
    printf("Popped value: %d\n", popped);
    printf("Stack: ");
    display(s);
    printf("Top element (peek): %d\n", peek(s));
    printf("Stack size: %d\n\n", size(s));
    
    printf("Step 6: Pop another element\n");
    popped = pop(s);
    printf("Popped value: %d\n", popped);
    printf("Stack: ");
    display(s);
    printf("Top element (peek): %d\n", peek(s));
    printf("Stack size: %d\n\n", size(s));
    
    printf("Step 7: Push 40 onto stack\n");
    push(s, 40);
    printf("Stack: ");
    display(s);
    printf("Top element (peek): %d\n", peek(s));
    printf("Stack size: %d\n\n", size(s));
    
    printf("Step 8: Peek at top element\n");
    printf("Top element: %d\n", peek(s));
    
    printf("Step 9: Check if stack is empty\n");
    printf("Is empty? %s\n\n", isEmpty(s) ? "Yes" : "No");
    
    printf("Step 10: Clear stack by popping all\n");
    while (!isEmpty(s)) {
        printf("Popped: %d\n", pop(s));
    }
    printf("Stack after clearing: ");
    display(s);
    
    printMetrics();
    freeStack(s);
}

// Run tests on different input sizes
void runTests() {
    printf("\n========================================\n");
    printf("PERFORMANCE TESTING ON DIFFERENT INPUT SIZES\n");
    printf("========================================\n\n");
    
    int test_sizes[] = {1, 2, 3, 4, 5, 10, 250, 999, 9999, 89786, 789300};
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);
    
    printf("%-12s %-15s %-15s %-15s %-20s\n", "Input Size", "Push O(1)", "Pop O(1)", "Peek O(1)", "Total Operations");
    printf("----------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < num_tests; i++) {
        int n = test_sizes[i];
        
        // Skip large sizes if memory limit exceeded
        if (n > 1000000) {
            printf("%-12d %-15s %-15s %-15s %-20s\n", n, "SKIPPED", "SKIPPED", "SKIPPED", "Memory limit");
            continue;
        }
        
        Stack *s = createStack(n);
        resetMetrics();
        
        // Push n elements
        for (int j = 0; j < n; j++) {
            push(s, j);
        }
        
        // Peek at top
        peek(s);
        
        // Pop half the elements
        for (int j = 0; j < n/2; j++) {
            pop(s);
        }
        
        printf("%-12d %-15d %-15d %-15d %-20d\n", 
               n, 
               metrics.push_count, 
               metrics.pop_count,
               metrics.peek_count,
               metrics.push_count + metrics.pop_count + metrics.peek_count + metrics.comparisons);
        
        freeStack(s);
    }
}

// Main function
int main() {
    printf("========================================\n");
    printf("STACK IMPLEMENTATION - COSC 333\n");
    printf("Moitui Beckham - EB3/67334/23\n");
    printf("========================================\n");
    
    // Step-by-step demonstration
    demonstrateStepByStep();
    
    // Run performance tests
    runTests();
    
    // Test with very large input (1.78 million)
    printf("\n========================================\n");
    printf("LARGE INPUT TEST (1.78 million elements)\n");
    printf("========================================\n\n");
    
    int large_size = 1780000;
    if (large_size <= MAX_SIZE) {
        Stack *s = createStack(large_size);
        resetMetrics();
        
        clock_t start = clock();
        
        // Push all elements
        for (int i = 0; i < large_size; i++) {
            push(s, i);
        }
        
        clock_t push_end = clock();
        double push_time = ((double)(push_end - start)) / CLOCKS_PER_SEC;
        
        // Pop all elements
        while (!isEmpty(s)) {
            pop(s);
        }
        
        clock_t end = clock();
        double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        printf("Input size: %d\n", large_size);
        printf("Push operations: %d (Time: %.4f seconds)\n", metrics.push_count, push_time);
        printf("Pop operations: %d\n", metrics.pop_count);
        printf("Total operations: %d\n", metrics.push_count + metrics.pop_count);
        printf("Total execution time: %.4f seconds\n", total_time);
        
        freeStack(s);
    } else {
        printf("Input size %d exceeds maximum capacity %d\n", large_size, MAX_SIZE);
    }
    
    printf("\n========================================\n");
    printf("END OF PROGRAM\n");
    printf("========================================\n");
    
    return 0;
}
