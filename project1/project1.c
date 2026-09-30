#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_board(char *board)
{
  int i;
  int j;
  char c[9];

  for (i = 0; i < 9; ++i)
  {
    if (board[i] == ' ')
      c[i] = '0' + i;
    else
      c[i] = board[i];
  }

  for (i = 0; i < 9; ++i)
  {
    putchar(' ');
    putchar(c[i]);
    putchar(' ');

    if (i != 8)
    {
      if (i % 3 == 2)
        printf("\n---+---+---\n");
      else
        putchar('|');
    }
  }

  putchar('\n');
}

int main(void)
{
  char board[] = {' ', ' ', ' ', 'x', ' ', ' ', ' ', ' ', ' '};
  bool player_turn = true;

  print_board(board);
}
