/*
 * Bucket.h
 *
 *  Created on: 24.02.2017
 *      Author: Raffael Wojtas
 */

#ifndef SRC_BUCKET_H_
#define SRC_BUCKET_H_

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

typedef struct {
	uint8_t currentElements;
	uint8_t currentSize;
	uint8_t maxSize;
	int *startAddress;
	uint8_t offset;

} Bucket;

Bucket createBucket();

void initBucket(Bucket *bucket);

int * addBucketItem(Bucket *bucket, char suffix[], int commonLength, int suffixLength, int parentItem);

void readWholeBucket(Bucket *bucket);

char * readFirstItemFromBucket(int *nextFreeAddress);

int calculateOffset(int amountOfElements, int suffixLength);

#endif /* SRC_BUCKET_H_ */
