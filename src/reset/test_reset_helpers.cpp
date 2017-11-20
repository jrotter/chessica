#include "reset.h"

int Reset::MatchesToFrom(const char *CompareFrom, const char *CompareTo)
{
  unsigned int FromNum = TextToSquareNumber((char *) CompareFrom);
  unsigned int ToNum = TextToSquareNumber((char *) CompareTo);

  if ((From == FromNum) && (To == ToNum))
    return TRUE;
  else
    return FALSE;
}


int Reset::GenerateSingleMove(Reset *Child, const char *MoveFrom, const char *MoveTo)
{
  int retval = FALSE;

  InitializeMoveGeneration();
  InitMyChild(Child);
  while(GenerateNextMove(Child))
  {
    if (Child->MatchesToFrom(MoveFrom,MoveTo))
    {
      retval = TRUE;
      break;
    }
    InitMyChild(Child);
  }
  return(retval);
}
