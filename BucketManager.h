/*
 * BucketManager.h
 *
 *  Created on: 24.02.2017
 *      Author: Raffael Wojtas
 */

#ifndef SRC_BUCKETMANAGER_H_
#define SRC_BUCKETMANAGER_H_

#include <stdlib.h>
#include <stdio.h>
#include "Bucket.h"
#include "BucketItem.h"
#include <inttypes.h>

const int THRESHOLD_FOR_INSERTION_INTO_BUCKET;

//extend for saving pointers to buckets
typedef struct {
	uint8_t maxBuckets;
	uint8_t currentBuckets;
	uint8_t maxBucketSize;
	uint8_t THRESHOLD_FOR_SUFFIX_TO_INSERT_INTO_BUCKET;
	Bucket *pointerToBucketStartingPoints;
} BucketManager;



void initBucketManager(BucketManager *buckerManager);

void addBucketToBucketManager(BucketManager *bucketManager, Bucket bucket);

BucketItem * selectBestFittingBucket(BucketManager *bucketManager, char stringForInsertion[]);

/*!
 * @brief
 * @return 1 if the threshold is reached, else return 0
 */
uint8_t isThresholdReached(uint8_t i);

/*!
 * @brief
 * @return the position they differ
 */
uint8_t stringCompare(char str1[], char str2[]);

uint8_t MAX(uint8_t i, uint8_t j);

int * storeString(BucketManager *bucketManager, char string[]);

#endif /* SRC_BUCKETMANAGER_H_ */
