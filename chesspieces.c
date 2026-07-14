#include "header.h"
#include <raylib.h>

Texture2D WhitePieces[7];
Texture2D BlackPieces[7];


void LoadPieces(void){
WhitePieces[PAWN] = LoadTexture("chess_pieces_64x64_pack/white_pawn.png");
WhitePieces[KNIGHT] = LoadTexture("chess_pieces_64x64_pack/white_knight.png");
WhitePieces[BISHOP] = LoadTexture("chess_pieces_64x64_pack/white_bishop.png");
WhitePieces[ROOK] = LoadTexture("chess_pieces_64x64_pack/white_rook.png");
WhitePieces[QUEEN] = LoadTexture("chess_pieces_64x64_pack/white_queen.png");
WhitePieces[KING] = LoadTexture("chess_pieces_64x64_pack/white_king.png");

BlackPieces[PAWN] = LoadTexture("chess_pieces_64x64_pack/black_pawn.png");
BlackPieces[KNIGHT] = LoadTexture("chess_pieces_64x64_pack/black_knight.png");
BlackPieces[BISHOP] = LoadTexture("chess_pieces_64x64_pack/black_bishop.png");
BlackPieces[ROOK] = LoadTexture("chess_pieces_64x64_pack/black_rook.png");
BlackPieces[QUEEN] = LoadTexture("chess_pieces_64x64_pack/black_queen.png");
BlackPieces[KING] = LoadTexture("chess_pieces_64x64_pack/black_king.png");

}

void UnloadPieces(void){
    for(int i = 0; i <= 6; i++){
        UnloadTexture(WhitePieces[i]);
        UnloadTexture(BlackPieces[i]);
    }
}

