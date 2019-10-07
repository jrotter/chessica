#ifndef reset_h__
#define reset_h__

#include "common.h"
#include "constants_reset.h"
#include "score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULLRESET (Reset *) 0

/* Define the piece types */
#define NONE 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Constants for board searching
#define NOTRANK1 0x00ffffffffffffff
#define RANK1 0xff00000000000000
#define RANK2 0x00ff000000000000
#define RANK3 0x0000ff0000000000
#define RANK4 0x000000ff00000000
#define RANK5 0x00000000ff000000
#define RANK6 0x0000000000ff0000
#define RANK7 0x000000000000ff00
#define RANK8 0x00000000000000ff
#define NOTRANK1 0x00ffffffffffffff
#define NOTRANK2 0xff00ffffffffffff
#define NOTRANK3 0xffff00ffffffffff
#define NOTRANK4 0xffffff00ffffffff
#define NOTRANK5 0xffffffff00ffffff
#define NOTRANK6 0xffffffffff00ffff
#define NOTRANK7 0xffffffffffff00ff
#define NOTRANK8 0xffffffffffffff00
#define FILE1 0x8080808080808080
#define FILE2 0x4040404040404040
#define FILE3 0x2020202020202020
#define FILE4 0x1010101010101010
#define FILE5 0x0808080808080808
#define FILE6 0x0404040404040404
#define FILE7 0x0202020202020202
#define FILE8 0x0101010101010101
#define NOTFILE1 0x7f7f7f7f7f7f7f7f
#define NOTFILE2 0xbfbfbfbfbfbfbfbf
#define NOTFILE3 0xdfdfdfdfdfdfdfdf
#define NOTFILE4 0xefefefefefefefef
#define NOTFILE5 0xf7f7f7f7f7f7f7f7
#define NOTFILE6 0xfbfbfbfbfbfbfbfb
#define NOTFILE7 0xfdfdfdfdfdfdfdfd
#define NOTFILE8 0xfefefefefefefefe
#define CANMOVEUP    0xffffffffffffff00
#define CANMOVEDOWN  0x00ffffffffffffff
#define CANMOVELEFT  0x7f7f7f7f7f7f7f7f
#define CANMOVERIGHT 0xfefefefefefefefe
#define UREDGE 0xfefefefefefefe00
#define ULEDGE 0x7f7f7f7f7f7f7f00
#define DREDGE 0x00fefefefefefefe
#define DLEDGE 0x007f7f7f7f7f7f7f
#define K0100 0xfefefefefefe0000
#define K0200 0xfcfcfcfcfcfcfc00
#define K0400 0x00fcfcfcfcfcfcfc
#define K0500 0x0000fefefefefefe
#define K0700 0x00007f7f7f7f7f7f
#define K0800 0x003f3f3f3f3f3f3f
#define K1000 0x3f3f3f3f3f3f3f00
#define K1100 0x7f7f7f7f7f7f0000
#define ULCORNER 0x0000000000000080
#define URCORNER 0x0000000000000001
#define LLCORNER 0x8000000000000000
#define LRCORNER 0x0100000000000000

#define WCASTLEKSAFE 0x0e00000000000000
#define WCASTLEQSAFE 0x3800000000000000
#define BCASTLEKSAFE 0x000000000000000e
#define BCASTLEQSAFE 0x0000000000000038
#define WCASTLEKEMPTY 0x0600000000000000
#define WCASTLEQEMPTY 0x7000000000000000
#define BCASTLEKEMPTY 0x0000000000000006
#define BCASTLEQEMPTY 0x0000000000000070

class Reset {

/*************************************************************/
/*************************************************************/
/*********************** PROTECTED ***************************/
/*************************************************************/
/*************************************************************/
protected:

  ////////////////////////////////////
  //Fields passed from Parent to Child
  ////////////////////////////////////
  unsigned long long int bAll;      // 8 bytes (  8)
  unsigned long long int bWhite;    // 8 bytes ( 16)
  unsigned long long int bBlack;    // 8 bytes ( 24)
  unsigned long long int bPawns;    // 8 bytes ( 32)
  unsigned long long int bKnights;  // 8 bytes ( 40)
  unsigned long long int bBishops;  // 8 bytes ( 48)
  unsigned long long int bRooks;    // 8 bytes ( 56)
  unsigned long long int bQueens;   // 8 bytes ( 64)
  unsigned long long int bKings;    // 8 bytes ( 72)
  signed char Material;             // 1 byte  ( 73)
  unsigned char MovesSinceCapture;  // 1 byte  ( 74)
  unsigned char WhiteKingSquare;    // 1 byte  ( 75)
  unsigned char BlackKingSquare;    // 1 byte  ( 76)
                                    // 4 bytes ( 80) below
  unsigned WhiteCastleQ :1;     // white can still castle when on
  unsigned WhiteCastleK :1;     // white can still castle when on
  unsigned BlackCastleQ :1;     // black can still castle when on
  unsigned BlackCastleK :1;     // black can still castle when on
  unsigned Reserved01 :28; 

