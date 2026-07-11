#include "raylib.h"
#include <stdbool.h>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1200;
const int BOARD_SIZE = 8;
const int SQUARE_SIZE = SCREEN_WIDTH / BOARD_SIZE;

int SelectedRow = -1;
int SelectedCol = -1;
bool isPieceSelected = false;

void DrawBoard(void){
    for(int row = 0; row < BOARD_SIZE; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            Color GetSquareColor = ((row + col) % 2 == 0) ? BEIGE : BROWN;

            if(isPieceSelected && row == SelectedRow && col  == SelectedCol){
                GetSquareColor = ORANGE;
            }
            DrawRectangle(col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, GetSquareColor);
        }
    }
}

int main(){

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "my first window");

    SetTargetFPS(60);
    DrawBoard();

    while (!WindowShouldClose()){

        BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
