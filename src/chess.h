#ifndef chess_h__
#define chess_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "logger.h"
#include "constants.h"
#include "lock.h"
#include "common.h"
#include "reset.h"
#include "tree.h"
#include "score.h"
#include "timer.h"
#include "hash.h"
#include "game.h"

using namespace std;

typedef struct ABParmStruct {
  int Depth;
  int MaxHold;
  int LeaveDepth;
  int PrimeDepth;
} ABParms;

typedef struct {
  Game *ThisGame;
} EngineParmType;

typedef struct {
    Game *myGame;
    int inThreadID;
  } SearchThreadParms;

typedef int (Game::*SearchRoutineFunction)(int ThreadID);

/* GLOBAL STRUCTURES */

/////////////////////////////////////////
//
// Cross-Process Stuff
//
extern Lock IOLock;	//io.cpp

extern Logger Log;	//logger.cpp
extern FILE *logfile;
extern int HashMultiples[64];
extern ResetTree * FreeList[MAX_THREADS];	//tree.cpp
extern ResetTree * MoveHistory[200];		//tree.cpp

/* io.cpp */
//extern int TextToSquareNumber(char Text[]);
//extern int SquareNumberToText(int SquareNumber, char Text[]);
extern void ObtainIOSerialization();
extern void ReleaseIOSerialization();

/* print.cpp */
extern void ClearScreen();

/* test_main.cpp */
extern int TestMoves();

/* tree.cpp */
extern ResetTree *MoveHistory[];

/* xboard.cpp */
void InitIO();
void XboardCommandInterpreter();

#endif  //chess_h__

