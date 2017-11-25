#include "chess.h"

Game MyGame;

int main()
{
  char temp;
  ResetTree & Root = *new ResetTree;
  
  Log.Open();

  Root.InitFreeList();
  //Root.bInitToFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  //Root.PrintReset();

  MyGame.XboardCommandInterpreter();

  Log.Close();

  return (0);
}
