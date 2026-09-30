#include <stdbool.h>

// Struct
const int NUM_WINNING_WAYS = 8;

struct winning_way {
  int start_at;
  int offset;  // how far to skip ahead to find next X or O
} winning_ways[NUM_WINNING_WAYS] = {
  {0, 1}, {3, 1}, {6, 1},  // horizontal ways to win
  {0, 3}, {3, 3}, {6, 3},  // vertical ways to win
  {0, 4}, {2, 2}           // diagonal ways to win
};

bool check_winning(char *board, char player) {
  for (int i = 0; i < NUM_WINNING_WAYS; i++) {
    int loc = winning_ways[i].start_at;
    int offset = winning_ways[i].offset;
    for (int j = 0; j < 3; j++) {
      if (board[loc] != player)
        goto next_way;
      loc += offset;
    }
    return true;
next_way:
  }
}

// Check win states for variable sized grids
bool check_winning_scalable(const char *board, char player, int row_size, int col_size) {
  int x;
  int y;
  bool win;

  // Horizontal
  for (y = 0; y < col_size; ++y) {
    win = true;
    for (x = 0; x < row_size; ++x) {
      if (board[y * row_size + x] != player) {
        win = false;
        break;
      }
    }
    if (win) return true;
  }

  // Vertical
  for (x = 0; x < row_size; ++x) {
    win = true;
    for (y = 0; y < col_size; ++y) {
      if (board[y * row_size + x] != player) {
        win = false;
        break;
      }
    }
    if (win) return true;
  }

  // Diagonal
  win = true;
  for (x = 0; x < row_size; ++x) {
    if (board[x * row_size + x] != player) {
      win = false;
      break;
    }
  }
  if (win) return true;

  win = true;
  for (y = 0; y < col_size; ++y) {
    x = row_size - 1 - y;
    if (board[y * row_size + x] != player) {
      win = false;
      break;
    }
  }
  if (win) return true;

  return false;
}