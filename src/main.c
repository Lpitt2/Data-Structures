// Levi Pittman
// March 17, 2025
// The main driver code for the project.

#include <stdio.h>
#include <stdlib.h>

#include "stack/stack.h"
#include "list/list.h"
#include "queue/queue.h"
#include "binary_tree/binary_tree.h"


// Runs the tests for stack.
void stack_driver();

// Display the contents of an integer stack.
void display_stack(struct Stack stack);

// Display generic information about the stack.
void display_stack_info(struct Stack stack);

// Creates an integer stack node.
struct StackNode* create_int_stack_node(int value);


// Run the tests for queue.
void queue_driver();

// Display the contents of an integer queue.
void display_queue(struct Queue queue);

// Display generic information about the queue.
void display_queue_info(struct Queue queue);

// Creates an integer queue node.
struct QueueNode *create_int_queue_node(int value);


// Run the tests for list.
void list_driver();

// Display the value of a node and deallocate the node.
void display_value_of_node_and_delete(struct ListNode* node);

// Display the contents of a list.
void display_list(struct ListNode *list);

// Display generic information about the list.
void display_list_info(struct ListNode *list);

// Creates an integer list node.
struct ListNode *create_int_list_node(int value);


// Run the tests for binary tree.
void binary_tree_driver();

// Creates an integer binary search tree node.
struct BinaryTreeNode* create_int_binary_tree_node(int value);

// Compares the values of two integer binary tree nodes.
short binary_tree_int_compare(void* root_value, void* node_value);

// Displays the elements of a binary tree node in transversal functions.
void display_binary_tree_element(void* value);

int main()
{

  // Test stacks.
  printf("\n\033[1;35mSTACK DRIVER\033[1;0m\n\n");
  stack_driver();

  // Test queues.
  printf("\n\n\033[1;35mQUEUE DRIVER\033[1;0m\n\n");
  queue_driver();

  // Test linked-lists.
  printf("\n\n\033[1;35mLINKED-LIST DRIVER\033[1;0m\n\n");
  list_driver();

  // Test Binary Tree.
  printf("\n\n\033[1;35mBINARY TREE DRIVER\033[1;0m\n\n");
  binary_tree_driver();

  return 0;

}



/*
 *  Stack Testing Utilities.
*/

// Runs the tests for stack.
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
  printf("Address of root:    %p\n", stack.root);
  printf("Address of top:     %p\n", stack.top);

  // Display the Length of the stack.
  printf("Length:             %i\n", stack_length(stack));

  // Display the contents of the stack.
  display_stack(stack);

  // Display empty lines.
  printf("\n\n");

}

// Creates an integer stack node.
struct StackNode* create_int_stack_node(int value)
{

  // Declare variables.
  struct StackNode* node = NULL;
  int* ptr = (int*)(malloc(sizeof(int)));

  // Set the value of the node.
  (*ptr) = value;

  // Create the stack node.
  node = create_stack_node(ptr);

  return node;
  
}



/*
 * Queue Testing Utilities.
*/

// Run the tests for queue.
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

// Display the contents of an integer queue.
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

// Display generic information about the queue.
void display_queue_info(struct Queue queue)
{

  // Display the address of the top and bottom nodes.
  printf("Address of bottom:  %p\n", queue.bottom);
  printf("Address of top:     %p\n", queue.top);

  // Display the length of the queue.
  printf("Length:             %i\n", queue_length(queue));

  // Display the queue.
  display_queue(queue);

  // Display linme separators.
  printf("\n\n");

}

// Creates an integer queue node.
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



/*
 * Linked-List Utilities.
*/

