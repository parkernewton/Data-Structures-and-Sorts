/*
 * 
 * Name: 			stack.c
 *
 * Description: 	Implementation for a stack abstract data type that stores integer values.
 * 					A stack is a type of list in which its elements conform to the last-in, first-out (LIFO) order.
 * 
 * Author: 			Parker C. Newton 
 * 
 * Created: 		Oct 8, 2014
 * 
 * Project: 		abstractDataTypes
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"


typedef struct stack {
	int count;
	struct node * head;				//sentinel node
} STACK;

typedef struct node {
	int data;
	struct node * next;
} NODE;

STACK * createStack(void) {
	//We must allocate memory for the stack list
	STACK * stack = (STACK *)malloc(sizeof(STACK));
	assert(stack != NULL);
	stack->count = 0;

	//allocate memory for the sentinel node
	stack->head = (NODE *)malloc(sizeof(NODE));
	assert(stack->head != NULL);
	stack->head->next = NULL;

	return stack;
}

void destroyStack(STACK * stack) {
	assert(stack != NULL);
	//first, we need to de-allocate memory for each node in the list
	NODE * pCur = stack->head->next;				//pCur will maintain our current location in the list
	NODE * willy;  									//willy will point to the node we wish to de-allocate
	while(pCur != NULL){
		willy = pCur;
		pCur = pCur->next;
		free(willy);
	}

	//next, we will de-allocate memory for the sentinel node
	free(stack->head);

	//finally, we will de-allocate memory for the stack struct
	free(stack);

	return;
}

void push(STACK * stack, int element){
	assert(element != NULL && stack != NULL);

	//allocate memory for and set data for new node
	NODE * pNew = (NODE *)malloc(sizeof(NODE));
	assert(pNew != NULL);
	pNew->data = element;

	//push new node to stack (at beginning of list)
	pNew->next = stack->head->next;
	stack->head->next = pNew;
	stack->count++;

	return;
}

int pop(STACK * stack){
	assert(stack != NULL);

	//if there are no nodes in the stack, then we return NULL
	if(stack->count <= 0){
		return NULL;
	}

	//de-allocate first node in list
	NODE * pCur = stack->head->next;
	int element = pCur->data;			//element is a temp variable that holds data value to return
	stack->head->next = pCur->next;
	free(pCur);
	stack->count--;

	return element;
}

int getStackCount(STACK * stack){
	assert(stack != NULL);
	return stack->count;
}