  ////////////////////////////////////
  //Fields cleared in a new Child
  ////////////////////////////////////
  unsigned long long int bCurrentPiece; // 8 bytes (  8)
  unsigned long long int bEP;           // 8 bytes ( 16)
  unsigned long long int bMoveData;     // 8 bytes ( 24)
  int Score;                            // 4 bytes ( 28)
  unsigned char MoveNumber;             // 1 byte  ( 29)
  unsigned char CurrentPiece;           // 1 byte  ( 30)
  unsigned char MoveData;               // 1 byte  ( 31)
                                        // 1 byte  ( 32) below
  unsigned Capture :1;          // Was last move a capture?
  unsigned WhiteInCheck :1;     // Is white in check?
  unsigned BlackInCheck :1;     // Is black in check?
  unsigned ToMove :1;           // Whose turn is it?  WHITE or BLACK
  unsigned EPCapture:1;         // Reset represents an en passant capture
  unsigned Promotion:1;         // Reset represents a pawn promotion
  unsigned KingCastled:1;       // Was last move a castle?
  unsigned GameOver:1;          // Is the game over?

  ///////////////////////////////////////////
  //Fields that can be garbage in a new child
  ///////////////////////////////////////////
  unsigned long long int bFrom;     // 8 bytes (  8)
  unsigned long long int bTo;       // 8 bytes ( 16)
  int HashValue;                    // 4 bytes ( 20)
  int Min;                          // 4 bytes ( 24)
  int Max;                          // 4 bytes ( 28)
  signed char ScoreDepth;           // 1 byte  ( 29)
  unsigned char HashCount;          // 1 byte  ( 30)
  signed char TimesSeen;            // 1 byte  ( 31)  
  unsigned char From;               // 1 byte  ( 32)
  unsigned char To;                 // 1 byte  ( 33)
                                    // 3 bytes ( 36)
  unsigned MustCheckSafety:1;	//Force king safety check for this reset
  unsigned reserved03:23;	//Reserved

/*************************************************************/
/*************************************************************/
/************************ PRIVATE ****************************/
/*************************************************************/
/*************************************************************/
private:

  //Class Setup
  static Reset FreeResetList;	// FreeList declaration
  static bool Initialized;      // True if one-time initialization is complete 

  //constants.cpp
  //static char Points[2][7];
  //static float DrawScore[2];
  //static float CheckMateScore[2];

  void PrintSquare(int SquareIndex, int Level);
  void PrintBoardRow(int Start, int End, int Name);
  //void LogPrintSquare(signed char PieceIndex);

  //moves.cpp
  int AddNextWhiteMove(Reset *Target, long long unsigned int *PieceBeingMoved);
  int AddNextBlackMove(Reset *Target, long long unsigned int *PieceBeingMoved);
  unsigned long long int UpdateMoveData(int Target);

  //pawn.cpp
  int GenerateNextWhitePawnMove(Reset *Child);	
  int GenerateNextBlackPawnMove(Reset *Child);
  int GenerateNextWhitePawnPromotion(Reset * Child, unsigned long long int Target);	
  int GenerateNextBlackPawnPromotion(Reset * Child, unsigned long long int Target);
  int GenerateNextWhitePawnCapture(Reset *Child);	
  int GenerateNextBlackPawnCapture(Reset *Child);

  //knight.cpp
  int GenerateNextWhiteKnightMove(Reset *Child);
  int GenerateNextBlackKnightMove(Reset *Child);
  int GenerateNextWhiteKnightCapture(Reset *Child);
  int GenerateNextBlackKnightCapture(Reset *Child);

  //bishop.cpp
  int GenerateNextWhiteBishopMove(Reset *Child);
  int GenerateNextBlackBishopMove(Reset *Child);
  int GenerateNextWhiteBishopCapture(Reset *Child);
  int GenerateNextBlackBishopCapture(Reset *Child);

  //rook.cpp
  int AddNextWhiteRookMove(Reset *MyChild);
  int AddNextBlackRookMove(Reset *MyChild);
  int GenerateNextWhiteRookMove(Reset *Child);
  int GenerateNextBlackRookMove(Reset *Child);
  int GenerateNextWhiteRookCapture(Reset *Child);
  int GenerateNextBlackRookCapture(Reset *Child);

  //queen.cpp
  int GenerateNextWhiteQueenMove(Reset *Child);
  int GenerateNextBlackQueenMove(Reset *Child);
  int GenerateNextWhiteQueenCapture(Reset *Child);
  int GenerateNextBlackQueenCapture(Reset *Child);

