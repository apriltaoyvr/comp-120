#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
  return input >= 0 && input < 9 && board[input] == ' ';
}

void get_player_move(char* board) {
  int input;

  while (true) {
    printf("Your turn (O). Please select a square (0-8): ");
    if (scanf("%d", &input) != 1) {
      printf("Invalid input. Please enter a number from 0 to 8.\n");
      continue;
    }

    if (is_valid_move(input, board)) {
      board[input] = 'O';
      return;
    }

    printf("Invalid move. Please select a valid square.\n");
  }
}

void get_comp_move(char* board) {
  int move;
  printf("Computer (X) is thinking...");

  do {
    move = rand() % 9;
    if (is_valid_move(move, board)) {
      board[move] = 'X';
      printf("Computer (X) chose square %d. Your move next!\n", move);
      break;
    }
  } while (true);
}

bool play_again(void) {
  char input;

  printf("Would you like to play again?\n");

  while (true) {
    printf("Press y to play again or q to quit.\n");
    if (scanf(" %c", &input) != 1) {
      return false;
    }

    if (input == 'y') {
      return true;
    } else if (input == 'q') {
      return false;
    } else {
      printf("Please enter a valid input.\n");
    }
  }
}

void play_game(void) {
  char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  bool player_turn = true;
  bool game_finished = false;

  printf("You are O and you go first. The computer is X.\n");
  print_board(board);

  while (!game_finished) {
    if (player_turn) {
      get_player_move(board);
    } else {
      get_comp_move(board);
    }

    print_board(board);

    if (in_winstate(board, player_turn ? 'O' : 'X')) {
      printf(player_turn ? "Congratulations! You've won.\n" : "Computer wins!\n");
      game_finished = true;
    } else if (strchr(board, ' ') == NULL) {
      printf("It's a draw!\n");
      game_finished = true;
    } else {
      player_turn = !player_turn;
    }
  }
}

int main(void) {
  bool still_want_to_play;
  srand(rand());

  do {
    play_game();
    still_want_to_play = play_again();
  } while (still_want_to_play);

  printf("Thanks for playing!\n");
}
