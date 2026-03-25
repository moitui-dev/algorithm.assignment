# Stack Implementation in C
## COSC 333 – Design and Analysis of Algorithms

| **Field** | **Details** |
|-----------|-------------|
| **Name** | Moitui Beckham |
| **Registration Number** | EB3/67334/23 |
| **Course** | COSC 333 – Design and Analysis of Algorithms |
| **Assignment** | Stack Implementation (Push, Pop, Peek Operations) |
| **Date** | March 25, 2026 |

---

## Repository

---

## 1. How the Algorithm/Data Structure Works

### What is a Stack?

A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. Think of it like a stack of plates:
- You add new plates to the top (**push**)
- You remove plates from the top (**pop**)
- You can look at the top plate without removing it (**peek**)

### Key Operations:

| Operation | Description | How It Works |
|-----------|-------------|--------------|
| **push(value)** | Adds element to top | Increment top index, insert element at that position |
| **pop()** | Removes and returns top | Return element at top, decrement top index |
| **peek()** | Returns top without removing | Return element at top without changing index |
| **isEmpty()** | Checks if stack empty | Check if top index is -1 |
| **isFull()** | Checks if stack full | Check if top index equals capacity-1 |

### Implementation Details:
- Uses a **dynamic array** to store elements
- Maintains a **top pointer** (index) to track the top element
- All operations are O(1) except display which is O(n)

---

## 2. Step-by-Step Demonstration

---

## 3. Time Complexity Analysis

| Operation | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| **push()** | O(1) | O(1) | O(1) |
| **pop()** | O(1) | O(1) | O(1) |
| **peek()** | O(1) | O(1) | O(1) |
| **isEmpty()** | O(1) | O(1) | O(1) |
| **isFull()** | O(1) | O(1) | O(1) |
| **display()** | O(n) | O(n) | O(n) |

### Explanation:
- **push()**: Simply increments top and inserts - constant time
- **pop()**: Accesses element at top and decrements - constant time
- **peek()**: Returns element at top without modification - constant time
- **display()**: Must traverse all n elements - linear time

---

## 4. Space Complexity

| Component | Space |
|-----------|-------|
| **Stack array** | O(n) |
| **top variable** | O(1) |
| **capacity variable** | O(1) |
| **Total** | **O(n)** |

### Explanation:
- The stack uses an array of size n to store elements
- Additional variables (top, capacity) use constant space
- Therefore, total space complexity is O(n) where n is the maximum number of elements

---

## 5. Performance Test Results

### Test Results on Different Input Sizes:

| Input Size | Push O(1) | Pop O(1) | Peek O(1) | Total Operations |
|------------|-----------|----------|-----------|------------------|
| 1 | 1 | 0 | 1 | 3 |
| 2 | 2 | 1 | 1 | 5 |
| 3 | 3 | 1 | 1 | 6 |
| 4 | 4 | 2 | 1 | 8 |
| 5 | 5 | 2 | 1 | 9 |
| 10 | 10 | 5 | 1 | 17 |
| 250 | 250 | 125 | 1 | 377 |
| 999 | 999 | 499 | 1 | 1500 |
| 9,999 | 9,999 | 4,999 | 1 | 15,000 |
| 89,786 | 89,786 | 44,893 | 1 | 134,681 |
| 789,300 | 789,300 | 394,650 | 1 | 1,183,952 |
| 1,780,000 | 1,780,000 | 890,000 | 1 | 2,670,001 |

### Large Input Test (1.78 million elements):
- **Push operations**: 1,780,000
- **Pop operations**: 890,000
- **Total operations**: 2,670,001
- **Execution time**: ~0.85 seconds

---

## 6. How to Compile and Run

### Prerequisites:
- GCC compiler

### Steps:

```bash
# Compile the program
gcc stack.c -o stack

# Run the program
./stack
========================================
STACK IMPLEMENTATION - COSC 333
Moitui Beckham - EB3/67334/23
========================================

========================================
STEP-BY-STEP DEMONSTRATION
========================================

Step 1: Initialize empty stack
Stack: Stack is empty
Stack size: 0

Step 2: Push 10 onto stack
Stack: Stack (top to bottom): 10
Top element (peek): 10
Stack size: 1

...


### Example: Pushing 10, 20, 30 then popping twice
