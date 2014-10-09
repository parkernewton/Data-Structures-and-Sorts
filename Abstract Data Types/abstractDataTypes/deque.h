/*
 * 
 * Name: 			deque.h
 *
 * Description: 	Interface for a doubly-ended queue (deque) that stores integer values.
 * 					A deque is a type of queue in which we can enqueue and dequeue elements from either the beginning or the end of the list.
 * 
 * Author: 			Parker C. Newton 
 * 
 * Created: 		Oct 8, 2014
 * 
 * Project: 		abstractDataTypes
 * 
 */

#ifndef DEQUE_H_
#define DEQUE_H_

DEQUE * createDeque(void);
//allocates and initializes a new deque ADT
//returns the newly-initialized DEQUE pointer

void destoryDeque(DEQUE * deque);
//de-allocates the deque passed as a parameter

void enqueueFirst(DEQUE * deque, int element);
//enqueue the supplied element to the beginning of the deque

void enqueueLast(DEQUE * deque, int element);
//enqueue the supplied element to the end of the deque

int dequeueFirst(DEQUE * deque);
//dequeue the first element from the deque passed as a parameter
//returns the data value from the dequeued element

int dequeueLast(DEQUE * deque);
//dequeues the last element from the deque passed as a parameter
//returns the data value from the dequeued element

int getDequeCount(DEQUE * deque);
//returns the number of elements in the deque passed as a parameter

#endif /* DEQUE_H_ */
