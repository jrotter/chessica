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

char * Reset::ConvertToFEN(char *TargetString)
{
  unsigned long long int square = 0x0000000000000080;
  unsigned long long int rightside = 0x0101010101010101;
  int FENindex = 0;
  int emptycount = 0;
  int filecount = 0;

  // Board representation
  while(square)
  {
    if (bAll & square)
    {
      if (emptycount)
        TargetString[FENindex++] = '0' + emptycount;
      if (bPawns & square)
        TargetString[FENindex] = 'P';
      if (bKnights & square)
        TargetString[FENindex] = 'N';
      if (bBishops & square)
        TargetString[FENindex] = 'B';
      if (bRooks & square)
        TargetString[FENindex] = 'R';
      if (bQueens & square)
        TargetString[FENindex] = 'Q';
      if (bKings & square)
        TargetString[FENindex] = 'K';
      if (bBlack & square)
        TargetString[FENindex] += 32;
      FENindex++;
      emptycount = 0;
    }
    else //no piece
    {
      emptycount++;
    }

    if (square & rightside)
      square = square << 15;
    else
      square = square >> 1;

    filecount++;
    if (filecount >= 8)
    {
      filecount = 0;
      if (emptycount) 
      {
        TargetString[FENindex++] = '0' + emptycount;
        emptycount = 0;
      }
      if (square)
        TargetString[FENindex++] = '/';
      else
        TargetString[FENindex++] = ' ';
    }
  }

  // Active color
  if (ToMove == WHITE)
    TargetString[FENindex++] = 'w';
  else
    TargetString[FENindex++] = 'b';
  TargetString[FENindex++] = ' ';

  // Castling availability
  if (WhiteCastleQ | WhiteCastleK | BlackCastleQ | BlackCastleK)
  {
    if (WhiteCastleK)
      TargetString[FENindex++] = 'K';
    if (WhiteCastleQ)
      TargetString[FENindex++] = 'Q';
    if (BlackCastleK)
      TargetString[FENindex++] = 'k';
    if (BlackCastleQ)
      TargetString[FENindex++] = 'q';
  }
  else
    TargetString[FENindex++] = '-';
  TargetString[FENindex++] = ' ';

  // En Passant target square
  if (bEP)
  {
    if (bEP & FILE1)
      TargetString[FENindex++] = 'a';
    if (bEP & FILE2)
      TargetString[FENindex++] = 'b';
    if (bEP & FILE3)
      TargetString[FENindex++] = 'c';
    if (bEP & FILE4)
      TargetString[FENindex++] = 'd';
    if (bEP & FILE5)
      TargetString[FENindex++] = 'e';
    if (bEP & FILE6)
      TargetString[FENindex++] = 'f';
    if (bEP & FILE7)
      TargetString[FENindex++] = 'g';
    if (bEP & FILE8)
      TargetString[FENindex++] = 'h';
    if (bEP & RANK1)
      TargetString[FENindex++] = '1';
    if (bEP & RANK2)
      TargetString[FENindex++] = '2';
    if (bEP & RANK3)
      TargetString[FENindex++] = '3';
    if (bEP & RANK4)
      TargetString[FENindex++] = '4';
    if (bEP & RANK5)
      TargetString[FENindex++] = '5';
    if (bEP & RANK6)
      TargetString[FENindex++] = '6';
    if (bEP & RANK7)
      TargetString[FENindex++] = '7';
    if (bEP & RANK8)
      TargetString[FENindex++] = '8';
  }
  else
    TargetString[FENindex++] = '-';
  TargetString[FENindex++] = ' ';

  // Halfmove clock
  TargetString[FENindex++] = '0'; //ignore for now
  TargetString[FENindex++] = ' ';

  // Move number
  TargetString[FENindex++] = '0'; //ignore for now
  TargetString[FENindex] = '\0';
  printf("FEN: %s\n",TargetString);
}

