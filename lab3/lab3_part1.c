#include <stdio.h>

int main(void) {
  int testScore;
  char letterGrade;

  printf("Enter your test score: ");
  scanf("%d", &testScore);

  if (testScore >= 90) {
    letterGrade = 'A';
  } else if (testScore >= 80) {
    letterGrade = 'B';
  } else if (testScore >= 70) {
    letterGrade = 'C';
  } else if (testScore >= 60) {
    letterGrade = 'D';
  } else if (testScore >= 50) {
    letterGrade = 'E';
  } else {
    letterGrade = 'F';
  }

  printf("Your test score is %d, so your letter grade is %c.\n", testScore, letterGrade);

  return 0;
}