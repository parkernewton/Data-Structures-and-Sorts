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


int main(void){
	LISTING phoneList[SIZE];
	int last = SIZE - 1;

	printf("\nPhone Listing: \n");

	buildList(phoneList, &last);
	hashSearch(phoneList, last);

	printf("\nEnd. \n");

	return 0;
}

