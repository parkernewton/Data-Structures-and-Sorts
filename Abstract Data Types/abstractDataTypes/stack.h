/*
 * 
 * Name: 			stack.h
 *
 * Description: 	Interface for a stack abstract data type that stores integer values.
 * 					A stack is a type of list in which its elements conform to the last-in, first-out (LIFO) order.
 * 
 * Author: 			Parker C. Newton 
 * 
 * Created: 		Oct 7, 2014
 * 
 * Project: 		abstractDataTypes
 * 
 */

#ifndef STACK_H_
#define STACK_H_

STACK * createStack(void);
//allocates and initializes a new stack ADT

void destroyStack(STACK * stack);
//de-allocates the stack ADT passed as a parameter

void push(STACK * stack, int elemen);
//pushes a new element to the stack passed as parameter

int pop(STACK * stack);
//pops the last element from the stack passed as a parameter

int getStackCount(STACK * stack);
//returns the number of elements in the stack passed as a parameter

#endif /* STACK_H_ */
