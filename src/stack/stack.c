// Levi Pittman
// March 17, 2025
// Contains the implementation code for the stack data structure.

/*
 * Functions:
 *  - Stack create_stack():                        Creates an empty stack.
 *  - StackNode* create_stack_node(void* value):   Creates a new stack node.
 *  - unsigned int stack_length(Stack):            Returns the number of nodes within a stack.
 *  - void stack_push(Stack*, StackNode*):         Pushes a node to a stack.
 *  - StackNode stack_pop(Stack *):                Pops the top node from a stack.
*/

#include <stdlib.h>
#include <stddef.h>

#include "stack.h"


// Creates an empty stack.
struct Stack create_stack()
{

  // Create the stack.
  struct Stack stack;

  // Set the pointers to null.
  stack.top = NULL;
  stack.root = NULL;

  return stack;

}

// Creates a new stack node.
struct StackNode* create_stack_node(void* value)
{

  // Declare variables.
  struct StackNode* node = NULL;
  
  // Allocate the new node.
  node = (struct StackNode*)(malloc(sizeof(struct StackNode)));

  // Assign the value to the node.
  (*node).value = value;

  return node;

}

// Returns the number of nodes within a stack.
unsigned int stack_length(struct Stack stack)
{

  // Declare variables.
  unsigned int count = 0;
  struct StackNode current_node;

  // Ensure that the stack is not empty.
  if (stack.top != NULL)
  {
    
    // Get the top node.
    current_node = (*stack.top);

    // Set the counter to one to account for the top node.
    count = 1;

    // Iterate until the current node does not have a lower node.
    while (current_node.previous != NULL)
    {

      // Increment the counter.
      ++count;

      // Seek to the next node.
      current_node = (*current_node.previous);

    }

  }

  return count;

}

// Pushes a node to a stack.
void stack_push(struct Stack *stack, struct StackNode* node)
{

  // Ensure that the stack is not empty.
  if ((*stack).top == NULL)
  {

    // Set the root and top nodes to the new node.
    (*stack).root = node;
    (*stack).top = node;

  } else
  {

    // Set the current top to the new node.
    (*node).previous = (*stack).top;

    // Update the top to equal the new node.
    (*stack).top = node;

  }

}

// Pops the top node from a stack.
struct StackNode stack_pop(struct Stack *stack)
{

  // Declare variables.
  struct StackNode node;
  struct StackNode current_top;

  // Set up the node.
  node.value = NULL;
  node.previous = NULL;

  // Ensure that the stack is not empty.
  if ((*stack).top != NULL)
  {

    // Obtain the current top node.
    current_top = (*(*stack).top);

    // Copy the results of the top node.
    node.value = current_top.value;
    node.previous = current_top.previous;

    // Deallocate the top node.
    free((*stack).top);

    // Update the top node.
    (*stack).top = current_top.previous;

  }

  return node;

}
