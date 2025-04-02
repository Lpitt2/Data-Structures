// Levi Pittman
// March 17, 2025
// Contains the implementation code for the queue data structure.

/*
* Functions:
*  - create_queue():                   Creates an empty queue.
*  - create_queue_node(void*):         Creates a new queue node.
*  - queue_push(Queue*, QueueNode*):   Pushes a node to the top of the queue.
*  - queue_pop(Queue*):                Pops the bottom node from a queue.
*  - queue_length(Queue):              Returns the number of nodes within a queue.
*/

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>


// Creates an empty queue.
struct Queue create_queue()
{

  // Declare variables.
  struct Queue queue;

  // Set the default bottom and top nodes.
  queue.bottom = NULL;
  queue.top = NULL;

  return queue;

}

// Creates a new queue node.
struct QueueNode* create_queue_node(void *value)
{

  // Declare variables.
  struct QueueNode *node = NULL;

  // Dynamically allocate the node.
  node = (struct QueueNode *)(malloc(sizeof(struct QueueNode)));

  // Set the default node.
  (*node).next = NULL;

  // Set the value of the node.
  (*node).value = value;

  return node;

}

// Pushed a node to the top of the queue.
void queue_push(struct Queue *queue, struct QueueNode *node)
{

  // Determine if the queue is empty.
  if ((*queue).top == NULL)
  {

    // Set the node to the bottom and top nodes.
    (*queue).bottom = node;
    (*queue).top = node;

  } else
  {

    // Update the top node.
    (*(*queue).top).next = node;

    // Change the top node to the new node.
    (*queue).top = node;

  }

}

// Pops the bottom node from a queue.
struct QueueNode queue_pop(struct Queue *queue)
{

  // Declare variables.
  struct QueueNode node;

  // Set up the node.
  node.value = NULL;
  node.next = NULL;

  // Ensure that the queue is nopt empty.
  if ((*queue).bottom != NULL)
  {

    // Copy the contents of the bottom node to 'node'.
    node.value = (*(*queue).bottom).value;
    node.next = (*(*queue).bottom).next;

    // Determine if the bottom node is not null.
    if ((*queue).bottom == (*queue).top)
    {

      // Delete the bottom node.
      free((*queue).bottom);

      // Set both the top and gbottom nodes to null.
      (*queue).bottom = NULL;
      (*queue).top = NULL;

    } else
    {

      // Deallocate the bottom node.
      free((*queue).bottom);

      // Update the bottom node pointer.
      (*queue).bottom = node.next;

    }

  }

  return node;

}

// Returns the number of nodes within a queue.
unsigned int queue_length(struct Queue queue)
{

  // Declare variables.
  unsigned int length = 0;
  struct QueueNode *node = NULL;

  // Ensure that the queue is not null.
  if ((queue.top != NULL) && (queue.bottom != NULL))
  {

    // Set the value of 'length' to one.
    length = 1;

    // Iterate over every node within the queue.
    node = queue.bottom;
    while (node != NULL && node != queue.top)
    {

      // Increment the value of 'length'.
      ++length;

      // Seek to the next node.
      node = (*node).next;

    }

  }

  return length;

}
