//
//  hashedList.c
//  HashedList
//
//  Created by parker on Nov 25, 2014.
//  Copyright (c) 2014 parker. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashedList.h"

void buildList(char * fileIn, LISTING phoneList[], int * last){
	if(!phoneList || !(last)){
		printf("\nError: too few arguments to buildList(). \n");
		return;
	}

	FILE * input = fopen(fileIn, "r");
	if(!input){
		printf("\nError: unable to open %s for reading. \n", fileIn);
		return;
	}

	//First, we set the keys to the null byte
	int i = 0;
	for(i = 0; i <= *last; i++){
		phoneList[i].name[0] = '\0';
	}

	LISTING aListing;
	int location;
	int counter;
	while(fscanf(input, " %30[^;]%*c %[^;]%*c", aListing.name, aListing.phone)==2){
		location = hashKey(aListing.name, *last);

		if(phoneList[location].name[0] != '\0'){
			//then we have a collision
			counter = 0;
			while((phoneList[location].name[0] != '\0') && counter++ <= *last){
				location = collision(*last, location);
			}
			if(phoneList[location].name[0] != '\0'){
				printf("Error: list is already full. \n");
				return;
			}
		}

		phoneList[location] = aListing;
	}
}

int hashKey(char * key, int last){
	if(!key || !last){
		printf("Error: too few args to hashKey(). \n");
		return -1;
	}

	int sum = 0;
	int keyLength = strlen(key);

	int i = 0;
	for(i = 0; i < keyLength; i++){
		if(key[i] != ' '){
			sum += key[i];
		}
	}

	return ((sum % last) + 1);
}

int collision(int last, int location){
	if(!last || !location){
		printf("\nError: too few args to collision(). \n");
		return -1;
	}

	if(location < last){
		return ++location;
	}
	return 0;
}

void hashSearch(LISTING * phoneList, int last){
	if(!phoneList || !last){
		printf("\nError: too few args to hashSearch(). \n");
		return;
	}

	char searchName[31];
	int location;
	int counter;
	char searchAgain;

	do {
		printf("\nEnter name: \n");
		scanf(" %[^\n]", searchName);

		location = hashKey(searchName, last);
		if(strcmp(searchName, phoneList[location].name) != 0){
			//We will first check if this is due to a collision
			counter = 0;
			while((strcmp(searchName, phoneList[location].name) != 0) && (counter++ <= last)){
				location = collision(last, location);
			}
		}

		if(strcmp(searchName, phoneList[location].name) == 0){
			//We have found our match
			printf("\n%s \t%d \t%s", phoneList[location].name, location, phoneList[location].phone);
		}
		else{
			printf("\n%s not found. \n", searchName);
		}

		printf("\n(Y) to search for another name, (N) to quit. \n");
		scanf(" %c", &searchAgain);
	} while(searchAgain=='Y' || searchAgain=='y');
}

