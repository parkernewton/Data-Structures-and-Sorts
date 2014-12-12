//
//  main.c
//  Sorts
//
//  Created by parker on Dec 11, 2014.
//  Copyright (c) 2014 parker. All rights reserved.
//

//Program to test various sorting algorithms

#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

#define SIZE 100

int main(void){
	char input;
	int data;

	while(1){
		printf("\nThis program sorts integers based on various sorting algorithms. \nPress any key to proceed or (q) to quit. \n");
		scanf(" %c[^\n]", &input);
		if(input=='q' || input=='Q')
			return 0;

		int size;
		printf("\nEnter the no. of integers which you wish to sort. \n");
		scanf(" %d[^\n]", &size);
		if(size > SIZE){
			printf("\nError: value exceeds %d \n", SIZE);
			continue;
		}

		int i, a[SIZE];
		for(i = 0; i < size; i++){
			printf("\nEnter integer no. %d :\n", i+1);
			if(scanf(" %d[^\n]", &data) == 1)
				a[i] = data;
		}

		printf("\nSelect your sort of choice from the list below: \n(0) - Selection Sort \n(1) - Insertion Sort \n(2) - Heap Sort \n(3) - Quick Sort \n");
		scanf(" %d[^\n]", &data);
		switch(data){
		case 0:
			selectionSort(a, size);
			break;
		case 1:
			insertionSort(a, size);
			break;
		case 2:
			heapSort(a, size);
			break;
		case 3:
			quickSort(a, 0, (size - 1));
			break;
		default:
			return 0;
		}

		printf("\nSorted Integers: \n");
		for(i = 0; i < size; i++)
			printf("%d\t", a[i]);
	}

	return 0;
}
