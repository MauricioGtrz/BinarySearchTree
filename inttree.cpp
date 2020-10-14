/*
PIC 10B Homework 7, inttree.cpp , inttree.h
Purpose: The purpose of this program to is to demonstrate a binary search tree created from scratch.
I added some functionality that is also able to look for the smallest value and also erase, insert, and
count a value of the user's choosing. Duplicates are also allowed in this binary search tree.

Output:
 30 30 19 19 14 10 2 0 0 0 -5 -10
 30 19 19 14 2 0 0 -5
 The count of 30 is 1.
 The count of 0 is 2.
 The smallest integer is -5.

Date: 06/05/20
*/

#include <iostream>
#include <string>
#include "inttree.h"

BinarySearchTree::BinarySearchTree()
{  
   root = NULL; // sets the rooot to null
}

void BinarySearchTree::print() const
{  
   if (root != NULL) // looks to see if root has been assigned value. If so then call funtion to print nodes
      root->print_nodes();
   std::cout << "\n"; // new line after nodes have been printed
}

void BinarySearchTree::insert(int data)
{  
   TreeNode* new_node = new TreeNode; // new node is created
   new_node->data = data; // data is being assigned to the node
   new_node->left = NULL; // left pointer set to null
   new_node->right = NULL; // right pointer set to null
   if (root == NULL) root = new_node; // checks to see if root is empty. If so set this new node to the root
   else root->insert_node(new_node); // if root is taken then call funtion to insert node
}


/*
 This function assigns the new node according to its value.
 It compares it to the data of the current node. If the new node
 is smaller to the current node then it is sent to the left but if
 it is greater than it is sent to the right. If the current value of node
 is null then the new node is set to that pointer (left or right).
*/
void TreeNode::insert_node(TreeNode* new_node)
{  
   if (new_node->data < data)
   {  
      if (left == NULL) left = new_node;
      else left->insert_node(new_node);
   }
   else if (data < new_node->data)
   {  
      if (right == NULL) right = new_node;
      else right->insert_node(new_node);
   }
   else
   {
      if (right == NULL) right = new_node;
      else right->insert_node(new_node);
   }
}

int BinarySearchTree::count(int data) const
{
   if (root == NULL) return 0; // if the root is null then that means that there are no other nodes in the tree so return 0
   else return root->count_dup(data); // if root does exist then execute count_dup to check for duplicates
}

void BinarySearchTree::erase(int data)
{
   // Find node to be removed

   TreeNode* to_be_removed = root;
   TreeNode* parent = NULL;
   bool found = false;
   while (!found && to_be_removed != NULL)
   {
      if (to_be_removed->data < data)
      {
         parent = to_be_removed;
         to_be_removed = to_be_removed->right;
      }
      else if (data < to_be_removed->data)
      {
         parent = to_be_removed;
         to_be_removed = to_be_removed->left;
      }
      else found = true;
   }

   if (!found) return;

   // to_be_removed contains data

   // If one of the children is empty, use the other

   if (to_be_removed->left == NULL || to_be_removed->right == NULL)
   {
      TreeNode* new_child;
      if (to_be_removed->left == NULL) 
         new_child = to_be_removed->right;
      else 
         new_child = to_be_removed->left;
       if (parent == NULL) // Found in root
         root = new_child;
      else if (parent->left == to_be_removed)
         parent->left = new_child;
      else 
         parent->right = new_child;
      return;
   }
      
   // Neither subtree is empty

   // Find smallest element of the right subtree

   TreeNode* smallest_parent = to_be_removed;
   TreeNode* smallest = to_be_removed->right;
   while (smallest->left != NULL)
   {
      smallest_parent = smallest;
      smallest = smallest->left;
   }

   // smallest contains smallest child in right subtree
       
   // Move contents, unlink child
   to_be_removed->data = smallest->data;
   if (smallest_parent == to_be_removed) 
      smallest_parent->right = smallest->right; 
   else 
      smallest_parent->left = smallest->right; 
}

/*
This checks if the value is less than or greater than the data of the compared node.
If so then it checks to see if the left or right pointer of the node is null and if so
then return 0 but if not then repeat count_dup for next node.
 
If the value is equal to the data of the compared then it checks to see if there is a node in the right pointer.
If it is null then return 1 but if there is something then check to see if it is a duplicate and add 1.
 
This function works recusively
*/
int TreeNode::count_dup(int value)
{
   if (value < data)
   {
      if (left == NULL) return 0;
      else return left->count_dup(value);
   }
   else if (data < value)
   {
      if (right == NULL) return 0;
      else return right->count_dup(value);
   }
   else
   {
      if (right == NULL) return 1;
      else return right->count_dup(value) + 1;
   }
}

/* If there is somthing in either the right or left pointer then print what is inside */
void TreeNode::print_nodes() const
{
   if (right != NULL)
      right->print_nodes();
   std::cout << data << " ";
   if (left != NULL)
      left->print_nodes();
}

int BinarySearchTree::smallest() const
{
   if (root != NULL) // if there is something in the root then search for the smallest starting at the root
      return root->find_smallest();
   else return 0; // if root is empty return 0
}

int TreeNode::find_smallest() const
{
   if (left != NULL) // if there is a node in the left pointer than check that move to that node
      return left->find_smallest();
   else return data; // if there is no other node to the left of this one then this means that it is has the smallest value so return its data.
}
