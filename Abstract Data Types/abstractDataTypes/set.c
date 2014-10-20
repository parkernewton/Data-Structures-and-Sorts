/*
 * 
 * Name: 			set.c
 *
 * Description: 	Implementation for a set ADT that stores integer values.
 * 					A set is an unordered collection of distinct elements.
 * 
 * Author: 			Parker C. Newton 
 * 
 * Created: 		Oct 9, 2014
 * 
 * Project: 		abstractDataTypes
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "set.h"


#define intSize 32


typedef struct set {
	int count;
	int size;
	int objects[]; 			//array that contains all elements in set
} SET;


SET * createSet(int numberOfElements){
	assert(numberOfElements != NULL);

	//first, we will allocate memory for and initialize a new empty set
	SET * set = (SET *)malloc(sizeof(SET));
	assert(set != NULL);
	set->count = 0;
	set->size = numberOfElements;

	//next, we will allocate and initialize the objects array to store data in the set
	set->objects = malloc(intSize * numberOfElements);
	assert(set->objects != NULL);

	return set;
}


void destroySet(SET * set){
	assert(set != NULL);

	//first, we will de-allocate the objects array that stores the data in the set
	free(set->objects);

	//next, we will de-allocate the set pointer
	free(set);

	return;
}


int searchSet(SET * set, int element){
	assert(set != NULL && element != NULL);

	//if the set is empty, we cannot search for an element
	if(set->count <= 0){
		return -1;
	}

	int * pCur = set->objects; 			//pCur points to the current object in the set
	int index = 0; 			//if we find the element in the set, we will want to return its index in the array
	while(*pCur != NULL){
		if(*pCur == element){
			break;
		}
		index++;
		pCur++;
	}

	//if we didn't find the element in the set, return -1
	if(pCur == NULL){
		return -1;
	}

	return index;
}


bool addToSet(SET * set, int element){
	assert(set != NULL && element != NULL);

	//if the set is full, then we cannot insert an additional element
	if(set->count == set->size){
		return false;
	}

	//if the element already exists in the set, then we will not insert it again
	if(searchSet(&set, element) >= 0){
		return true; 			//we will return true because the element already exists in the set
	}

	//else, we will append the element to the end of the array of objects
	set->objects[set->count++] = element;
	return true;
}


bool removeFromSet(SET * set, int element){
	assert(set != NULL && element != NULL);

	//if the set if empty, then we cannot remove an element
	if(set->count <= 0){
		return false;
	}

	//if the element is not in the set, then we cannot remove it
	int location = searchSet(&set, element);
	if(location < 0){
		return false;
	}

	//to remove this element, we simply replace it with the last item in the array
	set->objects[location] = set->objects[--set->count];
	return true;
}


int getSetCount(SET * set){
	assert(set != NULL);
	return set->count;
}


