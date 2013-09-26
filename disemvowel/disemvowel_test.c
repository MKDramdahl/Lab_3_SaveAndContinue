#include <stdarg.h>
#include <setjmp.h>
#include <stdlib.h>

#include "../include/cmockery.h"
#include "disemvowel.h"

void test_empty_str(void) {
  char* result = disemvowel("");
  assert_string_equal("", result);
  free(result);
}

void test_no_vowels(void) {
  char* result = disemvowel("pqrst");
  assert_string_equal("pqrst", result);
  free(result);
}

void test_only_vowels(void) {
  char* result = disemvowel("aeiouAEIOUOIEAuoiea");
  assert_string_equal("", result);
  free(result);
}

void test_my_name(void) {
  char* result = disemvowel("Nicholas Freitag McPhee");
  assert_string_equal("Nchls Frtg McPh", result);
  free(result);
}

void test_punctuation(void) {
  char* result = disemvowel("An (Unexplained) Elephant!");
  assert_string_equal("n (nxplnd) lphnt!", result);
  free(result);
}

void test_long_string(void) {
  char* str;
  int size;
  int i;

  size = 50000;
  str = calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char* result = disemvowel(str);
  assert_string_equal("xyz", result);

  free(result);
  free(str);
}

int main(int argc, char* argv[]) {
  UnitTest tests[] = {
    unit_test(test_empty_str),
    unit_test(test_no_vowels),
    unit_test(test_only_vowels),
    unit_test(test_my_name),
    unit_test(test_punctuation),
    unit_test(test_long_string)
  };
  return run_tests(tests);
}
