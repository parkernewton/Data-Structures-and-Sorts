/*
 * 
 * Name: 			queue.c
 *
 * Description: 	Implementation for a queue ADT that stores integer values.
 * 					A queue is a type of list in which its elements conform to the first-in, first-out (FIFO) order.
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
#include "queue.h"


typedef struct queue {
	int count;
	struct node * head; 			//sentinel node
} QUEUE;

typedef struct node {
	int data;
	struct node * next, * prev; 			//we will implement a circular doubly-linked list
} NODE;


QUEUE * createQueue(void){
	//first, we will allocate memory for the queue ADT
	QUEUE * queue = (QUEUE *)malloc(sizeof(QUEUE));
	assert(queue != NULL);
	queue->count = 0;

	//next, we will allocate memory for and initialize the sentinel node
	queue->head = (NODE *)malloc(sizeof(NODE));
	assert(queue->head != NULL);
	queue->head->next = queue->head;
	queue->head->prev = queue->head;

	return queue;
}

void destroyQueue(QUEUE * queue){
	assert(queue != NULL);

	//first, we will de-allocate each node in the list
	NODE * pCur = queue->head->next; 			//pCur will maintain our current location in the list
	while(pCur != queue->head){
		pCur = pCur->next;
		free(pCur->prev);
	}

	//next, we will de-allocate the sentinel node
	free(queue->head);

	//finally, we will de-allocate the queue ADT
	free(queue);

	return;
}


void enqueue(QUEUE * queue, int element){
	assert(queue != NULL && element != NULL);

	//first we will allocate and initialize a new node
	NODE * pNew = (NODE *)malloc(sizeof(NODE));
	assert(pNew != NULL);
	pNew->data = element;

	//next we will insert the new node into the back of the queue
	pNew->prev = queue->head->prev;
	pNew->next = queue->head;
	queue->head->prev->next = pNew;
	queue->head->prev = pNew;
	queue->count++;

	return;
}


int dequeue(QUEUE * queue){
	assert(queue != NULL);

	//if there are no nodes in the list, then we return NULL
	if(queue->count <= 0){
		return NULL;
	}

	//de-allocate the first node in the list
	NODE * pCur = queue->head->next; 			//pCur stores a reference to the first node in the list
	int element = pCur->data; 			//element is a temp variable that stores the data value of pCur to return
	pCur->next->prev = pCur->prev;
	pCur->prev->next = pCur->next;
	free(pCur);
	queue->count--;

	return element;
}


int getQueueCount(QUEUE * queue){
	assert(queue != NULL);
	return queue->count;
}


