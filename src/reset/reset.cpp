#include "reset.h"

Reset Reset::FreeResetList;


/// Constructor for the Reset class
///
/// When the first Reset is built, Initialization is performed on Reset-related
/// structures, including those for measuring safety:
/// - Reset::InitKingStars, which initializes the mapping of straight-line 
/// attack routes to a king on any square of the board
/// - Reset::InitAllAttacks, which is KingStars with knights added 
/// - Reset::InitCheckFunctionRouters, which initializes methods to determine 
/// where to look for check given where a piece moved from and where it moved to
///
/// @returns Reset - a Reset instance
///
Reset::Reset()  //constructor
{
  //Class Setup
  if (!Initialized) {
    InitKingStars();
    InitAllAttacks();
    InitCheckFunctionRouters();
    Initialized = true;
  }
}


/// Initialize a child Reset for this Reset instance
///
/// @note This method is on the performance path.
///
/// @param[in,out] *Child The address of the child Reset
///
void Reset::InitMyChild(Reset * Child)
{
  int i;

  //memcpy(Child->Board,Board,137);

  memcpy((void *) &(Child->bAll),(void *) &(bAll),80);
  //Child->bAll = bAll;			//8 bytes
  //Child->bWhite = bWhite;		//8 bytes
  //Child->bBlack = bBlack;		//8 bytes
  //Child->bPawns = bPawns;		//8 bytes
  //Child->bKnights = bKnights;		//8 bytes
  //Child->bBishops = bBishops;		//8 bytes
  //Child->bRooks = bRooks;		//8 bytes
  //Child->bQueens = bQueens;		//8 bytes
  //Child->bKings = bKings;		//8 bytes
  //Child->Material = Material;		//1 byte
  //Child->MovesSinceCapture = MovesSinceCapture;	//1 byte
  //Child->WhiteKingSquare = WhiteKingSquare;	//1 byte
  //Child->BlackKingSquare = BlackKingSquare;	//1 byte
  //Childd bits				//1 byte

  memset((void *) &(Child->bCurrentPiece), 0, 32);
  //Child->bCurrentPiece = 0;
  //Child->bEP = 0;
  //Child->bMoveData = 0;
  //Child->Score = 0;
  //Child->MoveNumber = 0;
  //Child->CurrentPiece = 0;
  //Child->MoveData = 0;

  //Bits
  //Child->Capture = OFF;
  //Child->WhiteInCheck = OFF;
  //Child->BlackInCheck = OFF;
  //Child->ToMove = BLACK; //Same as OFF
  //Child->EPCapture = OFF;
  //Child->Promotion = OFF;
  //Child->KingCastled = OFF;
  //Child->GameOver = OFF;

  if (ToMove == BLACK)
    Child->ToMove = WHITE;
  Child->MustCheckSafety = (WhiteInCheck || BlackInCheck);
}


/// Given a Reset, is the game over?
///
/// @note This method is on the performance path.
///
/// @returns TRUE if the game is over and FALSE otherwise.
///
int Reset::GameNotOver()
{
  if (GameOver)
    return FALSE;
  else
    return TRUE;
}


/// Given a Reset, does its hash match mine?
///
/// @note This method is used with hashing, which is not currently enabled.
///
/// @param Candidate - The Reset to compare with me
///
/// @returns TRUE if the hashes match and FALSE otherwise.
///
int Reset::FullHashesMatch(Reset *Candidate)
{
  if (bAll == Candidate->bAll)
    return TRUE;
  else
    return FALSE;
}



/// Given a Reset that is a child of my parent, does it represent the same move that I do?
///
/// @note This method is on the performance path.
///
/// @param Candidate - The Reset to compare with me
///
/// @returns TRUE if the Resets match and FALSE otherwise.
///
int Reset::ChildrenMatch(Reset *Candidate)
{
  //
  //This is an abbreviated version of "ResetMatches" that will only work on
  //children of the same parent
  //
  if (bAll != Candidate->bAll)
    return FALSE;
  if (Promotion)
  {
    if (bKnights != Candidate->bKnights)
      return FALSE;
    if (bBishops != Candidate->bBishops)
      return FALSE;
    if (bRooks != Candidate->bRooks)
      return FALSE;
    if (bQueens != Candidate->bQueens)
      return FALSE;
  }
  return TRUE;
}



/// Given a Reset, does it represent the same move that I do?
///
/// @param Candidate - The Reset to compare with me
///
/// @returns TRUE if the Resets match and FALSE otherwise.
///
int Reset::ResetMatches(Reset *Candidate)
{
  if (bAll != Candidate->bAll)
    return FALSE;
  if (bWhite != Candidate->bWhite)
    return FALSE;
  if (bPawns != Candidate->bPawns)
    return FALSE;
  if (bKnights != Candidate->bKnights)
    return FALSE;
  if (bBishops != Candidate->bBishops)
    return FALSE;
  if (bRooks != Candidate->bRooks)
    return FALSE;
  if (bQueens != Candidate->bQueens)
    return FALSE;
  if (WhiteCastleQ != Candidate->WhiteCastleQ)
    return FALSE;
  if (WhiteCastleK != Candidate->WhiteCastleK)
    return FALSE;
  if (BlackCastleQ != Candidate->BlackCastleQ)
    return FALSE;
  if (BlackCastleK != Candidate->BlackCastleK)
    return FALSE;

  return TRUE;
}

/// \todo 
/// Instead of initializing my child each time, consider initializing a 
/// template child and then copying the first 80+32 bytes to initialize each subsequent child

//
//PERFORMANCE PATH
//
void Reset::CopyReset(Reset *Target)
{
  memcpy(&(Target->bAll),&(bAll),80+32+36);
}


//
//PERFORMANCE PATH
//
int Reset::WhiteToMove()
{
  return (ToMove == WHITE);
}

