/*
 * 
 * Name: 			deque.c
 *
 * Description: 	
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
#include "deque.h"


typedef struct deque {
	int count;
	struct node * head; 			//sentinel node
} DEQUE;

typedef struct node {
	int data;
	struct node * next, * prev;
} NODE;


DEQUE * createDeque(void){
	//allocate memory for and initialize the deque ADT
	DEQUE * deque = (DEQUE *)malloc(sizeof(DEQUE));
	assert(deque != NULL);
	deque->count = 0;

	//allocate memory for and initialize the sentinel node
	deque->head = (NODE *)malloc(sizeof(NODE));
	assert(deque->head != NULL);
	deque->head->next = deque->head;
	deque->head->prev = deque->head;

	return deque;
}


void destoryDeque(DEQUE * deque){
	assert(deque != NULL);

	//first, we must de-allocate each node in the list
	NODE * pCur = deque->head->next;
	while(pCur != NULL){
		pCur = pCur->next;
		free(pCur->prev);
	}

	//next, we will de-allocate the sentinel node
	free(deque->head);

	//finally, we will de-allocate the deque ADT
	free(deque);

	return;
}


void enqueueFirst(DEQUE * deque, int element){
	assert(deque != NULL && element != NULL);

	//first, we will allocate and initialize a new node
	NODE * pNew = (NODE *)malloc(sizeof(NODE));
	assert(pNew != NULL);
	pNew->data = element;

	//next, we will insert the new node at the beginning of the list
	pNew->next = deque->head->next;
	pNew->prev = deque->head;
	deque->head->next->prev = pNew;
	deque->head->next = pNew;

	deque->count++;

	return;
}


void enqueueLast(DEQUE * deque, int element){
	assert(deque != NULL && element != NULL);

	//first, we will allocate and initialize a new node
	NODE * pNew = (NODE *)malloc(sizeof(NODE));
	assert(pNew != NULL);
	pNew->data = element;

	//next, we will insert the new node at the end of the list
	pNew->next = deque->head;
	pNew->prev = deque->head->prev;
	deque->head->prev->next = pNew;
	deque->head->prev = pNew;

	deque->count++;

	return;
}


int dequeueFirst(DEQUE * deque){
	assert(deque != NULL);

	//if the deque is empty, we return NULL
	if(deque->count <= 0){
		return NULL;
	}

	//We will de-allocate the first node in the list
	NODE * pCur = deque->head->next;
	int element = pCur->data; 			//element is a temp var that will store the data value to return
	pCur->next->prev = pCur->prev;
	pCur->prev->next = pCur->next;
	free(pCur);

	deque->count--;

	return element;
}


int dequeueLast(DEQUE * deque){
	assert(deque != NULL);

	//if the deque is empty, we will return NULL
	if(deque->count <= 0){
		return NULL;
	}

	//we will de-allocate the last node in the list
	NODE * pCur = deque->head->prev;
	int element = pCur->data; 			//element is a temp var that will store the data value to return
	pCur->next->prev = pCur->prev;
	pCur->prev->next = pCur->next;
	free(pCur);

	deque->count--;

	return element;
}


int getDequeCount(DEQUE * deque){
	assert(deque != NULL);
	return deque->count;
}


