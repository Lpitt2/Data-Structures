// Levi Pittman
// March 17, 2025
// The main driver code for the project.

#include <stdio.h>
#include <stdlib.h>

#include "stack/stack.h"
#include "list/list.h"
#include "queue/queue.h"


void stack_driver();

void display_stack(struct Stack stack);

void display_stack_info(struct Stack stack);

struct StackNode* create_int_stack_node(int value);


void queue_driver();

void display_queue(struct Queue queue);

void display_queue_info(struct Queue queue);

struct QueueNode *create_int_queue_node(int value);



int main()
{

  // Test stacks.
  printf("\n\033[1;35mSTACK DRIVER\033[1;0m\n\n");
  stack_driver();

  // Test queues.
  printf("\n\n\033[1;35mQUEUE DRIVER\033[1;0m\n\n");
  queue_driver();

  return 0;

}



/*
 *  Stack Testing Utilities.
*/

void stack_driver()
{

  // Declare stack.
  struct Stack stack = create_stack();

  // Display stack info.
  display_stack_info(stack);

  // Create the first node.
  struct StackNode* node = create_int_stack_node(5);
  stack_push(&stack, node);

  // Display the stack info.
  display_stack_info(stack);

  // Create three more nodes.
  struct StackNode* node1 = create_int_stack_node(10);
  struct StackNode* node2 = create_int_stack_node(15);
  struct StackNode* node3 = create_int_stack_node(20);

  // Push the three nodes to the stack.
  stack_push(&stack, node1);
  stack_push(&stack, node2);
  stack_push(&stack, node3);

  // Display the stack info.
  display_stack_info(stack);

  // Pop the top from the stack.
  struct StackNode popped_node = stack_pop(&stack);

  // Display the node that was popped.
  printf("Popped Node: %i\n\n", (*(int*)(popped_node.value)));

  // Display stack info.
  display_stack_info(stack);

  // Pop another element from the stack.
  stack_pop(&stack);

  // Display the stack info.
  display_stack_info(stack);

  // Pop the last elements from the stack.
  stack_pop(&stack);
  stack_pop(&stack);

  // Display the stack info.
  display_stack_info(stack);

}

// Display the contents of an integer stack.
void display_stack(struct Stack stack)
{

  // Declare variables.
  struct StackNode *node;

  // Display an open square bracket.
  printf("[ ");

  // Determine if the stack is empty.
  if (stack.top == NULL)
  {

    // Display the message 'EMPTY STACK'.
    printf("EMPTY STACK ");

  } else if (stack.top == stack.root)
  {

    // Display the root element.
    printf("%i ", (*(int*)((*stack.root).value)));

  } else 
  {

    // Copy the top node to the current node.
    node = stack.top;

    // Iterate through the stack.
    do
    {
      
      // Display the current element.
      printf("%i ", (*(int*)((*node).value)));

      // seek to the previous node.
      node = (*node).previous;

    } while (((*node).previous != NULL) && (node != stack.root));
    
    // Display the root.
    printf("%i ", (*(int*)((*stack.root).value)));

  }

  // Display a closing square bracket.
  printf("]");

}

// Display generic information about the stack.
void display_stack_info(struct Stack stack)
{

  // Display the address of the root and the top of the stack.
  printf("Address of root:  %p\n", stack.root);
  printf("Address of top:   %p\n", stack.top);

  // Display the Length of the stack.
  printf("Length:           %i\n", stack_length(stack));

  // Display the contents of the stack.
  display_stack(stack);

  // Display empty lines.
  printf("\n\n");

}

// Create an integer stack node.
struct StackNode* create_int_stack_node(int value)
{

  // Declare variables.
  struct StackNode* node = (struct StackNode*)(malloc(sizeof(struct StackNode)));
  int* ptr = (int*)(malloc(sizeof(int)));

  // Assign the value to the node.
  (*ptr) = value;
  (*node).value = ptr;

  return node;
  
}



/*
 * Queue Testing Utilities.
*/

void queue_driver()
{

  // Declare variables.
  struct Queue queue = create_queue();

  // Display queue information.
  display_queue_info(queue);

  // Create and push a node to the queue.
  struct QueueNode* node = create_int_queue_node(5);
  queue_push(&queue, node);

  // Display queue information.
  display_queue_info(queue);

  // Create and push three nodes to the queue.
  struct QueueNode* node1 = create_int_queue_node(10);
  struct QueueNode* node2 = create_int_queue_node(15);
  struct QueueNode* node3 = create_int_queue_node(20);

  queue_push(&queue, node1);
  queue_push(&queue, node2);
  queue_push(&queue, node3);

  // Display queue information.
  display_queue_info(queue);

  // Pop a single node from the queue.
  queue_pop(&queue);

  // Display queue information.
  display_queue_info(queue);

  // Pop another node from the queue.
  struct QueueNode bottom_node = queue_pop(&queue);

  // Display the value of the node.
  printf("%i\n\n", (*(int*)(bottom_node.value)));

  // Display queue information.
  display_queue_info(queue);

  // Pop the rest of the nodes from the queue.
  queue_pop(&queue);
  queue_pop(&queue);

  // Display queue information.
  display_queue_info(queue);

}

void display_queue(struct Queue queue)
{

  // Declare variables.
  struct QueueNode *node = NULL;

  // Display an open square bracket.
  printf("[ ");

  // Determine if the queue is empty.
  if (queue.bottom == NULL || queue.top == NULL)
  {

    // Display a string indicating that the queue is empty.
    printf("QUEUE EMPTY ");

  } else if (queue.bottom == queue.top)
  {

    // Display the value of the bottom element.
    printf("%i ", (*(int*)((*queue.bottom).value)));

  } else
  {

    // Store the address of the bottom element of the queue in 'node'.
    node = queue.bottom;

    // Iterate over all of the elements within the queue.
    while ((node != NULL) && (node != queue.top))
    {

      // Display the value of the current element.
      printf("%i ", (*(int*)((*node).value)));

      // Seek to the next node.
      node = (*node).next;

    }

    // Display the top node.
    printf("%i ", (*(int*)(*queue.top).value));

  }

  // Display a closing square bracket.
  printf("]");

}

void display_queue_info(struct Queue queue)
{

  // Display the queue.
  display_queue(queue);
  
  // Display linme separators.
  printf("\n\n");

}

struct QueueNode *create_int_queue_node(int value)
{

  // Declare variables.
  int *ptr = NULL;
  struct QueueNode *node = NULL;

  // Dynamically create the integer value.
  ptr = (int*)(malloc(sizeof(int)));

  // Set the value.
  (*ptr) = value;

  // Create the node.
  node = create_queue_node(ptr);

  return node;

}
