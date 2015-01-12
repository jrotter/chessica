
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
  unsigned char WhiteKingSquare;    // 1 byte  ( 74)
  unsigned char BlackKingSquare;    // 1 byte  ( 75)
                                    // 1 byte  ( 76) below
  unsigned WhiteCastleQ :1;     // white can still castle when on
  unsigned WhiteCastleK :1;     // white can still castle when on
  unsigned BlackCastleQ :1;     // black can still castle when on
  unsigned BlackCastleK :1;     // black can still castle when on
  unsigned Reserved01 :4; 

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
  unsigned char MovesSinceCapture;  // 1 byte  ( 34)
                                    // 1 byte  ( 35)
  unsigned MustCheckSafety:1;	//Force king safety check for this reset
  unsigned reserved03:7;	//Reserved

/*************************************************************/
/*************************************************************/
/************************ PRIVATE ****************************/
/*************************************************************/
/*************************************************************/
private:

  static Reset FreeResetList;	/* FreeList declaration */

  void PrintSquare(int SquareIndex, int Level);
  void PrintBoardRow(int Start, int End, int Name);
  //void LogPrintSquare(signed char PieceIndex);
  void PrintSquareToAddress(unsigned long long int Mask, char * Addr);

  int AddNextWhiteMove(Reset *Target, long long unsigned int *PieceBeingMoved); //moves.cpp
  int AddNextBlackMove(Reset *Target, long long unsigned int *PieceBeingMoved); //moves.cpp

  int GenerateNextWhitePawnMove(Reset *Child);	
  int GenerateNextBlackPawnMove(Reset *Child);
  int GenerateNextWhitePawnPromotion(Reset * Child, unsigned long long int Target);	
  int GenerateNextBlackPawnPromotion(Reset * Child, unsigned long long int Target);
  int GenerateNextWhitePawnCapture(Reset *Child);	
  int GenerateNextBlackPawnCapture(Reset *Child);

  int GenerateNextWhiteKnightMove(Reset *Child);
  int GenerateNextBlackKnightMove(Reset *Child);
  int GenerateNextWhiteKnightCapture(Reset *Child);
  int GenerateNextBlackKnightCapture(Reset *Child);

  int GenerateNextWhiteBishopMove(Reset *Child);
  int GenerateNextBlackBishopMove(Reset *Child);
  int GenerateNextWhiteBishopCapture(Reset *Child);
  int GenerateNextBlackBishopCapture(Reset *Child);

  int AddNextWhiteRookMove(Reset *MyChild);
  int AddNextBlackRookMove(Reset *MyChild);
  int GenerateNextWhiteRookMove(Reset *Child);
  int GenerateNextBlackRookMove(Reset *Child);
  int GenerateNextWhiteRookCapture(Reset *Child);
  int GenerateNextBlackRookCapture(Reset *Child);

  int GenerateNextWhiteQueenMove(Reset *Child);
  int GenerateNextBlackQueenMove(Reset *Child);
  int GenerateNextWhiteQueenCapture(Reset *Child);
  int GenerateNextBlackQueenCapture(Reset *Child);

  int AddNextWhiteKingMove(Reset *MyChild, unsigned char To);
  int AddNextBlackKingMove(Reset *MyChild, unsigned char To);
  int GenerateNextWhiteKingMove(Reset *Child);
  int GenerateNextBlackKingMove(Reset *Child);
  int GenerateNextWhiteKingCapture(Reset *Child);
  int GenerateNextBlackKingCapture(Reset *Child);

  void CaptureProcessing(unsigned long long int To);	//capture.cpp
  int BlackIsSafe(unsigned long long int Squares);	//safe.cpp
  int WhiteIsSafe(unsigned long long int Squares);	//safe.cpp

  int WhiteRevealedCheckRouter(signed char Square);	//safe.cpp
  int BlackRevealedCheckRouter(signed char Square);	//safe.cpp
  int WhiteDirectCheckRouter(signed char Square);	//safe.cpp
  int BlackDirectCheckRouter(signed char Square);	//safe.cpp

  int WhiteIsSafeFromRevealedCheckUp();			//safe.cpp
  int WhiteIsSafeFromRevealedCheckUpRight();		//safe.cpp
  int WhiteIsSafeFromRevealedCheckRight();		//safe.cpp
  int WhiteIsSafeFromRevealedCheckDownRight();		//safe.cpp
  int WhiteIsSafeFromRevealedCheckDown();		//safe.cpp
  int WhiteIsSafeFromRevealedCheckDownLeft();		//safe.cpp
  int WhiteIsSafeFromRevealedCheckLeft();		//safe.cpp
  int WhiteIsSafeFromRevealedCheckUpLeft();		//safe.cpp
  int SafeFromCheck();			//safe.cpp

  int BlackIsSafeFromRevealedCheckUp();			//safe.cpp
  int BlackIsSafeFromRevealedCheckUpRight();		//safe.cpp
  int BlackIsSafeFromRevealedCheckRight();		//safe.cpp
  int BlackIsSafeFromRevealedCheckDownRight();		//safe.cpp
  int BlackIsSafeFromRevealedCheckDown();		//safe.cpp
  int BlackIsSafeFromRevealedCheckDownLeft();		//safe.cpp
  int BlackIsSafeFromRevealedCheckLeft();		//safe.cpp
  int BlackIsSafeFromRevealedCheckUpLeft();		//safe.cpp

  int WhiteIsSafeFromCheckUp();			//safe.cpp
  int WhiteIsSafeFromCheckUpRight();		//safe.cpp
  int WhiteIsSafeFromCheckRight();		//safe.cpp
  int WhiteIsSafeFromCheckDownRight();		//safe.cpp
  int WhiteIsSafeFromCheckDown();		//safe.cpp
  int WhiteIsSafeFromCheckDownLeft();		//safe.cpp
  int WhiteIsSafeFromCheckLeft();		//safe.cpp
  int WhiteIsSafeFromCheckUpLeft();		//safe.cpp
  int WhiteIsSafeFromCheckByKnight();		//safe.cpp

  int BlackIsSafeFromCheckUp();			//safe.cpp
  int BlackIsSafeFromCheckUpRight();		//safe.cpp
  int BlackIsSafeFromCheckRight();		//safe.cpp
  int BlackIsSafeFromCheckDownRight();		//safe.cpp
  int BlackIsSafeFromCheckDown();		//safe.cpp
  int BlackIsSafeFromCheckDownLeft();		//safe.cpp
  int BlackIsSafeFromCheckLeft();		//safe.cpp
  int BlackIsSafeFromCheckUpLeft();		//safe.cpp
  int BlackIsSafeFromCheckByKnight();		//safe.cpp

  int DidWhiteJustMoveIntoCheck();		//safe.cpp
  int DidBlackJustMoveIntoCheck();		//safe.cpp
  int DidWhiteMoveCauseBlackCheck();		//safe.cpp
  int DidBlackMoveCauseWhiteCheck();		//safe.cpp

  void LookForWhiteKingInCheck();		//safe.cpp
  void LookForBlackKingInCheck();		//safe.cpp
  int ValidChild(Reset *MyChild);	//safe.cpp
  unsigned long long int UpdateMoveData(int Target);	//moves.cpp

