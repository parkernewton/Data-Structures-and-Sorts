/*
 * 
 * Name: 			binarySearchTree.h
 *
 * Description: 	
 * 					Contains interface for a BST ADT
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

#include <stdbool.h>

typedef struct node {
	void * data;
	struct node * left;
	struct node * right;

} NODE;

typedef struct tree {
	int count;
	int (* compare)(void * argu1, void * argu2);
	NODE * root;
} BST;

BST * createBST(int(* compare)(void * argu1, void * argu2));
//Allocates and initializes a new BST
//Parameters: int(* compare)(void * argu1, void * argu2) -- pointer to function that compares node data values
//Returns pointer to BST on success, NULL on error

BST * destroyBST(BST * root);
//De-allocates memory for all nodes in BST passed as parameter

bool insertIntoBST(BST * tree, void * data);
//Inserts specified data pointer into BST passed as parameter
//Returns true on success, false on error

bool deleteFromBST(BST * tree, void * dltKey);
//Deletes node containing specified data value (dltKey) from the BST passed as a parameter
//Returns true on success, false on error

void * retrieveFromBST(BST * tree, void * keyPtr);
//Retrieves specified data value (keyPtr) from BST passed as a parameter
//Returns keyPtr on success, NULL on error

void traverseBST(BST * tree, void(* process)(void *data));
//Implements inorder traversal of BST passed as parameter
//Executes inorder process function passed as parameter

bool BSTIsEmpty(BST * tree);
//Returns true if specified BST if empty, else false

bool BSTIsFull(BST * tree);
//Full BST is defined as having a size >= 0 where no additional memory can be allocated for a potential new node
//Returns true if specified BST is full, else false

int BSTCount(BST * tree);
//Returns the number of nodes in the BST passed as a parameter, -1 on error

#endif /* BINARYSEARCHTREE_H_ */
