/*
 * 
 * Name: 			set.h
 *
 * Description: 	Interface for a set ADT that stores integer values.
 * 					A set is an unordered collection of distinct elements.
 * 
 * Author: 			Parker C. Newton 
 * 
 * Created: 		Oct 9, 2014
 * 
 * Project: 		abstractDataTypes
 * 
 */

#ifndef SET_H_
#define SET_H_

SET * createSet(int numberOfElements);
//allocates and initializes a new set ADT

void destroySet(SET * set);
//de-allocates the set ADT passed as a parameter

int searchSet(SET * set, int element);
//traverses the set passed as a parameter and searches for the specific element
//returns the location of the element of interest in the set if found, else returns -1

bool addToSet(SET * set, int element);
//inserts the specified element into the set passed as a parameter
//returns true on success, false on error

bool removeFromSet(SET * set, int element);
//removes the specified element from the set passed as a parameter
//returns true on success, false on error

int getSetCount(SET * set);
//returns the number of elements in the set passed as a parameter

#endif /* SET_H_ */
