/*
 * BucketManager.c
 *
 *  Created on: 24.02.2017
 *      Author: Raffael Wojtas
 */

#include "BucketManager.h"

const int THRESHOLD_FOR_INSERTION_INTO_BUCKET = 3;

void initBucketManager(BucketManager *bucketManager) {
	bucketManager->currentBuckets = 0;
	bucketManager->maxBuckets = 4;
	bucketManager->maxBucketSize = 100;
	bucketManager->pointerToBucketStartingPoints = (Bucket *)malloc(sizeof(Bucket) * 4);
}

void addBucketToBucketManager(BucketManager *bucketManager, Bucket bucket) {
	if(bucketManager->currentBuckets < bucketManager->maxBuckets) {
		*(bucketManager->pointerToBucketStartingPoints + bucketManager->currentBuckets) = bucket;
		Bucket b = *(bucketManager->pointerToBucketStartingPoints+bucketManager->currentBuckets);
		printf("maxSize of bucket: %i\n", b.maxSize);
		printf("____\n");
		bucketManager->currentBuckets++;
	}else {
		// error
		printf("Error...\n");
	}
}

BucketItem * selectBestFittingBucket(BucketManager *bucketManager, char stringForInsertion[]) {
	uint8_t bestBucket = 0, bestBucketValue = 0;
	for(int i = 0; i < bucketManager->currentBuckets; i++) {
		printf("------------------------\ninside selectBestFittingBucket\n");
		printf("Starting address: %i\n", (*(bucketManager->pointerToBucketStartingPoints + i)).startAddress);
		char *cPtr;
		cPtr = readFirstItemFromBucket((*(bucketManager->pointerToBucketStartingPoints + i)).startAddress);

		uint8_t stringCompareResult = stringCompare(cPtr, stringForInsertion);
		printf("result StringCompare: %i\n", stringCompareResult);

		bestBucketValue = MAX(bestBucketValue, stringCompareResult);
		bestBucket = stringCompareResult >= bestBucketValue ? i : bestBucket;
	}
	printf("bestBucket: %i\n", bestBucket);
	printf("bestBucketValue: %i\n", bestBucketValue);
	printf("address of bestBucket: %i\n", *(bucketManager->pointerToBucketStartingPoints+bestBucket));

	/*check if this result, is better than our threshold
	 *if result better(>) or good enough(=) threshold, then insert into that bucket
	 *if result worse(<) threshold, then
	 *check if we have reached maximum bucket bucketManager->currentBuckets
	 *if reached: add to the last bucket (or best fitting bucket)
	 *if not reached: create a new bucket and return its address
	*/
	if(isThresholdReached(bestBucketValue)) {
		BucketItem bucketItem;
		bucketItem.prefixLength = bestBucketValue;
		bucketItem.suffixLength = strlen(stringForInsertion) - bestBucketValue;
		bucketItem.bucket = bucketManager->pointerToBucketStartingPoints+bestBucket;
		return &bucketItem;
	}
	else {
		if(bucketManager->currentBuckets == bucketManager->maxBuckets) {
			BucketItem bucketItem;
			bucketItem.prefixLength = 0;
			bucketItem.suffixLength = strlen(stringForInsertion);
			bucketItem.bucket = bucketManager->pointerToBucketStartingPoints+ (bucketManager->currentBuckets - 1);
			return &bucketItem;
		}
		else {
			Bucket b = createBucket();
			addBucketToBucketManager(bucketManager, b);
			BucketItem bucketItem;
			bucketItem.prefixLength = 0;
			bucketItem.suffixLength = strlen(stringForInsertion);
			bucketItem.bucket = bucketManager->pointerToBucketStartingPoints+(bucketManager->currentBuckets - 1);
			return &bucketItem;
		}
	}
}

uint8_t isThresholdReached(uint8_t i) {
	if(i < THRESHOLD_FOR_INSERTION_INTO_BUCKET)
		return 0;
	else
		return 1;
}

uint8_t stringCompare(char str1[], char str2[]) {
	int ctr=0;
	while(str1[ctr]==str2[ctr])
	{
		if(str1[ctr]=='\0'||str2[ctr]=='\0')
			break;
		printf("%c", str1[ctr]);
		ctr++;
	}
	printf("\n");
	return ctr;
}

uint8_t MAX(uint8_t i, uint8_t j) {
	if (i >= j)
		return i;
	else
		return j;
}

int * storeString(BucketManager *bucketManager, char string[]){
	BucketItem *bucketItem;
	bucketItem = selectBestFittingBucket(bucketManager, string);
	return addBucketItem(bucketItem->bucket, string, bucketItem->prefixLength, bucketItem->suffixLength, (bucketManager->pointerToBucketStartingPoints+ bucketManager->currentBuckets)->startAddress);
}



