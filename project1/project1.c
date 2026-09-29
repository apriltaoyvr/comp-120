#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_board(char board_state[9])
{
  int i;
  int j;

  for (i = 0; i < 9; ++i)
  {
    char square = board_state[i];
    int offset = i + 1;

    if (board_state[i] == ' ') {
      printf(" %d ", i);
    } else {
      printf(" %c ", board_state[i]);
    }

    if (offset % 3 == 0 && offset != 9)
    {
      printf("\n");
      printf("---+---+---\n");
    }
    else
    {
      printf("|");
    }
  }
}

int main(void)
{
  char board[9] = "   x     ";
  bool player_turn = true;

  print_board(board);
}
