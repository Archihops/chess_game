#pragma once

#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>
#include <stdio.h>

// Replaced const int with #define macros
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200
#define BOARD_SIZE 8
#define SQUARE_SIZE (SCREEN_WIDTH / BOARD_SIZE)

enum Pieces { EMPTY = 0, PAWN = 1, KNIGHT = 2, BISHOP = 3, ROOK = 4, QUEEN = 5, KING = 6 };

extern int board[BOARD_SIZE][BOARD_SIZE];
extern bool isPieceSelected;
extern int selectedRow;
extern int selectedCol;

// Expose the function so main.c can call it
void HandleInput(void);
