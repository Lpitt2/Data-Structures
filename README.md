# Data Structures Example in C

**Author**: Levi Pittman

**Purpose**: Implement basic data structures within the C language.

### Disclaimer:

The purpose of this project is to implement and testbasic generic data structures within the C language. The list of data
structures can be found at [https://www.geeksforgeeks.org/data-structures/](https://www.geeksforgeeks.org/data-structures/). The
data structures are contained within header libraries. This project may be expanded upon or used for educational purposes without
receiving explicit consent from the author. The website [https://makefiletutorial.com/](https://makefiletutorial.com/) was used to 
create the makefile.

### Requirements:
* Implement data structures through header files.
* Test data strucutres.
* Use dynamic memory allocation to create and destroy the data structure in memory.
* Build a system that can be extended to provide a generic framework for various data structures in C.
* Maintain professional coding practices, including headers on the files, consistent naming, and testing.

## General Structure:
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

### Running the program.

A make file is provided to make it easy to compile and run the program. As mentioned in the section *General Structure* above; 
however, before running the make file, create a file called bin in the top-level directory as the make file requires this folder.

## data structures

This project implements three common data structures:
 * Stack
 * Queue
 * Linked-List

Each has its own node struct and functions that perform data structure specific operations for those nodes. Common
functionallities that each data structure has include calculating the length of the data structure, creating a new node,
appending (inserting) nodes, and popping (removing) nodes.

### Stack:

Stacks are a form of data structure that follows the Last In First Out (**LIFO**) principles. This means that the last
node to be added to the stack will be the first node to be removed from the stack. Another method of thinking about 
stacks is that the order in which information is added to the stack is the opposite order for removing information from
the stack. Stacks grow "upwards" and are destroyed "downwards". The elements that make up a stack are refered to as 
*StackNodes*. Each stack node has an ambigous pointer to the value stored within the element and a pointer to the previous
element. The stack itself contains a pointer to the bottom node, refered to as the *root node*, and a pointer to the current
top node. Nodes are pushed and popped to and from the top.

### Queue:

Queues are simular to stacks, except they only grow. Queues follow the First In First Out (**FIFO**) principles meaning that
the first node added to a queue is the first node to be removed from a queue. In this sense, the queue is always "growing" and 
shrinks by moving the root closer to the top of the queue. As with stacks, queues have two major components. The first 
being the *QueueNode* which contains an ambigious pointer to the value and a pointer to the next node. The *Queue* itself
contains two pointers, the first being a pointer to the *root node* and the second being a pointer to the *top node*. Nodes
are pushed to the top and popped from the bottom.

### List:

Lists are conceptually simular to that of a train. Trains are made up of multiple cars (or nodes) that are connected to the car in 
front and the car behind. The engine of the train does not have a car in front of it and the caboose does not connect to another 
car after it. A person can exist in only one car at a time. If that person exists in car three, where one is the engine and five 
is the caboose, would have to travel through car two to get to the engine since car two is connected to car three and the engine
is connected only to car two. Unlike the previous two data structures, the list only contains a single struct called *ListNode*
which contains an ambigious pointer to the value, and two pointers to the previous and next nodes within the list.

### Binary Search Tree:

Binary search trees are a form of binary tree that has the added requirement of the left element must be less then the root and the
right element must be greater than the root. The benefit of using a binary search tree is that searching for elements is at best
O(lb(n)), refered to as logarithmic, time complexity (source:  [https://www.geeksforgeeks.org/complexity-different-operations-binary-tree-binary-search-tree-avl-tree/](https://www.geeksforgeeks.org/complexity-different-operations-binary-tree-binary-search-tree-avl-tree/)). One can think of a binary search tree
as someone searching for a room down a hallway. The rooms in this hallway would be numbered sequentially. The room closest to the 
stairs is one, the next room is two, the room after that is three. This pattern continues on to the end of the hallway. A person 
attempting to find room 36 would have to travel 36 rooms down the hallway. In the case of a binary tree, we assume that the halway 
has two doors. The door on the left is labelled rooms "1 - 50" whereas the other is labelled rooms "51 - 100". Upon entering 
through the left door, the person discovers a room with two more doors the left labelled "1 - 25" with the other labelled "26 - 50".
The pattern is continued for all rooms until an actual room that is not a hallway is reached. Ignoring the problems that physics 
pose, the person would only have to travel through about seven doors to get to their destination.