/*
 * BucketItem.c
 *
 *  Created on: 13.03.2017
 *      Author: Raffael Wojtas
 */

#include "BucketItem.h"
#include <inttypes.h>

BucketItem createBucketItem(uint8_t prefixLength) {
	BucketItem bucketItem;
	bucketItem.prefixLength = prefixLength;
	//bucketItem.suffixLength = suffixLength;
	//bucketItem.bucket = bucket;
	return bucketItem;
}
