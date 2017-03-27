/*
 * Bucket.c
 *
 *  Created on: 24.02.2017
 *      Author: Raffael Wojtas
 */

#include "Bucket.h"

void initBucket(Bucket *bucket) {
	bucket->currentSize = 0;
	bucket->currentElements = 0;
	bucket->maxSize = 255;
	bucket->startAddress = malloc(sizeof(int) * bucket->maxSize);
	printf("initBucket: bucket->startAddress: %i\n", bucket->startAddress);
	*((*bucket).startAddress) = (*bucket).startAddress;
	bucket->offset = 0;
}

Bucket createBucket()  {
	Bucket b;
	initBucket(&b);
	return b;
}

int * addBucketItem(Bucket *bucket, char suffix[], int commonLength, int suffixLength, int parentItem) {
	printf("-------------\n");
	printf("size of bucket: %i\n", bucket->currentSize);
	printf("address of bucket: %i\n", bucket);
	if(suffixLength > 0) {
		int offset = bucket->offset;
		printf("offset: %i\n", offset);
		*(bucket->startAddress+offset+0) = calculateOffset(bucket->currentElements, suffixLength);
		*(bucket->startAddress+offset+1) = commonLength;
		*(bucket->startAddress+offset+2) = suffixLength;
		*(bucket->startAddress+offset+3) = bucket->startAddress;


		printf("(bucket->startAddress+offset): %i\n", (bucket->startAddress+offset));
		printf("*(bucket->startAddress+offset): %i\n", *(bucket->startAddress+offset));
		printf("(bucket->startAddress+offset+3): %i\n", (bucket->startAddress+offset+3));
		printf("*(bucket->startAddress+offset+3): %i\n", *(bucket->startAddress+offset+3));
		char *characterSuffixPointer;
		characterSuffixPointer = bucket->startAddress+offset+4;

		printf("cPtr: %i\n", characterSuffixPointer);
		printf("cPtr+1: %i\n", characterSuffixPointer+1);
		printf("cPtr+4: %i\n", characterSuffixPointer+4);
		for(int i = 0; i <suffixLength; i++) {
			*(characterSuffixPointer+i) = suffix[i + commonLength];
		}
		*(characterSuffixPointer+suffixLength) = '\0';

		bucket->offset = offset + calculateOffset(bucket->currentElements, suffixLength);
		printf("bucket->offset: %i\n", bucket->offset);
		bucket->currentElements++;
		printf("2startAddress: %i\n", *bucket->startAddress);

		return bucket->startAddress+offset;
	} else {
		// error
		return NULL;
	}
}

void readWholeBucket(Bucket *bucket) {
	printf("\n\n-----ReadWholeBucket------\n");
	int *ptr;
	char *cPtr;
	ptr = bucket->startAddress;
	printf("bucket->startAddress: %i\n", bucket->startAddress);
	int offset = 0;

	for(int i = 0; i < bucket->currentElements; i++) {
		printf("Start of \"For\"-Loop: offset: %i\n", offset);

		printf("offset: %i\n", offset);
		printf("%i\n", *(ptr+0+offset));
		printf("%i\n", *(ptr+1+offset));
		printf("%i\n", *(ptr+2+offset));
		printf("%i\n", *(ptr+3+offset));

		cPtr = ptr+4+offset;
		for(int i = 0;  i< *(ptr+2+offset); i++) {
			printf("%c", *(cPtr+i));
		}
		printf("\n");

		offset = offset +  *(ptr+offset);
		printf("-------\n");

	}
}

int calculateOffset(int amountOfElements, int suffixLength) {
	int offsetSuffixModulo, offset;
	offsetSuffixModulo = suffixLength % 4;

	if(offsetSuffixModulo != 0)
		offset = suffixLength / 4;
	else
		offset = ( suffixLength / 4) + 1;
	return ((amountOfElements+1) * 4) + offset;

}

char * readFirstItemFromBucket(int *startAddress) {
	int commonLength, suffixLength, parentItem, offset;
	int *iPtr;
	char *cPtr;

	iPtr = startAddress;
	offset = *iPtr;
	commonLength = *(iPtr+1);
	suffixLength = *(iPtr + 2);
	parentItem = *(iPtr + 3);
	printf("commonLength: %i\n", commonLength);
	printf("suffixLength: %i\n", suffixLength);
	printf("parentItem: %i\n", parentItem);
	cPtr = iPtr + 4;
	for(int i = 0; i < suffixLength; i++) {
		printf("%c", *(cPtr+i));
	}
	printf("\n");

	return cPtr;
}
