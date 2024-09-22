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
  - Left child: `2 * i + 1`
  - Right child: `2 * i + 2`
  - Parent: `(i - 1) / 2`

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