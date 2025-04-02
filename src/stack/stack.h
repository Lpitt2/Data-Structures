// Levi Pittman
// March 17, 2025
// Contains the declarations for a stack data structure.

/*
 * Structures:
 *  - StackNode:                                   Represents a generic node within a stack.
 *  - Stack:                                       Represents a generic stack.
 * 
 * Functions:
 *  - Stack create_stack():                        Creates an empty stack.
 *  - StackNode* create_stack_node(void* value):   Creates a new stack node.
 *  - unsigned int stack_length(Stack):            Returns the number of nodes within a stack.
 *  - void stack_push(Stack*, StackNode*):         Pushes a node to a stack.
 *  - StackNode stack_pop(Stack *):                Pops the top node from a stack.
*/

#ifndef __STACK_H__
#define __STACK_H__

#ifndef NULL
#define NULL 0x0
#endif


// Represents a generic node within a stack.
struct StackNode
{

  void *value;
  struct StackNode *previous;

};

// Represents a generic stack.
struct Stack
{

  struct StackNode* root;
  struct StackNode* top;

};


// Creates an empty stack.
struct Stack create_stack();

// Creates a new stack node.
struct StackNode* create_stack_node(void* value);

// Returns the number of nodes within a stack.
unsigned int stack_length(struct Stack stack);

// Pushes a node to a stack.
void stack_push(struct Stack* stack, struct StackNode* node);

// Pops the top node from a stack.
struct StackNode stack_pop(struct Stack *stack);


#endif