  //king.cpp
  int AddNextWhiteKingMove(Reset *MyChild, unsigned char To);
  int AddNextBlackKingMove(Reset *MyChild, unsigned char To);
  int GenerateNextWhiteKingMove(Reset *Child);
  int GenerateNextBlackKingMove(Reset *Child);
  int GenerateNextWhiteKingCapture(Reset *Child);
  int GenerateNextBlackKingCapture(Reset *Child);

  //capture.cpp
  void CaptureProcessing(unsigned long long int To);

  //safe_reset.cpp
  void InitKingStars();
  void InitAllAttacks();

  void InitCheckFunctionRouters();

  int BlackIsSafe(unsigned long long int Squares);
  int WhiteIsSafe(unsigned long long int Squares);

  int WhiteRevealedCheckRouter(signed char Square);
  int BlackRevealedCheckRouter(signed char Square);
  int WhiteDirectCheckRouter(signed char Square);
  int BlackDirectCheckRouter(signed char Square);

  int WhiteIsSafeFromRevealedCheckUp();
  int WhiteIsSafeFromRevealedCheckUpRight();
  int WhiteIsSafeFromRevealedCheckRight();
  int WhiteIsSafeFromRevealedCheckDownRight();
  int WhiteIsSafeFromRevealedCheckDown();
  int WhiteIsSafeFromRevealedCheckDownLeft();
  int WhiteIsSafeFromRevealedCheckLeft();
  int WhiteIsSafeFromRevealedCheckUpLeft();
  int SafeFromCheck();

  int BlackIsSafeFromRevealedCheckUp();
  int BlackIsSafeFromRevealedCheckUpRight();
  int BlackIsSafeFromRevealedCheckRight();
  int BlackIsSafeFromRevealedCheckDownRight();
  int BlackIsSafeFromRevealedCheckDown();
  int BlackIsSafeFromRevealedCheckDownLeft();
  int BlackIsSafeFromRevealedCheckLeft();
  int BlackIsSafeFromRevealedCheckUpLeft();

  int WhiteIsSafeFromCheckUp();
  int WhiteIsSafeFromCheckUpRight();
  int WhiteIsSafeFromCheckRight();
  int WhiteIsSafeFromCheckDownRight();
  int WhiteIsSafeFromCheckDown();
  int WhiteIsSafeFromCheckDownLeft();
  int WhiteIsSafeFromCheckLeft();
  int WhiteIsSafeFromCheckUpLeft();
  int WhiteIsSafeFromCheckByKnight();

  int BlackIsSafeFromCheckUp();
  int BlackIsSafeFromCheckUpRight();
  int BlackIsSafeFromCheckRight();
  int BlackIsSafeFromCheckDownRight();
  int BlackIsSafeFromCheckDown();
  int BlackIsSafeFromCheckDownLeft();
  int BlackIsSafeFromCheckLeft();
  int BlackIsSafeFromCheckUpLeft();
  int BlackIsSafeFromCheckByKnight();

  int DidWhiteJustMoveIntoCheck();
  int DidBlackJustMoveIntoCheck();
  int DidWhiteMoveCauseBlackCheck();
  int DidBlackMoveCauseWhiteCheck();

  void LookForWhiteKingInCheck();
  void LookForBlackKingInCheck();
  int ValidChild(Reset *MyChild);


/*************************************************************/
/*************************************************************/
/************************ PUBLIC *****************************/
/*************************************************************/
/*************************************************************/
public:

  //reset.cpp
  Reset();  //constructor
  void Free();
  void InitMyChild(Reset *Child);
  int GameNotOver();
  int WhiteToMove();
  int FullHashesMatch(Reset *Candidate);
  int ChildrenMatch(Reset *Candidate);
  int ResetMatches(Reset *Candidate);
  void CopyReset(Reset *Target);

  //init.cpp
  void bInitToFEN(const char *);

  //test_safe.cpp
  void TestSafety();
  void TestSafety(int Color, unsigned long long int SafeSquares);

  //print.cpp
  //void LogPrintBoard();
  void PrintBoard();
  void PrintSmallBoard();
  void PrintReset();
  void PrintMoveHistory(int Ply);
  void PrintSquareToAddress(unsigned long long int Mask, char * Addr);

  //moves.cpp
  void InitializeMoveGeneration();
  int NoMovesGenerated();
  int GenerateNextMove(Reset *Target);
  int GenerateNextCapture(Reset *Target);

  //score.cpp
  int ScoreResetMaterialOnly();

  //io.cpp
  void GetAlgebraicNotation(Reset *Parent, char Text[]);

  //test_reset_helpers.cpp
  int MatchesToFrom(const char *CompareFrom, const char *CompareTo); 
  int GenerateSingleMove(Reset *Child, const char *MoveFrom, const char *MoveTo);
  char * ConvertToFEN(char *TargetString);

};

#endif  // reset_h__
