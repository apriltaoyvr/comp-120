#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_board(char *board) {
  int i;
  char c[9];

  for (i = 0; i < 9; ++i) {
    if (board[i] == ' ')
      c[i] = '0' + i;
    else
      c[i] = board[i];
  }

  for (i = 0; i < 9; ++i) {
    putchar(' ');
    putchar(c[i]);
    putchar(' ');

    if (i != 8) {
      if (i % 3 == 2)
        printf("\n---+---+---\n");
      else
        putchar('|');
    }
  }

  putchar('\n');
}

bool check_winstate(char *board, char player) {
  int i;

  // Horizontal
  for (i = 0; i < 8; i += 3) {
    if (board[i] == player && board[i + 1] == player && board[i + 2] == player)
      return true;
  }

  // Vertical
  for (i = 0; i < 8; ++i) {
    if (board[i] == player && board[i + 3] == player && board[i + 6] == player)
      return true;
  }

  // Diagonal
  if (board[4] == player) {
    if (board[0] == player && board[8] == player)
      return true;

    if (board[2] == player && board[6] == player)
      return true;
  }

  return false;
}

int main(void) {
  char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  bool player_turn = true;
  bool still_want_to_play = true;

  // do {

  // } while (still_want_to_play);

  print_board(board);
}
