#include "game.h"


int Game::IterativeAlphaBetaSaveBest(int ThreadID)
{
  return (CurrentBoard->IterativeAlphaBetaSaveBest(ABParmlist.Depth,&(MoveCount[MoveNumber])));
}


int Game::ParallelIterativeAlphaBetaLeaveNodesSaveBest(int ThreadID)
{
  int i;
  int retval;
  ResetTree *printptr;
  char mybuffer[20];

  ThreadLock.Obtain();
  //If I am first to the party
  if ((SyncCounter % NumThreads) == 0)
  { 
    PrimeSearchThreadTrees();
  }
  SyncCounter++;
  ThreadLock.Release();
  
  while (SyncCounter < (NumThreads*i))
    usleep(100);
    
  for (i=1;i<=ABParmlist.Depth;i++)
  {
    if (ThreadData[ThreadID].Root->StillSearching())
    {
      ThreadData[ThreadID].Score = ThreadData[ThreadID].Root->AlphaBetaLeaveNodesSaveBest(ABParmlist.LeaveDepth,i,      0,MAX_SCORE,MIN_SCORE,ThreadID,&(ThreadData[ThreadID].MoveCount));
      
      ThreadLock.Obtain();
   
      //If I am last to the party
      if (((SyncCounter + 1) % NumThreads) == 0)
      {
        if (ShowThinking)
        {
          //Find best score
          
          
          IOLock.Obtain();
          
          //print best score - this needs to be a resettree routine
          printf("%d %d 0 %lld ",i,ThreadData[ThreadID].Score / 10,ThreadData[ThreadID].MoveCount);
          ThreadData[ThreadID].Root->PrintBestMoveLine();
          IOLock.Release();
        }
      }
      
      SyncCounter++;

      ThreadLock.Release();
      
      while (SyncCounter < (NumThreads*i))
        usleep(100);
    }
  }
  MergeSearchThreadTrees();
  return(retval);
}


int Game::SerialAlphaBeta(int ThreadID)
{
  //Serial
  if (ThreadID == 0)
  {
    printf("serial ab\n");
    SearchScore[Ply] = CurrentBoard->SerialAlphaBeta(ABParmlist.Depth,0,MAX_SCORE,MIN_SCORE,&(MoveCount[Ply]));
  }
}


int Game::IterativeAlphaBeta(int ThreadID)
{
  //Serial
  if (ThreadID == 0)
  {
    SearchScore[Ply] = CurrentBoard->IterativeAlphaBeta(ABParmlist.PrimeDepth,ABParmlist.Depth,&(MoveCount[Ply]));
  }
}


int Game::IterativeAlphaBetaInPlace(int ThreadID)
{
  //Serial
  if (ThreadID == 0)
  {
    SearchScore[Ply] = CurrentBoard->IterativeAlphaBetaInPlace(ABParmlist.Depth,ABParmlist.MaxHold,&(MoveCount[Ply]));
  }
}


