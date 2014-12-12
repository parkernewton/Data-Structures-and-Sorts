//
//  sorts.h
//  Sorts
//
//  Created by parker on Dec 11, 2014.
//  Copyright (c) 2014 parker. All rights reserved.
//

//Interface for Selection Sort, Insertion Sort, Quick Sort, and Heap Sort

#ifndef SORTS_H_
#define SORTS_H_

void selectionSort(int a[], int n);
//a[] is a pointer to an array of integers
//n is the size of the array

void insertionSort(int a[], int n);
//a[] is a pointer to an array of integers
//n is the size of the array

void heapSort(int a[], int n);
//a[] is a pointer to an array of integers
//n is the size of the array

void quickSort(int a[], int lo, int hi);
//a is a pointer to an array of integers
//lo is the index of the first array element
//hi is the index of the last array element

#endif /* SORTS_H_ */
