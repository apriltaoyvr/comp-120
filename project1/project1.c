#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Board stuff
#define RED "\033[31m"
#define BLUE "\033[34m"
#define DIM "\033[90m"
#define RESET "\033[0m"

void print_board(char* board) {
  int i;
  char c[9];

  for (i = 0; i < 9; ++i) {
    const char current = board[i];
    char new_square = c[i];

    if (current == ' ')
      new_square = '0' + i;
    else
      new_square = current;

    putchar(' ');

    if (current == 'O')
      printf(BLUE "O" RESET);
    else if (current == 'X')
      printf(RED "X" RESET);
    else
      printf(RESET "%c" RESET, new_square);

    putchar(' ');

    if (i != 8) {
      if (i % 3 == 2)
        printf(DIM "\n---+---+---\n" RESET);
      else
        printf(DIM "|" RESET);
    }
  }

  putchar('\n');
}

// Win state checks
bool match_exists(char* board, char player) {
  int i;

  // Horizontal
  for (i = 0; i < 9; i += 3) {
    if (board[i] == player && board[i + 1] == player && board[i + 2] == player)
      return true;
  }

  // Vertical
  for (i = 0; i < 3; ++i) {
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

bool is_game_finished(char* board, bool* player_turn) {
  if (match_exists(board, player_turn ? 'O' : 'X')) {
    printf(player_turn ? BLUE "Congratulations! You've won.\n" RESET : RED "Computer wins!\n" RESET);
    return true;
  } else if (strchr(board, ' ') == NULL) {
    printf("It's a draw!\n");
    return true;
  } else {
    return false;
  }
}

// Turn stuff
bool is_valid_move(int input, char* board) {
  return input >= 0 && input <= 8 && board[input] == ' ';
}

void get_player_move(char* board) {
  int number;
  char input[100];

  printf("Your turn (O). Please select a square (0-8): ");

  while (fgets(input, sizeof(input), stdin)) {
    if (sscanf(input, "%d", &number) == 1) {
      number /= 1;

      if (is_valid_move(number, board)) {
        board[number] = 'O';
        return;
      } else {
        printf("Please select an unoccupied square (0-8): ");
      }

    } else {
      printf("Invalid input.\nPlease choose a number (0-8): ");
    }
  }
}

void get_comp_move(char* board) {
  int move;
  printf("Computer (X) is thinking...");

  while (true) {
    move = rand() % 9;
    
    if (is_valid_move(move, board)) {
      board[move] = 'X';
      printf("Computer (X) chose square %d. Your move next!\n", move);
      break;
    }
  }
}

// Main logic
bool play_again(void) {
  char input;

  printf("Would you like to play again?\n");

  while (true) {
    printf("Press y to play again or q to quit.\n");

    if (scanf(" %c", &input) != 1)
      return false;

    if (input == 'y')
      return true;
    else if (input == 'q')
      return false;
    else
      printf("Please enter a valid input.\n");
  }
}

void play_game(void) {
  char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  bool player_turn = true;
  bool game_finished = false;

  printf("You are O and you go first. The computer is X.\n");
  print_board(board);

  while (!game_finished) {
    player_turn ? get_player_move(board) : get_comp_move(board);
    player_turn = !player_turn;

    print_board(board);

    game_finished = is_game_finished(board, &game_finished);
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
