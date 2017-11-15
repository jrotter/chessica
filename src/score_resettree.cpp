#include "chess.h"


int ResetTree::ScoreResetNode()
{
  int MaterialScore;
  long long int MoveCount = 0;

  MaterialScore = ScoreResetMaterialOnly();
  //MaterialScore = AlphaBetaCapturesOnly(MAX_SCORE,MIN_SCORE,&MoveCount);
  //printf("MoveCount == %d\n",MoveCount);
  return MaterialScore;
}
