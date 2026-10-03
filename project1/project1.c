#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Board stuff
void print_board(char* board) {
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

// Game state
bool in_winstate(char* board, char player) {
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

bool is_valid_move(int input, char* board) {
  bool valid_number = input >= 0 && input <= 8;
  bool square_empty = board[input] == ' ';
  return valid_number && board[input] == ' ';
}

void get_player_move(char* board, bool* player_move) {
  int input;
  bool mark_placed = false;

  while (!mark_placed) {
    printf("Your turn (O). Please select a square (0-8): ");
    scanf("%d\n", &input);

    if (is_valid_move(input, &board)) {
      board[input] = "O";
      mark_placed = true;
    }

    printf("Invalid move. Please select a valid square.\n");
  }

  print_board(&board);
  player_move = false;
}

void get_comp_move(char* board, bool* player_move) {
  int move = rand() % (8 + 1 - 0);
  bool mark_placed = false;

  printf("Computer (X) is thinking...");

  while (!mark_placed) {
    if (is_valid_move(move, board)) {
      board[move] = "X";
      mark_placed = true;
      printf("Computer (X) chose square %d. Your move next!\n", move);
    }
  }

  print_board(board);
  player_move = true;
}

void play_again(bool still_want_to_play) {
  char input;
  bool valid_input;

  printf("Would you like to play again?\n");

  do {
    printf("Press y to play again or q to quit.\n");
    scanf("%d\n", &input);

    if (input == 'y') {
      valid_input = true;
      still_want_to_play = true;
    } else if (input == 'q') {
      valid_input = true;
      still_want_to_play = false;
    } else {
      printf("Please enter a valid input.\n");
    }
  } while (!valid_input);
}

void play_game(bool* still_want_to_play) {
  int winner = NULL;  // 0 = player, 1 = comp, 2 = draw
  char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  bool player_turn = true;
  bool game_finished = false;
  srand();

  printf("You are O and you go first. The computer is X.\n");

  do {
    bool player_win = in_winstate(&board, "O");
    bool comp_win = in_winstate(&board, "X");

    if (strchr(board, ' ') == NULL || player_win || comp_win) {
      game_finished = true;

      if (player_win) {
        winner = 0;
        printf("Congratulations! You've won.\n");
      } else if (comp_win) {
        winner = 1;
        printf("Computer wins!\n");
      } else {
        printf("It's a draw!\n");
      }

      play_again(still_want_to_play);
    }

    if (player_turn) {
      get_player_move(&board, player_turn);
    } else {
      get_comp_move(&board, player_turn);
    }
  } while (!game_finished);

  print_board(&board);
}

int main(void) {
  bool still_want_to_play = true;

  do {
    play_game(still_want_to_play);
  } while (still_want_to_play);

  printf("Thanks for playing!\n");
}
