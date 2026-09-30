#include <stdbool.h>

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