# Stack Using a Single Queue (in C)

This repository contains a C implementation of a **Stack** data structure, built entirely using a single **Queue**. This project demonstrates how to manipulate a First-In-First-Out (FIFO) structure to behave like a Last-In-First-Out (LIFO) structure.

This implementation solves **"Problem 1: a stack using one queue"** from standard data structure exercises.

## 🧠 How It Works: The Algorithm

A standard Queue processes elements in the order they arrive (FIFO). To make it act like a Stack (LIFO), we must ensure that the newest added element is always at the **front** of the queue. 

We achieve this by making the `push` operation do a bit of extra work:

1. **Get the current size ($n$)** of the queue.
2. **Enqueue** the new element (it goes to the rear).
3. **Rotate** the older elements: Dequeue the front element and enqueue it right back to the rear. Repeat this $n$ times.

By doing this, all the older elements are moved behind the newly added element. As a result, the newest element ends up at the very front of the queue, ready to be popped in $O(1)$ time!

## ⚙️ Data Structure Details

### 1. Dynamic Circular Queue
The underlying queue is implemented as a **Circular Queue** using a dynamically allocated array.

* **Dynamic Capacity (`int *data`):** Instead of using a fixed-size array (like `int data[100]`), we use a pointer. This allows us to allocate exactly as much memory as we need at runtime using `malloc`.
* **Circular Wrapping (`%` modulo):** We use the modulo operator when calculating the `rear` and `front` indices (e.g., `(rear + 1) % capacity`). This prevents the queue from running out of bounds and allows us to reuse empty spaces at the beginning of the array once elements are dequeued.
* **Enqueue Logic:** 
  ```c
  q->rear = (q->rear + 1) % q->capacity; // Find the next circular index
  q->data[q->rear] = item;               // Place the item in memory
  q->size++;                             // Increment the element counter
  ```

### 2. The Stack Wrapper
The Stack structure simply contains a pointer to our Queue. It restricts the user to only use `push`, `pop`, and `top` operations, hiding the queue mechanics underneath.

## ⏱️ Complexity

| Operation | Time Complexity | Explanation |
| :--- | :--- | :--- |
| `push(x)` | $O(n)$ | We must rotate $n$ existing elements every time a new element is pushed. |
| `pop()` | $O(1)$ | The newest element is always at the front, so we just dequeue it. |
| `top()` | $O(1)$ | We just peek at the front element of the queue. |
| **Space** | $O(n)$ | We need space proportional to the number of elements stored. |

## 🚀 How to Compile and Run

1. Open your terminal.
2. Compile the C file using GCC:
   ```bash
   gcc main.c -o stack_queue
   ```
3. Run the executable:
   ```bash
   ./stack_queue
   ```