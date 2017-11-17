#include "reset.h"

void Reset::GetAlgebraicNotation(Reset *Parent, char Text[])
{
  char tobuffer[5], frombuffer[5], tempbuffer[5];
  int i = 0;
  int DisambiguateFile = 0; //File is a column (letter)
  int DisambiguateRank = 0; //Rank is a row (number)
  Reset LP, LC;
  Reset *LocalParent = &LP;
  Reset *LocalChild = &LC;
  

  if (KingCastled)
  {
    Text[i++] = 'O';
    Text[i++] = '-';
    Text[i++] = 'O';
    if ((To == 2) || (To == 58))
    {
      Text[i++] = '-';
      Text[i++] = 'O';
    }
  }
  else
  {
    Parent->CopyReset(LocalParent);
    SquareNumberToText(To,tobuffer);
    SquareNumberToText(From,frombuffer);
    LocalParent->InitializeMoveGeneration();
    LocalParent->InitMyChild(LocalChild);

    if (Promotion || EPCapture || (bPawns & bTo))
    {
      if (Capture || EPCapture)
      {
        Text[i++] = frombuffer[0];
        Text[i++] = 'x';
      }
      Text[i++] = tobuffer[0];
      Text[i++] = tobuffer[1];

      if (Promotion)
      {
        if (bTo & bKnights)
          Text[i++] = 'N';
        if (bTo & bBishops)
          Text[i++] = 'B';
        if (bTo & bRooks)
          Text[i++] = 'R';
        if (bTo & bQueens)
          Text[i++] = 'Q';
      }
    }


    if (bKnights & bTo)
    {
      while(LocalParent->GenerateNextMove(LocalChild))
      {
        if (!ResetMatches(LocalChild))
        {
          if (bTo & LocalChild->bTo & LocalChild->bKnights)
          {
            SquareNumberToText(LocalChild->From,tempbuffer);
            if (tempbuffer[0] == frombuffer[0])
              DisambiguateRank = 1;
            else
            {
              if (tempbuffer[1] == frombuffer[1])
                DisambiguateFile = 1;
            }
          }
        }
        LocalParent->InitMyChild(LocalChild);
      }

      Text[i++] = 'N';
      if (DisambiguateFile)
        Text[i++] = frombuffer[0];
      if (DisambiguateRank)
        Text[i++] = frombuffer[1];
      if (Capture)
        Text[i++] = 'x';
      Text[i++] = tobuffer[0];
      Text[i++] = tobuffer[1];
    }

    if (bBishops & bTo)
    {
      while(LocalParent->GenerateNextMove(LocalChild))
      {
        if (!ResetMatches(LocalChild))
        {
          if (bTo & LocalChild->bTo & LocalChild->bBishops)
          {
            SquareNumberToText(LocalChild->From,tempbuffer);
            if (tempbuffer[0] == frombuffer[0])
              DisambiguateRank = 1;
            else
            {
              if (tempbuffer[1] == frombuffer[1])
                DisambiguateFile = 1;
            }
          }
        }
        LocalParent->InitMyChild(LocalChild);
      }

      Text[i++] = 'B';
      if (DisambiguateFile)
        Text[i++] = frombuffer[0];
      if (DisambiguateRank)
        Text[i++] = frombuffer[1];
      if (Capture)
        Text[i++] = 'x';
      Text[i++] = tobuffer[0];
      Text[i++] = tobuffer[1];
    }

    if (bRooks & bTo)
    {
      while(LocalParent->GenerateNextMove(LocalChild))
      {
        if (!ResetMatches(LocalChild))
        {
          if (bTo & LocalChild->bTo & LocalChild->bRooks)
          {
            SquareNumberToText(LocalChild->From,tempbuffer);
            if (tempbuffer[0] == frombuffer[0])
              DisambiguateRank = 1;
            else
            {
              if (tempbuffer[1] == frombuffer[1])
                DisambiguateFile = 1;
            }
          }
        }
        LocalParent->InitMyChild(LocalChild);
      }

      Text[i++] = 'R';
      if (DisambiguateFile)
        Text[i++] = frombuffer[0];
      if (DisambiguateRank)
        Text[i++] = frombuffer[1];
      if (Capture)
        Text[i++] = 'x';
      Text[i++] = tobuffer[0];
      Text[i++] = tobuffer[1];
    }

    if (bQueens & bTo)
    {
      while(LocalParent->GenerateNextMove(LocalChild))
      {
        if (!ResetMatches(LocalChild))
        {
          if (bTo & LocalChild->bTo & LocalChild->bQueens)
          {
            SquareNumberToText(LocalChild->From,tempbuffer);
            if (tempbuffer[0] == frombuffer[0])
              DisambiguateRank = 1;
            else
            {
              if (tempbuffer[1] == frombuffer[1])
                DisambiguateFile = 1;
            }
          }
        }
        LocalParent->InitMyChild(LocalChild);
      }

      Text[i++] = 'Q';
      if (DisambiguateFile)
        Text[i++] = frombuffer[0];
      if (DisambiguateRank)
        Text[i++] = frombuffer[1];
      if (Capture)
        Text[i++] = 'x';
      Text[i++] = tobuffer[0];
      Text[i++] = tobuffer[1];
    }

    if (bKings & bTo)
    {
      Text[i++] = 'K';
      if (Capture)
        Text[i++] = 'x';
      Text[i++] = tobuffer[0];
      Text[i++] = tobuffer[1];
    }
  }

  if (WhiteInCheck || BlackInCheck)
  {
    if (GameOver)
      Text[i++] = '#';
    else
      Text[i++] = '+';
  }
  Text[i++] = '\0';
}


