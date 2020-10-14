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


#ifndef _INTTREE_H
#define _INTTREE_H

#include <iostream>
#include <string>

class TreeNode
{
public:
   void insert_node(TreeNode* new_node); // adds a new node to the tree with an assigned value
   void print_nodes() const; // prints nodes in succession
   int count_dup(int value); // counts the duplicates in the tree if there are any
   int find_smallest() const; // looks for the smallest value in the tree
private:
   int data; // value assigned to node
   TreeNode* left; // pointers to left node
   TreeNode* right; // pointer to right node
friend class BinarySearchTree; // allows this class to access private variables in TreeNode
};

class BinarySearchTree
{
public:
   BinarySearchTree();
   void insert(int data); // allows user to add values to the tree
   void erase(int data); // erases a node
   int count(int data) const; // counts the amount of times a number appears in the tree
   void print() const; // prints out tree in order
   int smallest() const; // finds the smallest number in the tree
private:
   TreeNode* root; // assigns the first node as the root
};

#endif
