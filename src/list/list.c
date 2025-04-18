// Levi Pittman
// March 17, 2025
// Contains the implementation for the linked list data structure.

/*
 * Functions:
 *  - ListNode* create_list_node(void*):        Creates an empty linked-list node.
 *  - unsigned int list_length(ListNode*):      Returns the number of nodes within a linked-list.
 *  - void list_insert(ListNode*, ListNode*):   Inserts a node after another node within a linked-list.
 *  - list_remove(ListNode*):                   Removes a node from a linked-list.
*/

#include <stdlib.h>
#include <stddef.h>

#include "list.h"


// Creates a new linked-list node.
struct ListNode *create_list_node(void *value)
{

  // Declare variables.
  struct ListNode* node = (struct ListNode*)(malloc(sizeof(struct ListNode)));

  // Set the defaults to the node.
  (*node).previous = NULL;
  (*node).next = NULL;
  (*node).value = value;

  return node;

}

// Returns the number of nodes within a linked-list.
unsigned int list_length(struct ListNode *node)
{

  // Declare variables.
  unsigned int length = 0;

  // Determine if the list is empty.
  if (node != NULL)
  {

    // Set the value of 'length' equal to one.
    length = 1;

    // Seek to the root node.
    while ((*node).previous != NULL)
    {

      // Seek to the previous node.
      node = (*node).previous;

    }

    // Iterate until the end is reached.
    while ((*node).next != NULL)
    {

      // Increment the value of 'length'.
      ++length;

      // Seek to the next node.
      node = (*node).next;

    }

  }

  return length;

}

// Inserts a node after another node within a linked-list.
void list_insert(struct ListNode* origin, struct ListNode* node)
{

  // Declare variables.
  struct ListNode* next_node = (*origin).next;

  // Set the connections of the new node.
  (*node).previous = origin;
  (*node).next = next_node;

  // Set the next node connection of the previous node to the new node.
  (*origin).next = node;

  // Determine if the next node is valid.
  if (next_node != NULL)
  {

    // Set the previous connection of the next node to the new node.
    (*next_node).previous = node;

  }

}

// Removes a node from a linked-list.
struct ListNode *list_remove(struct ListNode* origin)
{

  // Determine the state of the node.
  if (((*origin).previous != NULL) && ((*origin).next != NULL))
  {

    // Update the previous and next nodes.
    (*(*origin).previous).next = (*origin).next;
    (*(*origin).next).previous = (*origin).previous;

  } else if ((*origin).previous != NULL)
  {

    // Update the previous node.
    (*(*origin).previous).next = NULL; 

  } else if ((*origin).next != NULL)
  {

    // Update the next node.
    (*(*origin).next).previous = NULL;

  }

  return origin;

}
