#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "mergesort.h"

bool needsSorting(int rangeSize) {
  return rangeSize >= 2;
}

void mergeRanges(int* values, int startIndex, int midPoint, int endIndex) {
  int rangeSize = endIndex - startIndex;
  int* destination = calloc(rangeSize + 1, sizeof(int));
  destination[rangeSize] = '\0';
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;
  while(firstIndex < midPoint && secondIndex < endIndex) {
    if(values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      firstIndex++;
    } else {
      destination[copyIndex] = values[secondIndex];
      secondIndex++;
    }
  }
  while(firstIndex < midPoint) {
    destination[copyIndex] = values[firstIndex];
    copyIndex++;
    firstIndex++;
  }
  while(secondIndex < endIndex) {
    destination[copyIndex] = values[secondIndex];
    copyIndex++;
    secondIndex++;
  }
  int i;
  for(i = 0; i < rangeSize; i++) {
    values[i + startIndex] = destination[i];
  }
  free(destination);
}

void mergesortRange(int* values, int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if(needsSorting(rangeSize)) {
    int midPoint = (startIndex + endIndex)/2;
    mergesortRange(values, startIndex, midPoint);
    mergesortRange(values, midPoint, endIndex);
    mergeRanges(values, startIndex, midPoint, endIndex);
    int i;
    //for (i=0; i<rangeSize; ++i) {
      //printf("values[%d] = %d.\n", i);
    //}
  }
}

void mergesort(int size, int* values) {
  //int* temp = calloc(size, sizeof(int));
  //for (i=0; i<size; ++i) {
  //  temp[i] = values[i];
  //  printf("temp[%d] = %d.\n", temp[i]);
  //}
  mergesortRange(values, 0, size);
}
