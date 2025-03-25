// Levi Pittman
// March 17, 2025
// Contains the declarations for the queue data structure.
#ifndef __QUEUE_H__
#define __QUEUE_H__

#define NULL 0x0

struct QueueNode
{

  void *value;
  struct QueueNode *next;

};

struct Queue
{

  struct QueueNode *bottom;
  struct QueueNode *top;

};


struct Queue create_queue();

struct QueueNode* create_queue_node(void *value);

void queue_push(struct Queue *queue, struct QueueNode *node);

struct QueueNode queue_pop(struct Queue *queue);

unsigned int queue_length(struct Queue queue);

#endif