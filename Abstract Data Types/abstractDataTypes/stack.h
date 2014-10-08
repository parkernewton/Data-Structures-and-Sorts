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

typedef struct stack STACK;

STACK createStack(void);
void destroyStack(void);
void push(int element);
int pop(void);

#endif /* STACK_H_ */
