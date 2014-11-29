//
//  main.c
//  HashedList
//
//  Created by parker on Nov 25, 2014.
//  Copyright (c) 2014 parker. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashedList.h"


const int size = 50;


int main(int argc, char * argv[]){
	if(argc < 2){
		printf("\nError: expected input text file. \n");
		return -1;
	}

	char * fileIn = argv[1];
	LISTING phoneList[size];
	int last = size - 1;

	printf("\nPhone Listing: \n");

	buildList(fileIn, phoneList, &last);
	hashSearch(phoneList, last);

	printf("\nEnd. \n");

	return 0;
}

