// Levi Pittman
// April 18, 2025
// Contains the implementation code for the binary search tree data structure.

/*
 * Functions:
 *  - BinaryTreeNode* create_binary_tree_node(void*):                                            Creates an empty binary search tree node.
 *  - void binary_tree_insert(BinaryTreeNode*, BinaryTreeNode*, binary_tree_compare_function):   Inserts a node into the binary search tree.
 *  - void transverse_binary_tree_preorder(BinaryTreeNode*, binary_tree_transversal_function):   Performs preorder transversal of a binary search tree in the form of preorder.
 *  - void transverse_binary_tree_postorder(BinaryTreeNode*, binary_tree_transversal_function):  Performs postorder transversal of a binary search tree in the form of postorder.
 *  - void transverse_binary_tree_inorder(BinaryTreeNode*, binary_tree_transversal_function):    Performs inorder transversal of a binary search tree in the form of inorder.
 *  - void reverse_binary_tree(struct BinaryTreeNode *root):                                     Switches the sides that elements are on in a binary tree.
*/

#include <stddef.h>
#include <stdlib.h>

#include "binary_tree.h"

// Creates an empty binary search tree node.
struct BinaryTreeNode* create_binary_tree_node(void* value)
{

  // Declare variables.
  struct BinaryTreeNode *node = NULL;

  // Dynamically allocate the node.
  node = (struct BinaryTreeNode*)(malloc(sizeof(struct BinaryTreeNode)));

  // Initialize the left and right branches.
  (*node).left = NULL;
  (*node).right = NULL;

  // Setup the value.
  (*node).value = value;

  return node;

}

// Inserts a node into the binary search tree.
void binary_tree_insert(struct BinaryTreeNode* root, struct BinaryTreeNode* node, binary_tree_compare_function compare_function)
{

  // Declare variables.
  signed short comparison = 0;

  // Ensure that root and node are not null.
  if (root == NULL || node == NULL)
  {
    return;
  }

  // Compare the values of root and null.
  comparison = compare_function((*root).value, (*node).value);

  // Determine which side to place node on.
  if (comparison < 0) 
  {

    // Determine if the left child node exists.
    if ((*root).left == NULL)
    {

      // Assign the node to the left child of the root.
      (*root).left = node;

    } else {

      // Place node on the left.
      binary_tree_insert((*root).left, node, compare_function);

    }

  } else if (comparison > 0)
  {

    // Determine if the right child node exists.
    if ((*root).right == NULL)
    {

      // Assign the node to the right child of the root.
      (*root).right = node;

    } else {

      // Place node on the right.
      binary_tree_insert((*root).right, node, compare_function);

    }

  }

}

// Performs preorder transversal of a binary search tree in the form of preorder.
void transverse_binary_tree_preorder(struct BinaryTreeNode* root, binary_tree_transversal_function node_transversal_function)
{

  // Ensure that the current node is not null.
  if (root == NULL)
  {
    return;
  }

  // Execute the transversal operation on the value of the root node.
  node_transversal_function((*root).value);

  // Determine if there is a left node.
  if ((*root).left != NULL)
  {

    // Perform preorder transversal on the left node.
    transverse_binary_tree_preorder((*root).left, node_transversal_function);

  } 

  // Determine if there is a right node.
  if ((*root).right != NULL)
  {

    // Perform preorder transversal on the right node.
    transverse_binary_tree_preorder((*root).right, node_transversal_function);

  }

}

// Performs postorder transversal of a binary search tree in the form of postorder.
void transverse_binary_tree_postorder(struct BinaryTreeNode *root, binary_tree_transversal_function node_transversal_function)
{

  // Ensure that the current node is not null.
  if (root == NULL)
  {
    return;
  }

  // Determine if there is a left node.
  if ((*root).left != NULL)
  {

    // Preform preorder transversal on the left node.
    transverse_binary_tree_postorder((*root).left, node_transversal_function);

  }

  // Determine if there is a right node.
  if ((*root).right != NULL)
  {

    // Preform preorder transversal on the right node.
    transverse_binary_tree_postorder((*root).right, node_transversal_function);

  }

  // Execute the transversal operation on the value of the root node.
  node_transversal_function((*root).value);

}

// Performs inorder transversal of a binary search tree in the form of inorder.
void transverse_binary_tree_inorder(struct BinaryTreeNode *root, binary_tree_transversal_function node_transversal_function)
{

  // Ensure that the current node is not null.
  if (root == NULL)
  {
    return;
  }

  // Determine if there is a left node.
  if ((*root).left != NULL)
  {

    // Perform inorder transversal on the left node.
    transverse_binary_tree_inorder((*root).left, node_transversal_function);

  }

  // Execute the transversal operation on the value of the root node.
  node_transversal_function((*root).value);

  // Determine if there is a right node.
  if ((*root).right != NULL)
  {

    // Perform inorder transversal on the right node.
    transverse_binary_tree_inorder((*root).right, node_transversal_function);

  }

}

// Switches the sides that elements are on in a binary tree.
void reverse_binary_tree(struct BinaryTreeNode *root)
{

  // Declare local variables.
  struct BinaryTreeNode *temp = NULL;

  // Ensure that the root is not null.
  if (root == NULL)
  {
    return;
  }

  // Determine if there is a left node.
  if ((*root).left != NULL)
  {

    // Perform pre-order transversal of the left node.
    reverse_binary_tree((*root).left);

  }

  // Determine if there is a right node.
  if ((*root).right != NULL)
  {

    // Perform post-order transversal of the right node.
    reverse_binary_tree((*root).right);

  }

  // Swap the nodes.
  temp = (*root).left;
  (*root).left = (*root).right;
  (*root).right = temp;

}