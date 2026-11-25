#include <stdio.h>

int main(void) {
  int i;
  int j;

  printf("   |   1   2   3   4   5   6   7   8   9  10\n");
  printf("---+----------------------------------------\n");

  for (i = 1; i < 11; ++i) {
    printf("%3d|", i);

    for (j = 1; j < 11; j++) {
      printf("%4d", j);
    }

    printf("\n");
  }

  return 0;
}