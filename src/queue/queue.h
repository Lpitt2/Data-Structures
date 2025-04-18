// Levi Pittman
// March 17, 2025
// Contains the declarations for the queue data structure.

/*
 * Structures:
 *  - QueueNode:                        Represents a generic node within a queue.
 *  - Queue:                            Represents a generic queue.
 * 
 * Functions:
 *  - create_queue():                   Creates an empty queue.
 *  - create_queue_node(void*):         Creates a new queue node.
 *  - queue_push(Queue*, QueueNode*):   Pushes a node to the top of the queue.
 *  - queue_pop(Queue*):                Pops the bottom node from a queue.
 *  - queue_length(Queue):              Returns the number of nodes within a queue.
*/

#ifndef __QUEUE_H__
#define __QUEUE_H__


// Represents a generic node within a queue.
struct QueueNode
{

  void *value;
  struct QueueNode *next;

};

// Represents a generic queue.
struct Queue
{

  struct QueueNode *bottom;
  struct QueueNode *top;

};


// Creates an empty queue.
struct Queue create_queue();

// Creates a new queue node.
struct QueueNode* create_queue_node(void *value);

// Pushed a node to the top of the queue.
void queue_push(struct Queue *queue, struct QueueNode *node);

// Pops the bottom node from a queue.
struct QueueNode queue_pop(struct Queue *queue);

// Returns the number of nodes within a queue.
unsigned int queue_length(struct Queue queue);


#endif