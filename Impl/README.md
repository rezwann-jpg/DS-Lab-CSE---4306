# Asymptotic Notation

## Introduction

Asymptotic notation is a mathematical tool used in computer science to analyze algorithm efficiency. It provides a way to describe the performance or complexity of an algorithm without relying on machine-specific constants or implementation details. This allows for meaningful comparisons between algorithms based on their fundamental trends as input sizes approach infinity.

## Main Asymptotic Notations

1. Big-O Notation (O-notation)
2. Omega Notation (Ω-notation)
3. Theta Notation (Θ-notation)

### 1. Theta Notation (Θ-notation)

Theta notation encloses the function from above and below. Since it represents the upper and the lower bound of the running time of an algorithm, it is used for analyzing the average-case complexity of an algorithm. Theta (Average Case) You add the running times for each possible input combination and take the average in the average case.

A simple way to get the Theta notation of an expression is to drop low-order terms and ignore leading constants. For example, Consider the expression $3n^3 + 6n^2 + 6000 = Θ(n^3)$, the dropping lower order terms is always fine because there will always be a number(n) after which $Θ(n^3)$ has higher values than $Θ(n^2)$ irrespective of the constants involved. For a given function $g(n)$, we denote $Θ(g(n))$ is following set of functions. 


#### Visual Representation:
Let $g$ and $f$ be the function from the set of natural numbers to itself. The function $f$ is said to be $Θ(g)$, if there are constants $c1, c2 > 0$ and a natural number $n_0$ such that $c_1* g(n) ≤ f(n) ≤ c_2 * g(n)$ for all $n ≥ n_0$

