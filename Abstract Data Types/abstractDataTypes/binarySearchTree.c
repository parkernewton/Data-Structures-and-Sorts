/*
 * 
 * Name: 			binarySearchTree.c
 *
 * Description: 	Contains implementation for a BST ADT.
 * 					A binary search tree (BST) is a binary tree ADT with the following properties:
 * 						1) Each subtree itself is a BST
 * 						2) All the nodes to the left of the root are less than the value of the root
 * 						3) All the nodes to the right of the root are greater than or equal to the root
 * 
 * Author: 			Parker C. Newton 
 * 
 * Created: 		Nov 4, 2014
 * 
 * Project: 		abstractDataTypes
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "binarySearchTree.h"


static NODE * _insert(BST * tree, NODE * root, NODE * pNew);

static NODE * _delete(BST * tree, NODE * root, void * data, bool * success);

static void * _retrieve(BST * tree, NODE * root, void * data);

static void _traverse(NODE * root, void(* process)(void * data));

static NODE * _destroy(NODE * root);

BST * createBST(int(* compare)(void * argu1, void * argu2)){
	if(!compare)
		return NULL;

	BST * tree = (BST *)malloc(sizeof(BST));
	if(tree){
		tree->root = NULL;
		tree->compare = compare;
		tree->count = 0;
	}
	return tree;
}

bool insertIntoBST(BST * tree, void * data){
	if(!tree || !data)
		return false;

	NODE * pNew = (NODE *)malloc(sizeof(NODE));
	if(!pNew)
		return false;

	pNew->data = data;
	pNew->left = NULL;
	pNew->right = NULL;

	if((tree->count)++ == 0){
		tree->root = pNew;
	}
	else {
		_insert(tree, tree->root, pNew);
	}
	return true;
}

NODE * _insert(BST * tree, NODE * root, NODE * pNew){
	if(!root){
		//once we reach the bottom of the tree, return pNew so that it can be inserted into its appropriate spot
		return pNew;
	}

	if(tree->compare(pNew->data, root->data) < 0){
		//pNew->data < root->data
		root->left = _insert(tree, root->left, pNew);
		return root;
	}
	else{
		//pNew->data >= root->data
		root->right = _insert(tree, root->right, pNew);
		return root;
	}

	//lastly, we return the original root
	return root;
}

bool deleteFromBST(BST * tree, void * dltKey){
	if(!tree || !dltKey)
		return false;

	bool success;
	NODE * newRoot = _delete(tree, tree->root, dltKey, &success);
	if(success){
		tree->root = newRoot;
		(tree->count)--;
		if(tree->count == 0){
			//BST is now empty
			tree->root = NULL;
		}
	}
	return success;
}

NODE * _delete(BST * tree, NODE * root, void * data, bool * success){
	if(root == NULL){
		//node containing data not found
		*success = false;
		return NULL;
	}

	if(tree->compare(data, root->data) < 0){
		root->left = _delete(tree, root->left, data, success);
	}
	else if(tree->compare(data, root->data) >= 0){
		root->right = _delete(tree, root->right, data, success);
	}
	else {
		//We have found the node containing data -->> time to delete it
		if(!root->left){
			//no left subtree
			NODE * pDel = root;
			NODE * pNew = pDel->right;
			free(pDel->data);
			free(pDel);
			*success = true;
			return pNew;
		}
		else if(!root->right){
			//only left subtree
			NODE * pDel = root;
			NODE * pNew = pDel->right;
			free(pDel->data);
			free(pDel);
			*success = true;
			return pNew;
		}
		else{
			//pDel has 2 subtrees
			//we take the largest value of the left subtree, and swap its data with that of pDel
			NODE * pTemp = root->left;
			while(pTemp != NULL){
				pTemp = pTemp->right;
			}
			void * tempData = root->data;
			root->data = pTemp->data;
			pTemp->data = tempData;

			//now, we can simply delete the pTemp node which holds the data to be deleted
			root->left = _delete(tree, root->left, pTemp->data, success);
		}
	}

	return root;
}

void * retrieveFromBST(BST * tree, void * keyPtr){
	if(!tree || !keyPtr)
		return NULL;

	return _retrieve(tree, tree->root, keyPtr);
}

void * _retrieve(BST * tree, NODE * root, void * data){
	if(!root){
		//data is not found
		return NULL;
	}

	//We implement recursive binary search to find the data value
	if(tree->compare(data, root->data) < 0){
		return _retrieve(tree, root->left, data);
	}
	else if(tree->compare(data, root->data) > 0){
		return _retrieve(tree, root->right, data);
	}
	else {
		//we have found the node containing our data
		return root->data;
	}
}

void traverseBST(BST * tree, void(* process)(void *data)){
	if(!tree || !process){
		return;
	}

	_traverse(tree->root, process);
}

void _traverse(NODE * root, void(* process)(void * data)){
	if(!root)
		return;

	_traverse(root->left, process);
	process(root->data);
	_traverse(root->right, process);
}

BST * destroyBST(BST * tree){
	 if(tree){
		 _destroy(tree->root);
		 free(tree);
	 }
	 return NULL;
}

NODE * _destroy(NODE * root){
	if(root){
		_destroy(root->left);
		free(root->data);
		_destroy(root->right);
		free(root);
	}
	return root;
}

bool BSTIsEmpty(BST * tree){
	if(tree->count == 0)
		return true;

	return false;
}

bool BSTIsFull(BST * tree){
	NODE * pNew = (NODE *)malloc(sizeof(NODE));
	if(pNew){
		free(pNew);
		return false;
	}
	return true;
}

int BSTCount(BST * tree){
	if(!tree)
		return -1;
	return tree->count;
}

