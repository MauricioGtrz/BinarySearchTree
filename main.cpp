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
#include "inttree.h"

using namespace std;


int main()
{
   BinarySearchTree t;
   t.insert(10); t.insert(0); t.insert(0);
   t.insert(19); t.insert(-10); t.insert(-5);
   t.insert(14); t.insert(0); t.insert(30);
   t.insert(2); t.insert(19); t.insert(30);
   t.print();
   t.erase(30); t.erase(-10); t.erase(0); t.erase(10);
   t.print();
   cout << "The count of 30 is " << t.count(30) << ".\n";
   cout << "The count of 0 is " << t.count(0) << ".\n";
   cout << "The smallest integer is " << t.smallest() << ".\n";
   return 0;
}

