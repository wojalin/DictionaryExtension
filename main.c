#include <stdio.h>
#include <stdlib.h>
#include "BucketManager.h"



int main() {
	BucketManager bucketManager;
	initBucketManager(&bucketManager);


	int *myArray[5];

	myArray[0] = storeString(&bucketManager, "test");
	myArray[1] = storeString(&bucketManager, "tester");
	myArray[2] = storeString(&bucketManager, "testerYeah");
	myArray[3] = storeString(&bucketManager, "newBucket");
	myArray[4] = storeString(&bucketManager, "newSize");

	//for(int i = 0; i < bucketManager.currentBuckets; i++) {
		readWholeBucket(bucketManager.pointerToBucketStartingPoints);
	//}

	int *childItemPointer = myArray[0];
	int **parentItemPointer;
	parentItemPointer = (childItemPointer+3);
	printf("value of a: %i\n", childItemPointer);
	printf("value of *a: %i\n", *childItemPointer);
	printf("value at (a+3): %i\n", (childItemPointer+3));
	printf("value at *(a+3): %i\n", *(childItemPointer+3));
	printf("value of b: %i\n", parentItemPointer);
	printf("value of *b: %i\n", *parentItemPointer);
	printf("value of **b: %i\n", **parentItemPointer);



	char *bcPointer;
	bcPointer = parentItemPointer+4;
	printf("bcPointer: %i\n", bcPointer);
	printf("bcPointer CharValue: %c\n", *bcPointer);
	int j = 0;
	while(*(bcPointer+j) != '\0') {
		printf("%c", *(bcPointer+j));
		j++;
	}
	printf("\n");

	char *cPtr = childItemPointer+4;
	int i = 0;
	while(*(cPtr+i) != '\0') {
		printf("%c", *(cPtr+i));
		i++;
	}

	return 0;
}