/*************************************************************/
/*************************************************************/
/************************ PUBLIC *****************************/
/*************************************************************/
/*************************************************************/
public:
  Reset();
  void Free();			//reset.cpp
  void bInitToFEN(const char *);	//test_FEN.cpp
  void TestSafety();		//test_safe.cpp
  //void LogPrintBoard();		//print.cpp
  void PrintBoard();		//print.cpp
  void PrintSmallBoard();		//print.cpp
  void PrintReset();		//print.cpp
  void PrintMoveHistory(int Ply);		//print.cpp
  void InitMyChild(Reset *Child);	//reset.cpp 
  void InitCheckFunctionRouters();		//safe.cpp

  void InitializeMoveGeneration();	//moves.cpp
  int NoMovesGenerated();		//moves.cpp
  int GenerateNextMove(Reset *Target);	//moves.cpp
  int GenerateNextCapture(Reset *Target);	//moves.cpp
  void TestSafety(int Color, unsigned long long int SafeSquares);//test_safe.cpp
  int ScoreResetMaterialOnly();	//score.cpp
  int GameNotOver();			//reset.cpp
  int WhiteToMove();			//reset.cpp
  int FullHashesMatch(Reset *Candidate);	//reset.cpp
  int ChildrenMatch(Reset *Candidate);	//reset.cpp
  int ResetMatches(Reset *Candidate);	//reset.cpp
  void GetAlgebraicNotation(Reset *Parent, char Text[]);	//io.cpp
  void CopyReset(Reset *Target);	//reset.cpp
};


