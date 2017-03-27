/*
 * BucketItem.h
 *
 *  Created on: 13.03.2017
 *      Author: Raffael Wojtas
 */

#ifndef SRC_BUCKETITEM_H_
#define SRC_BUCKETITEM_H_

#include "Bucket.h"

typedef struct {
	uint8_t suffixLength;
	uint8_t prefixLength;
	Bucket *bucket;
}BucketItem;

#endif /* SRC_BUCKETITEM_H_ */