// Run the tests for list.
void list_driver()
{

  // Create the root node.
  struct ListNode *root = create_int_list_node(5);

  // Display list information.
  display_list_info(root);

  // Create five more nodes into the list.
  struct ListNode *node1 = create_int_list_node(10);
  struct ListNode *node2 = create_int_list_node(15);
  struct ListNode *node3 = create_int_list_node(20);
  struct ListNode *node4 = create_int_list_node(25);
  struct ListNode *node5 = create_int_list_node(30);

  // Insert the five new nodes into the list.
  list_insert(root, node1);
  list_insert(node1, node2);
  list_insert(node2, node3);
  list_insert(node3, node4);
  list_insert(node4, node5);

  // Display list information.
  display_list_info(root);

  // Remove the last list node.
  struct ListNode *node = list_remove(node5);

  // Display the value of the removed node.
  display_value_of_node_and_delete(node);
  node = NULL;

  // Display list information.
  display_list_info(root);

  // Remove a middle list node.
  node = list_remove(node2);

  // Displayt the value of the removed node.
  display_value_of_node_and_delete(node);
  node = NULL;

  // Display list information.
  display_list_info(root);

  // Remove the root node.
  node = list_remove(root);

  // Display the value of the removed node.
  display_value_of_node_and_delete(node);
  node = NULL;

  // Display the list information.
  display_list_info(node1);

  // Catch the removed node.
  node = list_remove(node1);

  // Display the value of the node.
  display_value_of_node_and_delete(node);
  node = NULL;

  // Display the list information.
  display_list_info(node3);

  // Remove the last node.
  node = list_remove(node4);

  // Display the value of the node.
  display_value_of_node_and_delete(node);
  node = NULL;

  // Display list information.
  display_list_info(node3);

  // Remove the final node.
  node = list_remove(node3);

  // Display the value of the node.
  display_value_of_node_and_delete(node);
  node = NULL;

}

// Display the value of a node and deallocate the node.
void display_value_of_node_and_delete(struct ListNode* node)
{

  // Declare variables.
  int* value = ((int*)((*node).value));

  // Display the value of the node.
  printf("Node Value: %i\n\n", (*value));

  // Deallocate the value and node.
  free(value);
  free(node);

}

// Display the contents of a list.
void display_list(struct ListNode *list)
{

  // Seek to the beginning.
  while ((*list).previous != NULL)
  {

    // Seek to the previous node.
    list = (*list).previous;

  }

  // Display an open square bracket.
  printf("[ ");

  // Determine if the list is empty.
  if (list_length(list) == 0)
  {

    // Display the message 'EMPTY LIST'.
    printf("EMPTY LIST ");

  } else
  {

    // Iterate over every element within the list.
    while ((*list).next != NULL)
    {

      // Display the current node.
      printf("%i ", (*(int*)((*list).value)));

      // Seek to the next node.
      list = (*list).next;

    }

    // Display the final node.
    printf("%i ", (*(int*)((*list).value)));

  }

  // Display a closing square bracket.
  printf("]");

}

// Display generic information about the list.
void display_list_info(struct ListNode *list)
{

  // Display the address of the current node.
  printf("Address:            %p\n", list);

  // Display length of list.
  printf("Length:             %i\n", list_length(list));

  // Display list.
  display_list(list);

  // Display separator.
  printf("\n\n");

}

// Creates an integer list node.
struct ListNode* create_int_list_node(int value)
{

  // Declare variables.
  struct ListNode *node = NULL;
  int *node_value = NULL;

  // Allocate and set the value of the node.
  node_value = ((int*)malloc(sizeof(int)));
  (*node_value) = value;

  // Add the integer value to the node.
  node = create_list_node(node_value);

  return node;

}



/*
 * Binary Search Tree Utilities.
*/

