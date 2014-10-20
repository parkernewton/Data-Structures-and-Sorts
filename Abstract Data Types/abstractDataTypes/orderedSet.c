/*
 * 
 * Name: 			orderedSet.c
 *
 * Description: 	Implementation for an ordered set ADT that stores integer values.
 * 					An ordered set is an ordered collection of distinct elements.
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

	//if the set is empty, then we return -1
	if(set->count <= 0){
		return -1;
	}

	//we will implement binary search to locate the specified element
	int lo = 0, hi = set->count - 1, mid;
	while(lo <= hi){
		mid = (lo + hi) / 2;
		if(set->objects[mid] > element){
			hi = mid - 1;
		}
		else if(set->objects[mid] < element){
			lo = mid + 1;
		}
		else {
			return mid;
		}
	}

	//if we break from the while loop above, the specified element was not found in the set
	return -1;
}


bool addToSet(SET * set, int element){
	assert(set != NULL && element != NULL);

	if(set->count == set->size){
		return false;
	}

	//now we will implement binary search to find where to insert the new element
}


bool removeFromSet(SET * set, int element){
	assert(set != NULL && element != NULL);

	if(set->count <= 0){
		return false;
	}

	int location = searchSet(&set, element);
	if(location < 0){
		return false;
	}

	for(int i = location; i < (set->count - 1); i++){
		set->objects[i] = set->objects[i + 1];
	}
	set->count--;
	return true;
}


int getSetCount(SET * set){
	assert(set != NULL);
	return set->count;
}
