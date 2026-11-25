#include <stdio.h>

int main() {
  FILE* data = fopen("data/DATA26.TXT", "r");

  if (!data) {
    printf("File unable to be read.\n");
    return -1;
  }

  int blocked_count = 0;
  int reading = 0;
  int reading_arr[80];

  int line = 0;
  while(fscanf(data, "%d", &reading) == 1) {
    reading_arr[line] = reading;
    line++;
  }
  fclose(data);

  for (int i = 1; i < line; ++i) {
    if (reading_arr[i-1] - reading_arr[i] > 100) blocked_count++;
  }

  printf("Light reader blocked %d times\n", blocked_count);

  return 0;
}