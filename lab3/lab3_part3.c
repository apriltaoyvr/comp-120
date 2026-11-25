#include <stdio.h>
#include <stdbool.h>

int main(void) {
  char var_name[50];
  
  printf("Enter a variable name: ");
  scanf("%s", var_name);
  
  char initial = var_name[0];
  bool upperAlpha = initial >= 'a' && initial <= 'z';
  bool lowerAlpha = initial >= 'A' && initial <= 'Z';

  if (upperAlpha || lowerAlpha || initial == '_') {
    printf("%s may be a valid name for a variable", var_name);
  } else {
    printf("%s is not a valid name for a variable", var_name);
  }

  return 0;
}