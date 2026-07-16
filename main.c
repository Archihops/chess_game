#include "header.h"
#include <raylib.h>
int posx;
int posy;

void DrawBoard(void){
    for(int row = 0; row < BOARD_SIZE; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            Color GetSquareColor = ((row + col) % 2 == 0) ? BEIGE : BROWN;

            if (row == hoverrow && col == hovercol){
                GetSquareColor = LIGHT_GOLD;
            }

            else if(isPieceSelected && row == selectedRow && col == selectedCol){
                GetSquareColor = GRAY;
            }
            DrawRectangle(col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, GetSquareColor);
        }
    }
}

void DrawPieces(void){
    for (int row = 0; row < BOARD_SIZE; row++){
        for (int col = 0; col < BOARD_SIZE; col++){

            int PieceinSquare = board[row][col];

            int drawx = row * SQUARE_SIZE;
            int drawy = col * SQUARE_SIZE;

            if (PieceinSquare > 0){
                DrawTexture(WhitePieces[PieceinSquare], drawy, drawx, WHITE);
            }

            if (PieceinSquare < 0){
                DrawTexture(BlackPieces[abs(PieceinSquare)], drawy, drawx, BLACK);
            }
        }
    }
}

int main(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chess");
    SetTargetFPS(60);

    LoadPieces();

    while (!WindowShouldClose()){
        // 1. Update the game state first
        MouseTracking();
        HandleInput();
        // 2. Draw the new state
        BeginDrawing();
            ClearBackground(BLACK);
            DrawBoard();
            DrawPieces();
        EndDrawing();
    }
    UnloadPieces();
    CloseWindow();
    return 0;
}