void binary_tree_driver()
{

  // Declare the nodes.
  struct BinaryTreeNode *root = create_int_binary_tree_node(5);
  struct BinaryTreeNode *node1 = create_int_binary_tree_node(1);
  struct BinaryTreeNode *node2 = create_int_binary_tree_node(2);
  struct BinaryTreeNode *node3 = create_int_binary_tree_node(3);
  struct BinaryTreeNode *node4 = create_int_binary_tree_node(4);
  struct BinaryTreeNode *node6 = create_int_binary_tree_node(6);
  struct BinaryTreeNode *node7 = create_int_binary_tree_node(7);
  struct BinaryTreeNode *node8 = create_int_binary_tree_node(8);

  int a = 1;
  int b = 2;
  int c = 0;

  // Test comparison method.
  printf ("Compare 1 and 1:  %i\n", binary_tree_int_compare(&a, &a));
  printf ("Compare 1 and 2:  %i\n", binary_tree_int_compare(&a, &b));
  printf ("Compare 1 and 0:  %i\n\n", binary_tree_int_compare(&a, &c));

  // Perform the inorder display of the nodes.
  printf ("Root:     [ ");
  transverse_binary_tree_inorder(root, &display_binary_tree_element);
  printf ("]\n");

  // Insert the node (2) to the root.
  binary_tree_insert(root, node2, &binary_tree_int_compare);

  // Perform the inorder display of the nodes.
  printf ("Insert 2: [ ");
  transverse_binary_tree_inorder(root, &display_binary_tree_element);
  printf ("]\n");

  // Insert the node (4) to the root.
  binary_tree_insert(root, node4, &binary_tree_int_compare);

  // Perform the inorder display of the nodes.
  printf ("Insert 4: [ ");
  transverse_binary_tree_inorder(root, &display_binary_tree_element);
  printf ("]\n");

  // Insert the node (1) to the root.
  binary_tree_insert(root, node1, &binary_tree_int_compare);

  // Perform the inorder display of the nodes.
  printf ("Insert 1: [ ");
  transverse_binary_tree_inorder(root, &display_binary_tree_element);
  printf ("]\n");

  // Insert the node (6) to the root.
  binary_tree_insert(root, node6, &binary_tree_int_compare);

  // Perform the inorder display of the nodes.
  printf ("Insert 6: [ ");
  transverse_binary_tree_inorder(root, &display_binary_tree_element);
  printf ("]\n");

  // Insert the node (3) to the root.
  binary_tree_insert(root, node3, &binary_tree_int_compare);

  // Perform the inorder display of the nodes.
  printf ("Insert 3: [ ");
  transverse_binary_tree_inorder(root, &display_binary_tree_element);
  printf ("]\n");

  // Insert the node (8) to the root.
  binary_tree_insert(root, node8, &binary_tree_int_compare);

  // Perform the inorder display of the nodes.
  printf ("Insert 8: [ ");
  transverse_binary_tree_inorder(root, &display_binary_tree_element);
  printf ("]\n");

  // Insert the node (7) to the root.
  binary_tree_insert(root, node7, &binary_tree_int_compare);

  // Perform the inorder display of the nodes.
  printf ("Insert 7: [ ");
  transverse_binary_tree_inorder(root, &display_binary_tree_element);
  printf ("]\n");

  // Perform preorder transversal.
  printf ("\nPreorder Transversal: [ ");
  transverse_binary_tree_preorder(root, &display_binary_tree_element);
  printf ("]\n");

  // Perform postorder transversal.
  printf ("\nPostorder Transversal: [ ");
  transverse_binary_tree_postorder(root, &display_binary_tree_element);
  printf ("]\n");

}

// Creates an integer binary search tree node.
struct BinaryTreeNode* create_int_binary_tree_node(int value)
{

  // Declare variables.
  int *ptr = NULL;

  // Dynamically allocate the integer value.
  ptr = (int*)(malloc(sizeof(int)));
  (*ptr) = value;

  return create_binary_tree_node(ptr);

}

signed short binary_tree_int_compare(void* root_value, void* node_value)
{

  // Declare variables.
  int root;
  int node;
  signed short result = 0;

  // Ensure that the root and node values are not null.
  if (root_value == NULL || node_value == NULL)
  {
    return 0;
  }
   
  // Convert the values to integers.
  root = (*(int*)(root_value));
  node = (*(int*)(node_value));

  // Perform the comparison.
  if (root > node)
  {
    result = -1;
  } else if (root < node) {
    result = 1;
  }

  return result;

}

// Displays the elements of a binary tree node in transversal functions.
void display_binary_tree_element(void* value)
{

  // Declare variables.
  int *ptr;

  // Ensure that the address of the value is not null.
  if (value == NULL)
  {
    return;
  }

  // Convert the value into a pointer.
  ptr = (int*)(value);

  // Display the value.
  printf ("%i ", (*ptr));

}