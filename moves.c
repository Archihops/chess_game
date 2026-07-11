#include "raylib.h"
#include <stdbool.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
#define BOARD_SIZE  8
const int SQUARE_SIZE = SCREEN_WIDTH / BOARD_SIZE;

// Piece representations (Positive = White, Negative = Black, 0 = Empty)
enum Pieces { EMPTY = 0, PAWN = 1, KNIGHT = 2, BISHOP = 3, ROOK = 4, QUEEN = 5, KING = 6 };

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

void DrawBoard() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            // Alternate colors across rows and columns
            Color squareColor = ((row + col) % 2 == 0) ? BEIGE : BROWN;
            
            // Highlight the active tile if it is selected
            if (isPieceSelected && row == selectedRow && col == selectedCol) {
                squareColor = GOLD;
            }

            DrawRectangle(col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, squareColor);
            
            // Temporary placeholder text visualization for pieces
            if (board[row][col] != EMPTY) {
                const char* pieceText = (board[row][col] > 0) ? "W" : "B";
                DrawText(pieceText, col * SQUARE_SIZE + 35, row * SQUARE_SIZE + 30, 20, RAYWHITE);
            }
        }
    }
}

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chess with Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        HandleInput();
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
