/*
 * 
 * Name: 			queue.h
 *
 * Description: 	Interface for a queue ADT that stores integer values.
 * 					A queue is a type of list in which its elements conform to the first-in, first-out (FIFO) order.
 * 
 * Author: 			Parker C. Newton 
 * 
 * Created: 		Oct 8, 2014
 * 
 * Project: 		abstractDataTypes
 * 
 */

#ifndef QUEUE_H_
#define QUEUE_H_

QUEUE * createQueue(void);
//allocates and initializes a new queue ADT

void destroyQueue(QUEUE * queue);
//de-allocates the queue passed as a parameter

void enqueue(QUEUE * queue, int element);
//inserts a new element to the end of the queue passed as parameters

int dequeue(QUEUE * queue);
//dequeues and de-allocates the element at the beginning of the queue passed as a parameter

int getQueueCount(QUEUE * queue);
//returns the number of elements in the current queue passed as a parameter

#endif /* QUEUE_H_ */