![Theta graph](https://media.geeksforgeeks.org/wp-content/uploads/20220822015828/thetanotation.png "Theta")

#### Key Points:
- The execution time serves as both a lower and upper bound on the algorithm’s time complexity. 
- It exist as both, most, and least boundaries for a given input value.
- Used for analyzing average-case complexity

### 2. Big O Notation (O-notation)

Big-O notation represents the upper bound of the running time of an algorithm. Therefore, it gives the worst-case complexity of an algorithm.

For example, Consider the case of Insertion Sort. It takes linear time in the best case and quadratic time in the worst case. We can safely say that the time complexity of the Insertion sort is $O(n^2)$. 
Note: $O(n^2)$ also covers linear time. 

If we use $Θ$ notation to represent the time complexity of Insertion sort, we have to use two statements for best and worst cases: 

- The worst-case time complexity of Insertion Sort is $Θ(n^2)$.
- The best case time complexity of Insertion Sort is $Θ(n)$. 

#### Definition:
If $f(n)$ describes the running time of an algorithm, $f(n)$ is $O(g(n))$ if there exist a positive constant $c$ and $n_0$ such that, $0 ≤ f(n) ≤ cg(n)$ for all $n ≥ n_0$

#### Visual Representation:
![Big Oh](https://media.geeksforgeeks.org/wp-content/uploads/AlgoAnalysis-2.png "Big oh")

#### Key Points:

- It is the most widely used notation for Asymptotic analysis.
- It specifies the upper bound of a function.
- The maximum time required by an algorithm or the worst-case time complexity.
- It returns the highest possible output value(big-O) for a given input.
- Big-O(Worst Case) It is defined as the condition that allows an algorithm to complete statement execution in the longest amount of time possible.

### 3. Omega Notation (Ω-notation)

Omega notation represents the lower bound of the running time of an algorithm. Thus, it provides the best case complexity of an algorithm.

Let us consider the same Insertion sort example here. The time complexity of Insertion Sort can be written as $Ω(n)$, but it is not very useful information about insertion sort, as we are generally interested in worst-case and sometimes in the average case. 

#### Definition:
Let $g$ and $f$ be the function from the set of natural numbers to itself. The function $f$ is said to be $Ω(g)$, if there is a constant $c > 0$ and a natural number $n_0$ such that $c*g(n) ≤ f(n)$ for all $n ≥ n_0$

#### Visual Representation:
![Omega](https://media.geeksforgeeks.org/wp-content/uploads/AlgoAnalysis-3.png "Omega")

#### Key Points:
- The execution time serves as a lower bound on the algorithm’s time complexity.

- It is defined as the condition that allows an algorithm to complete statement execution in the shortest amount of time.


## Common Time Complexities

1. $O(1)$ - Constant time
2. $O(log n)$ - Logarithmic time
3. $O(n)$ - Linear time
4. $O(n log n)$ - Linearithmic time
5. $O(n^2)$ - Quadratic time
6. $O(2^n)$ - Exponential time

### Comparison Graph
![](https://www.boardinfinity.com/blog/content/images/2022/10/o--9-.jpg)

This graph illustrates the relative growth rates of different time complexities. As n increases, the differences between these functions become more pronounced.

# Heap Implementation in C++

## Introduction
- A heap is a tree-based data structure where each node is either greater than or equal to (max heap) or less than or equal to (min heap) its children.
- Heaps are complete binary trees, with all levels filled except possibly the last, which is filled from left to right.

## Types of Heaps
1. **Min Heap**: Each node is less than or equal to its children.
2. **Max Heap**: Each node is greater than or equal to its children.

## Heap Representation
- Heaps are often stored in arrays for faster access and modification.
- Index calculations (0-based):
  - Left child: $2 * i + 1$
  - Right child: $2 * i + 2$
  - Parent: $(i - 1) / 2$

## C++ Implementation
```cpp
class Heap {
private:
    std::vector<int> array;
    int size;
    void heapify(int i);

public:
    Heap(int capacity);
    void insert(int key);
    int extractMax();
    int getMax() const;
    void deleteKey(int i);
    void increaseKey(int i, int newValue);
    void printHeap() const;
};
```

## Key Operations and Their Steps

### Heapify
1. Initialize the largest node as the current node i.
2. Calculate the left child index as 2 * i + 1.
3. Calculate the right child index as 2 * i + 2.
4. Check if the left child exists and is greater than the current largest node.
   - If true, update the largest node to the left child.
5. Check if the right child exists and is greater than the current largest node.
   - If true, update the largest node to the right child.
6. If the largest node is not the current node i, swap them.
7. Recursively apply heapify to the subtree rooted at the largest node.

### Insert
1. Append the new key to the end of the array.
2. Initialize the index i as the index of the newly inserted key.
3. While the key at index i is greater than its parent and i is not the root:
   - Swap the key with its parent.
   - Update i to the parent index.
4. Continue this process until the heap property is restored.

### Extract Max
1. Check if the heap is empty. If true, throw an underflow_error.
2. If the heap has only one element, remove and return that element.
3. Store the maximum value (root of the heap) in a temporary variable.
4. Replace the root of the heap with the last element in the array.
5. Remove the last element from the array.
6. Apply the heapify operation on the root to restore the heap property.
7. Return the stored maximum value.

### Get Max
1. Check if the heap is empty. If true, throw an underflow_error.
2. Return the root of the heap, which is the maximum value.

### Delete Key
1. Check if the index i is valid. If not, throw an out_of_range exception.
2. Replace the key at index i with the last element in the array.
3. Remove the last element from the array.
4. Apply the heapify operation on the subtree rooted at index i.

### Increase Key
1. Check if the index i is valid and the new value is greater than the current value. If not, throw an invalid_argument exception.
2. Update the value at index i to the new value.
3. While the key at index i is greater than its parent and i is not the root:
   - Swap the key with its parent.
   - Update i to the parent index.
4. Continue this process until the heap property is restored.

### Print Heap
1. Iterate through each element in the array.
2. Print each element followed by a space.
3. Print a newline at the end.

## Note
This implementation focuses on a max heap. For a min heap, the comparison operations would be reversed.

# Build Heap Operation

## Introduction
Building a heap from an array of N elements involves creating either a Max Heap or Min Heap. This operation is fundamental in heap sort and priority queue implementations.

## Problem Statement
Given an array of N elements, build a Binary Heap (Max Heap or Min Heap) from the given array.

## Examples

### Example 1
**Input:** arr[] = {4, 10, 3, 5, 1}
**Output:** Max-Heap:
```
      10
    /    \
   5      3
 /   \
4     1
```

### Example 2
**Input:** arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
**Output:** Max-Heap:
```
                 17
               /    \
             15      13
           /   \    /  \
          9     6  5   10
         / \   / \
        4   8 3   1
```

## Key Points
- Root is at index 0 in the array.
- Left child of i-th node is at (2*i + 1)th index.
- Right child of i-th node is at (2*i + 2)th index.
- Parent of i-th node is at (i-1)/2 index.

## Approaches

### 1. Naive Approach
- **Idea:** Heapify the complete binary tree in reverse level order, following a top-down approach.
- **Time Complexity:** O(N*logN), where N is the number of nodes.

### 2. Efficient Approach
- **Idea:** Optimize by observing that leaf nodes already follow the heap property.
- **Key Observation:** Find the position of the last non-leaf node and perform heapify on each non-leaf node in reverse level order.
- **Time Complexity:** O(N), which is more efficient than the naive approach.

## Efficient Approach Steps

1. Find the index of the last non-leaf node: (n/2) - 1, where n is the number of elements.
2. Iterate from the last non-leaf node to the root (index 0):
   a. Call heapify on each node.

## Heapify Process Illustration

Using the array: {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}

1. **Initial state:**
   ```
                 1
               /   \
              3     5
            /   \  / \
           4    6 13 10
          / \  / \
         9  8 15 17
   ```

2. **Heapify node 6:**
   Swap 6 and 17
   ```
                 1
               /   \
              3     5
            /   \  / \
           4    17 13 10
          / \  / \
         9  8 15 6
   ```

3. **Heapify node 4:**
   Swap 4 and 9
   ```
                 1
               /   \
              3     5
            /   \  / \
           9    17 13 10
          / \  / \
         4  8 15 6
   ```

4. **Heapify node 5:**
   Swap 5 and 13
   ```
                 1
               /   \
              3     13
            /   \  / \
           9    17 5  10
          / \  / \
         4  8 15 6
   ```

5. **Heapify node 3:**
   Swap 3 and 17, then 3 and 15
   ```
                 1
               /   \
              17    13
            /   \  / \
           9    15 5  10
          / \  / \
         4  8 3  6
   ```

6. **Heapify node 1 (root):**
   Swap 1 and 17, then 1 and 15, finally 1 and 6
   ```
                 17
               /    \
              15     13
            /   \   / \
           9     6  5  10
          / \   / \
         4   8 3   1
   ```

## Implementation Note
The actual implementation would involve a `heapify` function that is called on each non-leaf node, starting from the last non-leaf node and moving towards the root.

# Heap Sort Operation

## Introduction
Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure. It divides its input into a sorted and an unsorted region, and iteratively shrinks the unsorted region by extracting the largest element and moving it to the sorted region.

## Overview of Heap Sort
Heap Sort consists of two main phases:
1. Building a max heap from the input data.
2. Repeatedly extracting the maximum element from the heap and rebuilding the heap.

## Steps of Heap Sort

### 1. Build Max Heap
- Use the Build Heap operation to create a max heap from the input array.
- This ensures that the largest element is at the root of the heap.

### 2. Heapify and Sort
- Swap the root (largest element) with the last element of the heap.
- Reduce the size of the heap by 1.
- Heapify the root of the tree.
- Repeat this process until the heap size is reduced to 1.

## Detailed Algorithm with Visualizations

Let's consider an array: [4, 10, 3, 5, 1]

1. **Initial Array:**
   ```
   [4, 10, 3, 5, 1]
   ```
   Visualized as a binary tree:
   ```
        4
      /   \
     10    3
    /  \
   5    1
   ```

2. **Build Max Heap:**
   After building max heap: [10, 5, 3, 4, 1]
   ```
        10
      /    \
     5      3
    / \
   4   1
   ```

3. **Heapify and Sort:**

   a. Swap 10 and 1: [1, 5, 3, 4, 10]
   ```
        1
      /   \
     5     3
    / \
   4   10*  (* = sorted)
   ```

   b. Heapify: [5, 4, 3, 1, 10]
   ```
        5
      /   \
     4     3
    / \
   1   10*
   ```

   c. Swap 5 and 1: [1, 4, 3, 5*, 10*]
   ```
        1
      /   \
     4     3
    / \
   5*  10*
   ```

   d. Heapify: [4, 1, 3, 5*, 10*]
   ```
        4
      /   \
     1     3
    / \
   5*  10*
   ```

   e. Swap 4 and 3: [3, 1, 4*, 5*, 10*]
   ```
        3
      /   \
     1     4*
    / \
   5*  10*
   ```

   f. Heapify: [3, 1, 4*, 5*, 10*] (no change needed)

   g. Swap 3 and 1: [1, 3*, 4*, 5*, 10*]
   ```
        1
      /   \
     3*    4*
    / \
   5*  10*
   ```

Final sorted array: [1, 3, 4, 5, 10]

## Time Complexity
- Building the heap: O(n)
- Heapify process: O(log n) for each of n elements
- Overall time complexity: O(n log n)

## Space Complexity
- O(1) auxiliary space complexity as it sorts in-place

## Advantages of Heap Sort
1. Efficient for large data sets
2. In-place sorting algorithm
3. Consistent O(n log n) time complexity

## Disadvantages of Heap Sort
1. Not stable (relative order of equal elements may change)
2. Poor cache performance compared to quicksort

## Relationship with Build Heap Operation
The Build Heap operation is a crucial first step in Heap Sort. It transforms the input array into a max heap, setting the stage for the sorting process. Without an efficient Build Heap operation, the overall efficiency of Heap Sort would be compromised.

## Implementation Note
In practice, the Heap Sort algorithm would use the `heapify` function repeatedly. The initial Build Heap operation would call `heapify` on all non-leaf nodes, and then the sorting phase would call `heapify` on the root after each swap operation.


# C++ Linked Lists: Types, Structure, and Operations

## Definition
A linked list in C++ is a linear data structure that stores data in non-contiguous memory locations. Each node contains a value and a pointer to the next node. A linked list is defined as a collection of nodes where each node consists of two members which represents its value and a next pointer which stores the address for the next node.

## Types of Linked Lists

1. **Singly Linked List**: The singly linked list is the simplest form of linked list in which the node contain two members data and a next pointer that stores the address of the next node. Each node is a singly linked list is connected through the next pointer and the next pointer of the last node points to NULL denoting the end of the linked list. The following diagram describes the structure of a singly linked list:

![Single Linked List](https://media.geeksforgeeks.org/wp-content/uploads/20240607183512/Sinlgy-Linked-List.png)

2. **Doubly Linked List**: The doubly linked list is the modified version of the singly linked list where each node of the doubly linked consists of three data members data ,next and prev. The prev is a pointer that stores the address of the previous node in the linked list sequence. Each node in a doubly linked list except the first and the last node is connected with each other through the prev and next pointer. The prev pointer of the first node and the next pointer of the last node points to NULL in the doubly linked list. The following diagram describes the structure of a doubly linked list:

![Doubly linked list](https://media.geeksforgeeks.org/wp-content/uploads/20240607183511/Doubly-Linked-List.png)

3. **Circular Linked List**: The circular linked list is almost same as the singly linked list but with a small change. In a circular linked list the next pointer of the last node points to the first node of the linked list rather than pointing to NULL, this makes this data structure circular in nature which is used in various applications like media players. The following diagram describes the structure of a circular linked list:

![Circular linked list](https://media.geeksforgeeks.org/wp-content/uploads/20240607183510/Circular-Linked-List.png)

4. **Doubly Circular Linked List**: The doubly circular linked list is a combination of a doubly linked list and a circular linked list. In a doubly circular linked list the prev pointer of the first node points to the last node and the next pointer of the last node points to the first node. The main advantage of a doubly circular linked list is that we can access the last node of the linked list in constant time through the first node. The following diagram describes the structure of a doubly circular linked list:

![Doubly Circular linked list](https://media.geeksforgeeks.org/wp-content/uploads/20240607183510/DoublyCircular--Linked-List.png)

## Node Structure

```cpp
struct Node {    
    int data;    
    Node* next;
    // Node* prev;  // For doubly linked lists
};
```

## Basic Operations

| Operation | Description | Time Complexity | Space Complexity |
|-----------|-------------|-----------------|-------------------|
| insertAtBeginning | Add new node at start | O(1) | O(1) |
| insertAtEnd | Add new node at end | O(n) | O(1) |
| insertAtPosition | Add node at specific position | O(n) | O(1) |
| deleteFromBeginning | Remove head node | O(1) | O(1) |
| deleteFromEnd | Remove last node | O(n) | O(1) |
| deleteFromPosition | Remove node from given position | O(n) | O(1) |
| Display | Print all node values | O(n) | O(1) |

## Key Algorithms

### insertAtBeginning
1. Create a new node
2. Point the new Node’s next pointer to the current head.
3. Update the head of the linked list as the new node.

![](https://media.geeksforgeeks.org/wp-content/uploads/20240607192011/Insert-At-First-Linked-List.png)

### insertAtEnd
1. Create a new Node
2. If the linked list is empty, update the head as the new node.
3. Otherwise traverse till the last node of the linked list.
4. Update the next pointer of the last node from NULL to new node.

![](https://media.geeksforgeeks.org/wp-content/uploads/20240607192010/Insert-At-End-Linked-List.png)

### insertAtPosition

1. Check if the provided position by the user is a valid poistion.
2. Create a new node.
3. Find the node at position -1.
4. Update the next pointer of the new node to the next pointer of the current node.
5. Update the next pointer of the current node to new node.

![](https://media.geeksforgeeks.org/wp-content/uploads/20240607192009/Insert-After-Position-Linked-List.png)

### deleteFromBeginning
1. Check whether the Head of the linked list is not NULL. If Head is equal to NULL return as the linked list is empty, there is no node present for deletion.
2. Store the head of the linked list in a temp pointer.
3. Update the head of the linked list to next node.
4. Delete the temporary node stored in the temp pointer.

![](https://media.geeksforgeeks.org/wp-content/uploads/20240607192007/Delete-First-Position-Linked-List.png)

### deleteFromEnd
1. Verify whether the linked is empty or not before deletion.
2. If the linked list has only one node, delete head and set head to NULL.
3. Traverse till the second last node of the linked list.
4. Store the last node of the linked list in a temp pointer.
5. Pointer the next pointer of the second last node to NULL.
6. Delete the node represented by the temp pointer.

![](https://media.geeksforgeeks.org/wp-content/uploads/20240607192009/Delete-Last-Position-Linked-List.png)

### deleteFromPosition

1. Check if the provided postion by the users is a valid position in the linked list or not.
2. Find the node at position -1.
3. Save node to be deleted in a temp pointer.
4. Set the next pointer of the current node to the next pointer of the node to be deleted.
5. Set the next pointer of temp to NULL.
6. Delete the node represented by temp pointer.

![](https://media.geeksforgeeks.org/wp-content/uploads/20240607192008/Delete-From-Middle-Linked-List.png)

# Tree Data Structure Terminologies

### 1. Node
- Definition: Fundamental unit of a tree data structure.
- Characteristics:
  - Hierarchical structure to represent and organize data
  - Collection of nodes connected by edges
  - Hierarchical relationship between nodes
  - Topmost node is called the root
  - Nodes below root are child nodes
  - Each node can have multiple children
  - Recursive structure
  - Non-linear Nature
  - Data not stored sequentially/linearly
  - Arranged on multiple levels (hierarchical)
- Types:
  - Root node
  - Parent node
  - Child node
  - Leaf node
  - Internal node
### 2. Root Node
- The topmost node in the tree hierarchy.
- Has no parent
- Entry point for tree traversal
### 3. Parent Node
- Predecessor of a node
### 4. Child Node
- Immediate successor of a node
### 5. Leaf Node (External Node)
- A node that has no children.
### 6. Internal Node
- A node that has at least one child.
### 7. Sibling Nodes
- Nodes that share the same parent.
### 8. Ancestor Node
- Any node on the path from the root to a given node.
### 9. Descendant Node
- Any node reachable by repeated proceeding from parent to child.
### 10. Level of a Node
- The number of edges on the path from the root to the node.
### 11. Height of a Node
- The number of edges on the longest path from the node to a leaf.
### 12. Depth of a Node
- The number of edges from the root to the node.
### 13. Subtree
- A tree consisting of a node and all its descendants.
### 14. Degree of a Node
- The number of children a node has.

![](https://media.geeksforgeeks.org/wp-content/uploads/20240424105009/Representation-of-Tree-Data-Structure.webp)

# BST Operations

The in-order successor of a node is the node that comes immediately after the given node in the in-order traversal of the BST. In simpler terms, it's the next node in the sorted order of the BST.

### Key Points:
- If the node has a right child, the successor is the leftmost node in the right subtree.
- If the node has no right child, the successor is one of its ancestors. Specifically, it is the lowest ancestor for which the node is in the left subtree.

Steps to Find In-Order Successor:
- Case 1: The node has a right subtree:
  The in-order successor is the leftmost node in the right subtree of the current node.
- Case 2: The node has no right subtree:
  We move up to the parent node until we find a node that is the left child of its parent. The parent of that node will be the in-order successor.