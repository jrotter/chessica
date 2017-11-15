#include "chess.h"


void ResetTree::PrintChildren()
{
  ResetTree *CurrentNode = Children.First;	//Start with the first child

  while (CurrentNode)				//While there are children
  {
    CurrentNode->PrintReset();			//Print this child
    CurrentNode = CurrentNode->NextSibling;
  }
}


void ResetTree::PrintBestMoveLine()
{
  char mybuffer[100];

  printf("%s",PrintBestMoveLineToBuffer(mybuffer));
}



char *ResetTree::PrintBestMoveLineToBuffer(char *outbuffer)
{
  char mybuffer[10];
  ResetTree *printptr;

  printptr = Children.First;
  while (printptr)
  {
    printptr->GetAlgebraicNotation(printptr->Parent,mybuffer);
    sprintf(outbuffer,"%s  ",mybuffer);
    printptr = printptr->Children.First;
  }
  sprintf(outbuffer,"\n");
  return(outbuffer);
}


void ResetTree::PrintMoveHistory(int Ply)
{
  char Boards[8][8][8]; //Board,Row,Column
  int i,j,k;
  unsigned long long int Mask;
  int iterator;

  for (i=0;i<=Ply;i++)
  {
    Mask = 0x8000000000000000;
    for (j=0;j<64;j++)
    {
      MoveHistory[i]->PrintSquareToAddress(Mask, &(Boards[i][j/8][j%8]));
      Mask >>= 1;
    }
  }
  for (i=7;i>=0;i--)
  {
    for (j=0;j<=Ply;j++)
    {
      for (k=0;k<8;k++)
      {
        printf("%c ",Boards[j][i][k]);
      }
      printf("    ");
    }
    printf("\n");
  }
  printf("\n");
}


