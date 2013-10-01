#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "array_merge.h"
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  int resultSize;
  int i;
  for(i=0; i<num_arrays; i++){
    resultSize += sizes[i] ;
  }
  int* result = calloc(resultSize + 1, sizeof(int));
  int counter = 0;
  int j;  
  for (j = 0; j < num_arrays; j++) {
    int k = 0;
    for (k = 0; k < sizes[j]; k++) {
      bool match = false;
      int q;
      for(q = 0; q < counter; q++) {
	if(result[q] == values[j][k]){
	    match = true;
	}
      }
      if(match == false) {
	result[counter] = values[j][k];
	counter++;
      }
    }
  }
  mergesort(counter, result);
  int* resultTwo = calloc(counter + 2, sizeof(int)) ;
  resultTwo[0] = counter;
  for(i = 0; i<counter + 1; i++){
    resultTwo[i + 1] = result[i];
  }
  resultTwo[counter + 2] = '\0';
  free(result);
  return resultTwo;
}
