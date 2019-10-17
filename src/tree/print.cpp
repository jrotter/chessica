#include "tree.h"


void ResetTree::PrintChildren()
{
  ResetTree *CurrentNode = Children.First;	//Start with the first child

  while (CurrentNode)				//While there are children
  {
    CurrentNode->PrintReset();			//Print this child
    CurrentNode = CurrentNode->NextSibling;
  }
}


/// Print the string of moves that led to the current ResetTree
///
/// Traces back through parent pointers until it reaches a NULL parent
/// and prints the move sequence from that original parent to this move
///
void ResetTree::PrintMyMoveLine()
{
  char mybuffer[100];

  printf("%s",PrintMyMoveLineToBuffer(mybuffer));
}



/// Print the string of moves that led to the current ResetTree
///
/// Traces back through parent pointers until it reaches a NULL parent
/// and prints the move sequence from that original parent to this move
///
/// @param outbuffer - the buffer in which to store the move line
///
/// @returns a pointer to string representing the move line
///
char *ResetTree::PrintMyMoveLineToBuffer(char *outbuffer)
{
  char mybuffer[50][10];
  ResetTree *printptr;
  int x, i = 0;

  *outbuffer = '\0';
  printptr = this;
  while (printptr && printptr->Parent)
  {
    printptr->GetAlgebraicNotation(printptr->Parent,mybuffer[i++]);
    printptr = printptr->Parent;
  }
  for(x=(i-1); x>=0; x--)
  {
    strcat(outbuffer,mybuffer[x]);
    strcat(outbuffer,"  ");
  }
  strcat(outbuffer,"\n");
  printf("%s",outbuffer);
  return(outbuffer);
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

  *outbuffer = '\0';
  printptr = Children.First;
  while (printptr)
  {
    printptr->GetAlgebraicNotation(printptr->Parent,mybuffer);
    strcat(outbuffer,mybuffer);
    strcat(outbuffer,"  ");
    printptr = printptr->Children.First;
  }
  strcat(outbuffer,"\n");
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


