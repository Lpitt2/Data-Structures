# Data Structures Example in C

**Author**: Levi Pittman

**Purpose**: Implement basic data structures within the C language.

### Disclaimer:

The purpose of this project is to implement and testbasic generic data structures within the C language. The list of data
structures can be found at [https://www.geeksforgeeks.org/data-structures/](https://www.geeksforgeeks.org/data-structures/). The
data structures are contained within header libraries. This project may be expanded upon or used for educational purposes without
receiving explicit consent from the author.

### Requirements:
* Implement data structures through header files.
* Test data strucutres.
* Use dynamic memory allocation to create and destroy the data structure in memory.
* Provide utilities for pushing, popping, and selecting when necessary and displaying always.
* Maintain professional coding practices, including headers on the files, consistent naming, and testing.

### General Structure:
* *bin*
  * program
* *src*
  * main.c
  * *stack*
    * stack.h
    * stack.c
  * *queue*
    * queue.h
    * queue.c
  * *list*
    * list.h
    * list.c
* makefile
* README.md

The *bin* and *src* folders are common to programs. They store the binaries (e.g., executables) and the source
code respectively. The folders *stack*, *queue*, and *list* contain their respective data structure implementations
which includes associated header and C source files. The *main.c* file is the main driver code of the project and
does not include any data structure implementation. The *makefile* should be run before attempting to run the program
as it handles compiling the code. The *program* file only exists if the *makefile* has been run and contains the 
executable code of the program.

### Stack:

Stacks are a form of data structure that follows the Last In First Out (**LIFO**) principles. This means that the last
node to be added to the stack will be the first node to be removed from the stack. Another method of thinking about 
stacks is that the order in which information is added to the stack is the opposite order for removing information from
the stack. Stacks grow "upwards" and are destroyed "downwards". The elements that make up a stack are refered to as 
*StackNodes*. Each stack node has an ambigous pointer to the value stored within the element and a pointer to the previous
element. The stack itself contains a pointer to the bottom node, refered to as the *root node*, and a pointer to the current
top node. Nodes are pushed and popped to and from the top.

### Queue:

Queues are simular to stacks, except they only grow. Queues follow the First In First Out (**FIFO**) principles meaning that the
first node added to a queue is the first node to be removed from a queue. In this sense, the queue is always "growing" and 
shrinks by moving the root closer to the top of the queue. As with stacks, queues have two major components. The first 
being the *QueueNode* which contains an ambigious pointer to the value and a pointer to the next node. The *Queue* itself
contains two pointers, the first being a pointer to the *root node* and the second being a pointer to the *top node*. Nodes
are pushed to the top and popped from the bottom.
