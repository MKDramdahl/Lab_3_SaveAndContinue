#include <stdlib.h>
#include <string.h>

#include "disemvowel.h"

char* disemvowel(char* str) {
  int len = strlen(str);
  char* result = calloc(len+1, sizeof(char));
  int counter = 0;
  
  int i;
  for(i = 0; i < len; i++) {
    if( (str[i] != 'a') && (str[i] != 'e') && (str[i] != 'i') && (str[i] != 'o') && (str[i] != 'u') && (str[i] != 'A') && (str[i] != 'E') && (str[i] != 'I') && (str[i] != 'O') && (str[i] != 'U') ) {
      result[counter] = str[i];
      counter++;
    }  
  }
  return result;
}
