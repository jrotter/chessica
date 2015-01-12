#include "chess.h"

#define TESTMODE

Game MyGame;

int main()
{
  char temp;
  ResetTree & Root = *new ResetTree;

  InitKingStars();
  InitAllAttacks();
  Root.InitCheckFunctionRouters();

  Root.InitFreeList();
  //Root.bInitToFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  //Root.PrintReset();

#ifdef TESTMODE
  TestMoves();
#else
  MyGame.XboardCommandInterpreter();
#endif

  return (0);
}
