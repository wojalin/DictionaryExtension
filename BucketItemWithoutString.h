/*
 * BucketItem.h
 *
 *  Created on: 24.02.2017
 *      Author: Raffael Wojtas
 */

#ifndef SRC_BUCKETITEMWITHOUTSTRING_H_
#define SRC_BUCKETITEMWITHOUTSTRING_H_

typedef struct {
	int commonPrefixLength;
	int suffixLength
	BucketItemWithoutString *parentItem;
	int size;
} BucketItemWithoutString;

#endif /* SRC_BUCKETITEMWITHOUTSTRING_H_ */
