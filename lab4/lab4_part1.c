#include <stdio.h>

int main(void) {
  int i;
  int sum = 0;

  for (i = 1; i < 11; ++i) {
    if (i % 2 == 0) {
      sum += i;
    }
  }

  printf("The sum of all even integers between 1 and 10 is: %d", sum);

  return 0;
}