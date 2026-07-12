#include "header.h"

void DrawBoard(void){
    for(int row = 0; row < BOARD_SIZE; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            Color GetSquareColor = ((row + col) % 2 == 0) ? BEIGE : BROWN;

            // Notice we use the exact lowercase variables shared from moves.c
            if(isPieceSelected && row == selectedRow && col == selectedCol){
                Color GetSquareColor = {255, 161, 0, 138};
            }
            DrawRectangle(col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, GetSquareColor);
        }
    }
}

int main(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chess");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        // 1. Update the game state first
        HandleInput();

        // 2. Draw the new state
        BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
