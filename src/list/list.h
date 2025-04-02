// Levi Pittman
// March 17, 2025
// Contains the declarations for the linked list data structure.

/*
 * Structures:
 *  - ListNode:                                 Represents a generic node within a linked-list.
 * 
 * Functions:
 *  - ListNode* create_list_node(void*):        Creates an empty linked-list node.
 *  - unsigned int list_length(ListNode*):      Returns the number of nodes within a linked-list.
 *  - void list_insert(ListNode*, ListNode*):   Inserts a node after another node within a linked-list.
 *  - list_remove(ListNode*):                   Removes a node from a linked-list.
*/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#ifndef NULL
#define NULL 0x0
#endif


// Represents a generic node within a linked-list.
struct ListNode
{

  struct ListNode *previous;
  struct ListNode *next;
  void *value;

};


// Creates a new linked-list node.
struct ListNode *create_list_node(void *value);

// Returns the number of nodes within a linked-list.
unsigned int list_length(struct ListNode *list);

// Inserts a node after another node within a linked-list.
void list_insert(struct ListNode* origin, struct ListNode* node);

// Removes a node from a linked-list.
struct ListNode *list_remove(struct ListNode* node);


#endif