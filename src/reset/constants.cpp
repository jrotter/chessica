#include "reset.h"

signed char Points[2][7] = { { 0,-1,-3,-3,-5,-9,-100 },
                             { 0, 1, 3, 3, 5, 9, 100 } };

signed char InitialPieceType[32] = { PAWN,   PAWN,   PAWN,   PAWN,
                                     PAWN,   PAWN,   PAWN,   PAWN,
                                     KNIGHT, KNIGHT, BISHOP, BISHOP,
                                     ROOK,   ROOK,   QUEEN,  KING,
                                     PAWN,   PAWN,   PAWN,   PAWN,
                                     PAWN,   PAWN,   PAWN,   PAWN,
                                     KNIGHT, KNIGHT, BISHOP, BISHOP,
                                     ROOK,   ROOK,   QUEEN,  KING };

float DrawScore[2] = {-DRAW_SCORE,DRAW_SCORE};
float CheckMateScore[2] = {-CHECKMATE_SCORE,CHECKMATE_SCORE};


