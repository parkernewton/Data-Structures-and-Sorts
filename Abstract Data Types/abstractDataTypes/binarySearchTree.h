/*
 * 
 * Name: 			binarySearchTree.h
 *
 * Description: 	
 * 					Contains interface for a BST ADT that stores integer values.
 * 					A binary search tree (BST) is a binary tree ADT with the following properties:
 * 						1) Each subtree itself is a BST
 * 						2) All the nodes to the left of the root are less than the value of the root
 * 						3) All the nodes to the right of the root are greater than or equal to the root
 * 
 * Author: 			Parker C. Newton 
 * 
 * Created: 		Oct 19, 2014
 * 
 * Project: 		abstractDataTypes
 * 
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

BINSEARCHTREE * createBinSearchTree(void);
//allocates and initializes a new binary search tree ADT

void destoryBinSearchTree(BINSEARCHTREE * tree);
//de-allocates a binary search tree ADT passed as a parameter

int getBinSearchTreeCount(BINSEARCHTREE * tree);
//returns the number of nodes in the BST

void * searchBinSearchTree(BINSEARCHTREE * tree, int data);
//searches the BST for the specified data value and returns a pointer to the node

void traverseBinSearchTree(BINSEARCHTREE * tree);
//in-order traversal of specified BST; prints to stdout

int insertIntoBinSearchTree(BINSEARCHTREE * tree, int data);
//creates new tree node with specified data value and inserts into BST passed as a parameter
//returns 1 on success and 0 on error

int removeFromBinSearchTree(BINSEARCHTREE * tree, int data);
//removes node containing specified data value from the BST
//returns 1 on success and 0 on error

#endif /* BINARYSEARCHTREE_H_ */
