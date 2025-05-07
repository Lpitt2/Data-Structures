// Levi Pittman
// March 17, 2025
// Contains the declarations for a binary search tree data structure.

/*
 * Structures:
 *  - BinaryTreeNode:                                                                                 Represents a generic node within a binary tree.
 * 
 * Types:
 *  - signed short (*binary_tree_compare_function)(void*, void*):                                     Determines if the node value is greater than or less than the root node value.
 *  - void (*binary_tree_transversal_function)(void*):                                                Performs a user-defined operation during transversal of a binary tree.
 * 
 * Functions:
 *  - BinaryTreeNode* create_binary_tree_node(void*):                                                 Creates an empty binary search tree node.
 *  - void binary_tree_insert(BinaryTreeNode*, BinaryTreeNode*, binary_tree_compare_function):        Inserts a node into the binary search tree.
 *  - void transverse_binary_tree_preorder(BinaryTreeNode*, binary_tree_transversal_function):        Performs preorder transversal of a binary search tree in the form of preorder.
 *  - void transverse_binary_tree_postorder(BinaryTreeNode*, binary_tree_transversal_function):       Performs postorder transversal of a binary search tree in the form of postorder.
 *  - void transverse_binary_tree_inorder(BinaryTreeNode*, binary_tree_transversal_function):         Performs inorder transversal of a binary search tree in the form of inorder.
*/

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__


// Represents a generic node within a binary tree.
struct BinaryTreeNode
{

  void* value;
  struct BinaryTreeNode *left;
  struct BinaryTreeNode* right;

};


// Determines if the node value is greater than or less than the root node value.
typedef signed short (*binary_tree_compare_function)(void* root_value, void* node_value);

// Performs a user-defined operation during transversal of a binary tree.
typedef void (*binary_tree_transversal_function)(void *value);


// Creates an empty binary search tree node.
struct BinaryTreeNode* create_binary_tree_node(void* value);

// Inserts a node into the binary search tree.
void binary_tree_insert(struct BinaryTreeNode* root, struct BinaryTreeNode* node, binary_tree_compare_function compare_function);

// Performs preorder transversal of a binary search tree in the form of preorder.
void transverse_binary_tree_preorder(struct BinaryTreeNode* root, binary_tree_transversal_function node_display_function);

// Performs postorder transversal of a binary search tree in the form of postorder.
void transverse_binary_tree_postorder(struct BinaryTreeNode *root, binary_tree_transversal_function node_display_function);

// Performs inorder transversal of a binary search tree in the form of inorder.
void transverse_binary_tree_inorder(struct BinaryTreeNode *root, binary_tree_transversal_function node_display_function);


#endif