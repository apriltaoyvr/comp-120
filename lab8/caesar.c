// https://github.com/awang-capu/COMP120/blob/main/lab8_caesar_cipher.md

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STRING_SIZE_LIMIT 1024
#define INTEGER_SIZE_LIMIT 20

bool is_alpha(char c) {
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

void shift_message(char str[], int key) {
  key = ((key % 26) + 26) % 26;

  for (int i = 0; str[i] != '\0'; i++)
    if (is_alpha(str[i])) {
      char base = (str[i] >= 'a') ? 'a' : 'A';
      str[i] = base + (str[i] - base + key) % 26;
    }
}

void caesar_cipher(int input_choice) {
  char in_file[STRING_SIZE_LIMIT];
  char out_file[] = "cipher.txt";
  FILE* input = NULL;
  FILE* output = NULL;
  int key;
  char key_line[INTEGER_SIZE_LIMIT];
  char str[STRING_SIZE_LIMIT];

  printf("Enter filename: ");
  fgets(in_file, STRING_SIZE_LIMIT, stdin);
  in_file[strcspn(in_file, "\n")] = '\0';

  input = fopen(in_file, "r");
  if (input == NULL) {
    printf("Error! File could not be read.\n");
    return;
  }

  printf("Enter key: ");
  fgets(key_line, INTEGER_SIZE_LIMIT, stdin);
  sscanf(key_line, "%d", &key);
  if (input_choice == 2) key *= -1;

  output = fopen(out_file, "w");
  if (input == NULL) {
    printf("Error! File could not be read.\n");
    return;
  }

  while (fgets(str, sizeof str, input)) {
    shift_message(str, key);
    fprintf(output, "%s", str);
  }

  fclose(input);
  fclose(output);
}

void show_choices(void) {
  printf("Caesar Cipher Menu\n");
  printf("1. Encrypt\n");
  printf("2. Decrypt\n");
  printf("3. Quit\n");
  printf("Enter choice: ");
}

int main(void) {
  int input_choice;
  char input_choice_line[INTEGER_SIZE_LIMIT];
  while (1) {
    show_choices();
    fgets(input_choice_line, INTEGER_SIZE_LIMIT, stdin);
    sscanf(input_choice_line, "%d", &input_choice);
    if (input_choice == 1) {
      caesar_cipher(1);
    } else if (input_choice == 2) {
      caesar_cipher(2);
    } else if (input_choice == 3) {
      printf("Goodbye!\n");
      break;
    } else {
      printf("Invalid input! Enter 1, 2, or 3.\n\n");
    }
  }
  return 0;
}