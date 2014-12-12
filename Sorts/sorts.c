//
//  sorts.c
//  Sorts
//
//  Created by parker on Dec 11, 2014.
//  Copyright (c) 2014 parker. All rights reserved.
//

//Implementation for Selection Sort, Insertion Sort, Heap Sort, and Quick Sort

#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"


void selectionSort(int a[], int n){
	if(!a || !n){
		printf("\nError: too few args to selectionSort(). \n");
		return;
	}
	int i, j, temp, min;
	for(i = 0; i < n-1; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(a[j] < a[min]){
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
} //Selection Sort
//Runtime: O(n^2)
//Space overhead: O(1)
//Not stable


void insertionSort(int a[], int n){
	if(!a || !n){
			printf("\nError: too few args to selectionSort(). \n");
			return;
	}
	int i, j, temp;
	for(i = 1; i < n; i++){
		temp = a[i];
		for(j = i - 1; j>=0 && temp < a[j]; j--){
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
} //Insertion Sort
//Runtime:
// Best: O(n)
// Average: O(n^2)
// Worst: O(n^2)
//Space overhead: O(1)
//Stable


//Internal  Heap Sort functions:

int p(int i){
	return ((i - 1) / 2);
} //returns index of parent

int lc(int i){
	return (2*i + 1);
} //returns index of left child

int rc(int i){
	return (2*i + 2);
} //returns index of right child

void insert(int heap[], int * count, int x){
	int i = (*count)++;
	while(i > 0 && heap[p(i)] < x){
		heap[i] = heap[p(i)];
		i = p(i);
	}
	heap[i] = x;
} //inserts elements into binary heap order such that each node's key is greater than or equal to that of its children

int delete(int heap[], int * count){
	int i, x, child, max;
	max = heap[0];
	x = heap[--(*count)];
	i = 0;
	while(lc(i) < *count){
		child = lc(i);
		if(rc(i) < *count && heap[lc(i)] < heap[rc(i)]){
			child = rc(i);
		}
		if(x < heap[child]){
			heap[i] = heap[child];
			i = child;
		}
		else {
			break;
		}
	}
	heap[i] = x;
	return max;
} //deletes, stores and, after restoring heap order, returns max heap value

//End Internal Heap Sort functions

void heapSort(int a[], int n){
	if(!a || !n){
			printf("\nError: too few args to selectionSort(). \n");
			return;
	}
	int i, count = 0;
	for(i = 0; i < n; i++){
		insert(a, &count, a[i]);
	}
	for(i = 0; i < n; i++){
		a[n - i - 1] = delete(a, &count);
	}
} //Heap Sort
//Runtime: O(nlog(n))
//Space overhead: O(1)
//Not stable


//Internal Quick Sort functions:

int partition(int a[], int lo, int hi){
	int i, temp;
	int sep = lo;
	int x = a[hi];
	for(i = lo; i < hi; i++){
		if(a[i] < x){
			temp = a[i];
			a[i] = a[sep];
			a[sep++] = temp;
		}
	}
	temp = a[hi];
	a[hi] = a[sep];
	a[sep] = temp;
	return sep;
} //partitions array into sub-arrays (marked by a separator) and makes comparisons with pivot value
//all values to the left of the partition will have lesser values and all to the right will have greater values

//End Internal Quick Sort Functions

void quickSort(int a[], int lo, int hi){
	int pLoc;
	if(lo < hi){
		pLoc = partition(a, lo, hi);
		quickSort(a, lo, pLoc-1);
		quickSort(a, pLoc+1, hi);
	}
} //Quick Sort
//Runtime:
// Best: O(nlog(n))
// Average: O(nlog(n)) -- we make (n-1) comparison for each partition, and we partition log(n) times on average
//Worst: O(n^2) -- if our data is already sorted in reverse order
//Space overhead: O(log(n))
//Not stable

