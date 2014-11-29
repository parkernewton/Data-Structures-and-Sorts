//
//  hashedList.h
//  HashedList
//
//  Created by parker on Nov 25, 2014.
//  Copyright (c) 2014 parker. All rights reserved.
//
#ifndef HASHEDLIST_H_
#define HASHEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listing {
	char name[31];
	char phone[16];
} LISTING;


void buildList(char * fileIn, LISTING phoneList[], int * last);

void hashSearch(LISTING * phoneList, int last);

int hashKey(char * key, int last);

int collision(int last, int location);


#endif /* HASHEDLIST_H_ */
