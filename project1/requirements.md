# Project: Tic-Tac-Toe vs. the Computer

## Overview

Write a C program that lets a person play tic-tac-toe against the computer. If you don't know the game, see the rules below.

**Groups:** Yourself (Project 1 is an individual assignment).

**Concepts practiced:** variables, `char` arrays, `bool`, `if`, `for`, `while`, `do...while`, user-defined functions, `rand()` and `srand()`.

---

## Game Rules

- The game is played on a 3x3 board with 9 squares.
- Two players take turns placing their symbol on an **empty** square.
- A player **wins** by getting three of their symbols in a row: horizontally, vertically, or diagonally.
- If all 9 squares are filled and nobody has won, the game is a **draw**.

## Board Layout

Squares are numbered 0 to 8:

```
 0 | 1 | 2
---+---+---
 3 | 4 | 5
---+---+---
 6 | 7 | 8
```

---

## Requirements

### Board and players

1. Represent the board with a **1-D `char` array of 9 elements** (`char board[9]`). Use `' '` (a space) for an empty square.
2. The user is always **Player O** and **goes first**.
3. The computer plays **Player X** (the "virtual player").

### Moves

4. To move, the user enters an integer from **0 to 8** for an empty square.
5. The computer chooses its move using `rand()`. It does **not** need to be a good player (it may lose every time), but it must **always play a legal move**. Call `srand()` once, at the start of `main`, so the games differ from run to run.
6. After each legal move, place the player's symbol on the square, **redisplay the board**, and switch to the other player.
7. Tell the user clearly when it is their turn and what to enter. Also show clearly when the computer has finished moving (for example, "Computer (X) chose square 4. Your move next!").

### Display

8. `display_board` must use a temporary array `char c[9]`. It copies the board, but replaces each empty square with its own number (`'0' + i`), so the user always sees which numbers are still available.

### Game flow

9. Detect and report when the game is **won** (say who won) or is a **draw**.
10. The user can play **any number of games** without restarting the program. At the end of each game, ask whether to play again (`y`) or quit (`q`).

### Input handling

11. Handle **possible input errors** as much as possible: report the error, then ask again. At minimum, handle:
    - a digit outside 0 to 8 (for example `9`)
    - a square that is already taken

### Use of `bool`

12. Use `bool` (`#include <stdbool.h>`) for functions and variables that are true/false, such as `is_winner`, `game_over`, and `valid`.

### Loops

13. Use the loop that best fits each situation:
    - `while`: repeat until the input is valid
    - `do...while`: things that must happen at least once (a random pick, at least one game)
    - `for`: counted loops (the 9 turns of a game, filling the board)

### Abstraction and functional decomposition

14. Break the program into small functions, each doing one clear job. You may consider these:

    | Function | Purpose |
    |---|---|
    | `init_board` | Set all 9 squares to empty |
    | `display_board` | Print the board (uses `char c[9]`) |
    | `is_winner` | Return `true` if a player has three in a row |
    | `other_player` | Return the opposite symbol |
    | `get_human_move` | Ask until the user enters a valid square |
    | `get_computer_move` | Pick a random empty square |
    | `take_turn` | Let the current player make one move |
    | `play_game` | Play one complete game |
    | `play_again` | Ask whether to play another game |

15. The loop in `play_game` should read like the rules of tic-tac-toe: take a turn, display the board, check for a win, otherwise switch players. Keep it short and easy to follow.

---

## Sample Run

```
=====================================
        TIC-TAC-TOE vs COMPUTER
=====================================
You are O and you go first. The computer is X.
On your turn, type the number of an empty square:

 0 | 1 | 2
---+---+---
 3 | 4 | 5
---+---+---
 6 | 7 | 8

Your turn (O). Enter a square number (0-8): 4

 0 | 1 | 2
---+---+---
 3 | O | 5
---+---+---
 6 | 7 | 8

Computer (X) is thinking...
Computer (X) chose square 2. Your move next!

 0 | 1 | X
---+---+---
 3 | O | 5
---+---+---
 6 | 7 | 8

Your turn (O). Enter a square number (0-8): 4
  That square is already taken. Choose an empty one.
Your turn (O). Enter a square number (0-8): 
```

---


## Submission

Create a GitHub account, if you don't have one. You may follow [this](https://elearn.capu.ca/pluginfile.php/4140880/mod_resource/content/1/GitHub%20Setup.pdf) (note: our course is comp120).

After uploading your .c source file to your repo, write a good README.md file describing your project.

Copy your repo link and paste it on e-learn to submit.

## Grading Guide

| Category | Weight |
|---|---|
| Correct game play (legal moves, win and draw detection) | 30% |
| Functional decomposition and clear `play_game` loop | 40% |
| Required features (`bool`, `char c[9]`, `rand`/`srand`, loop choices) | 15% |
| Code style | 15% |