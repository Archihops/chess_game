#include "header.h"


int board[BOARD_SIZE][BOARD_SIZE] = {
    {-ROOK, -KNIGHT, -BISHOP, -QUEEN, -KING, -BISHOP, -KNIGHT, -ROOK},
    {-PAWN, -PAWN,   -PAWN,   -PAWN,  -PAWN, -PAWN,   -PAWN,   -PAWN},
    {EMPTY, EMPTY,   EMPTY,   EMPTY,  EMPTY, EMPTY,   EMPTY,   EMPTY},
    {EMPTY, EMPTY,   EMPTY,   EMPTY,  EMPTY, EMPTY,   EMPTY,   EMPTY},
    {EMPTY, EMPTY,   EMPTY,   EMPTY,  EMPTY, EMPTY,   EMPTY,   EMPTY},
    {EMPTY, EMPTY,   EMPTY,   EMPTY,  EMPTY, EMPTY,   EMPTY,   EMPTY},
    { PAWN,  PAWN,    PAWN,    PAWN,   PAWN,  PAWN,    PAWN,    PAWN},
    { ROOK,  KNIGHT,  BISHOP,  QUEEN,  KING,  BISHOP,  KNIGHT,  ROOK}
};

// Selection state tracking
bool isPieceSelected = false;
int selectedRow = -1;
int selectedCol = -1;

void HandleInput() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();
        int col = mousePos.x / SQUARE_SIZE;
        int row = mousePos.y / SQUARE_SIZE;

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            if (!isPieceSelected) {
                // Select a piece if the cell is not empty
                if (board[row][col] != EMPTY) {
                    isPieceSelected = true;
                    selectedRow = row;
                    selectedCol = col;
                }
            } else {
                // Move the piece to the new target location (Basic Move Logic)
                if (row != selectedRow || col != selectedCol) {
                    board[row][col] = board[selectedRow][selectedCol];
                    board[selectedRow][selectedCol] = EMPTY;
                }
                isPieceSelected = false;
                selectedRow = -1;
                selectedCol = -1;
            }
        }
    }
}

