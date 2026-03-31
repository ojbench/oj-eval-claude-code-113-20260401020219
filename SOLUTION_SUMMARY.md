# Problem 113 Solution Summary

## Problem Overview
Implement a template LinkedList class and two derived classes (Stack and Queue) in C++, using only `cstdio` and `iostream` headers.

## Solution Approach

### LinkedList Implementation
- Used a doubly-linked list structure with `Node<T>` containing data, next, and prev pointers
- Implemented all required methods:
  - `pushFront()` / `pushBack()`: Insert elements at head/tail
  - `popFront()` / `popBack()`: Remove elements from head/tail
  - `size()`: Return count of elements
  - `print()`: Output elements separated by spaces using cout
  - Copy constructor: Deep copy of all nodes
  - Destructor: Free all allocated nodes to prevent memory leaks

### Stack Implementation
- Inherits from `LinkedList<T>`
- Uses LIFO (Last In First Out) principle
- Stack top is at the tail of the linked list
- `push()` → `pushBack()`
- `pop()` → `popBack()`
- `peak()` → returns tail's data

### Queue Implementation
- Inherits from `LinkedList<T>`
- Uses FIFO (First In First Out) principle
- Queue front is at the head, back is at the tail
- `push()` → `pushBack()`
- `pop()` → `popFront()`
- `peak()` → returns head's data

## Test Results

### Submission 1 (ID: 766727)
- **Status**: Accepted
- **Score**: 100/100
- **All test points passed**:
  - Test 1-2: LinkedList non-virtual functions ✓
  - Test 3: Queue operations ✓
  - Test 4: Stack operations ✓
  - Test 5: All features ✓
  - Test 6-10: Memory leak tests ✓

### Resource Usage
- Time: 12.865 seconds total (max single test: 6.353s)
- Memory: ~65 MB max
- No memory leaks detected

## Key Design Decisions
1. **Doubly-linked list**: Allows O(1) operations at both ends
2. **Protected members**: head, tail, count accessible to derived classes
3. **Virtual functions**: Declared in base class, overridden in Stack/Queue
4. **Memory management**: Proper destructor implementation prevents leaks
5. **Empty list handling**: Returns `T()` default value when popping from empty list

## Submissions Used: 1/5
- First submission achieved perfect score
- No further optimization needed
