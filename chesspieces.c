#include "header.h"
#include <raylib.h>


Texture2D WhitePieces[7];
Texture2D BlackPieces[7];

Texture2D LoadandResize(const char *Filepath, int NewWidth, int NewHeight){
    Image imgs = LoadImage(Filepath);
    ImageResize(&imgs, SQUARE_SIZE, SQUARE_SIZE);
    Texture2D texture = LoadTextureFromImage(imgs);
    UnloadImage(imgs);

    return texture;
}

void LoadPieces(void){
WhitePieces[PAWN] = LoadandResize("chess_pieces_64x64_pack/white_pawn.png", SQUARE_SIZE, SQUARE_SIZE);
WhitePieces[KNIGHT] = LoadandResize("chess_pieces_64x64_pack/white_knight.png", SQUARE_SIZE, SQUARE_SIZE);
WhitePieces[BISHOP] = LoadandResize("chess_pieces_64x64_pack/white_bishop.png", SQUARE_SIZE, SQUARE_SIZE);
WhitePieces[ROOK] = LoadandResize("chess_pieces_64x64_pack/white_rook.png", SQUARE_SIZE, SQUARE_SIZE);
WhitePieces[QUEEN] = LoadandResize("chess_pieces_64x64_pack/white_queen.png", SQUARE_SIZE, SQUARE_SIZE);
WhitePieces[KING] = LoadandResize("chess_pieces_64x64_pack/white_king.png", SQUARE_SIZE, SQUARE_SIZE);

BlackPieces[PAWN] = LoadandResize("chess_pieces_64x64_pack/black_pawn.png", SQUARE_SIZE, SQUARE_SIZE);
BlackPieces[KNIGHT] = LoadandResize("chess_pieces_64x64_pack/black_knight.png", SQUARE_SIZE, SQUARE_SIZE);
BlackPieces[BISHOP] = LoadandResize("chess_pieces_64x64_pack/black_bishop.png", SQUARE_SIZE, SQUARE_SIZE);
BlackPieces[ROOK] = LoadandResize("chess_pieces_64x64_pack/black_rook.png", SQUARE_SIZE, SQUARE_SIZE);
BlackPieces[QUEEN] = LoadandResize("chess_pieces_64x64_pack/black_queen.png", SQUARE_SIZE, SQUARE_SIZE);
BlackPieces[KING] = LoadandResize("chess_pieces_64x64_pack/black_king.png", SQUARE_SIZE, SQUARE_SIZE);

}

void UnloadPieces(void){
    for(int i = 0; i <= 6; i++){
        UnloadTexture(WhitePieces[i]);
        UnloadTexture(BlackPieces[i]);
    }
}

