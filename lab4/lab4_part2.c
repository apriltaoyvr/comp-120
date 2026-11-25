#include <stdio.h>

int main(void) {
  int input;

  printf("Enter a whole number: ");
  scanf("%d", &input);

  while (input > 0) {
    printf("%d\n", input % 2);
    input = input / 2;
  }

  return 0;
}