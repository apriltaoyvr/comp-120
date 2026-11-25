#include <stdio.h>

int main(void) {
  char button;

  printf("Press a button (o/f/u/d/+/-): ");
  scanf("%c", &button);

  switch (button) {
    case ('o'):
      printf("Power is on.");
      break;
    
    case ('f'):
      printf("Power is off.");
      break;
    
    case ('u'):
      printf("Channel up.");
      break;
    
    case ('d'):
      printf("Channel down.");
      break;
    
    case ('+'):
      printf("Volume up.");
      break;
    
    case ('-'):
      printf("Volume down.");
      break;
    
    default:
      printf("Invalid input.");
      break;
  }

  return 0;
}