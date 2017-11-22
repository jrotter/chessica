#include "test_reset.h"


// Setup method
void TestReset::setUp() {
}
 
// Teardown method
void TestReset::tearDown() {
}

void TestReset::VerifyMoveCount(Reset *parent, int MoveCount)
{
  Reset child;
  int count = 0;

  parent->InitializeMoveGeneration();
  parent->InitMyChild(&child);
  while (parent->GenerateNextMove(&child))
    count++;
  CPPUNIT_ASSERT(count == MoveCount);
}

void TestReset::VerifySingleMove(Reset *parent, Reset *child, const char *from, const char *to, const char *infen)
{
  char myfen[100];

  CPPUNIT_ASSERT(parent->GenerateSingleMove(child,from,to));
  child->ConvertToFEN(myfen);
  CPPUNIT_ASSERT(strcmp(myfen,infen) == 0);
}

void TestReset::testReset_WhiteOpeningMoves() {
  Reset x, y;
  int found;

  x.bInitToFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 0");
  VerifyMoveCount(&x,20);
  VerifySingleMove(&x,&y,"a2","a3","rnbqkbnr/pppppppp/8/8/8/P7/1PPPPPPP/RNBQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"a2","a4","rnbqkbnr/pppppppp/8/8/P7/8/1PPPPPPP/RNBQKBNR b KQkq a4 0 0");
  VerifySingleMove(&x,&y,"b2","b3","rnbqkbnr/pppppppp/8/8/8/1P6/P1PPPPPP/RNBQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"b2","b4","rnbqkbnr/pppppppp/8/8/1P6/8/P1PPPPPP/RNBQKBNR b KQkq b4 0 0");
  VerifySingleMove(&x,&y,"c2","c3","rnbqkbnr/pppppppp/8/8/8/2P5/PP1PPPPP/RNBQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"c2","c4","rnbqkbnr/pppppppp/8/8/2P5/8/PP1PPPPP/RNBQKBNR b KQkq c4 0 0");
  VerifySingleMove(&x,&y,"d2","d3","rnbqkbnr/pppppppp/8/8/8/3P4/PPP1PPPP/RNBQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"d2","d4","rnbqkbnr/pppppppp/8/8/3P4/8/PPP1PPPP/RNBQKBNR b KQkq d4 0 0");
  VerifySingleMove(&x,&y,"e2","e3","rnbqkbnr/pppppppp/8/8/8/4P3/PPPP1PPP/RNBQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"e2","e4","rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e4 0 0");
  VerifySingleMove(&x,&y,"f2","f3","rnbqkbnr/pppppppp/8/8/8/5P2/PPPPP1PP/RNBQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"f2","f4","rnbqkbnr/pppppppp/8/8/5P2/8/PPPPP1PP/RNBQKBNR b KQkq f4 0 0");
  VerifySingleMove(&x,&y,"g2","g3","rnbqkbnr/pppppppp/8/8/8/6P1/PPPPPP1P/RNBQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"g2","g4","rnbqkbnr/pppppppp/8/8/6P1/8/PPPPPP1P/RNBQKBNR b KQkq g4 0 0");
  VerifySingleMove(&x,&y,"h2","h3","rnbqkbnr/pppppppp/8/8/8/7P/PPPPPPP1/RNBQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"h2","h4","rnbqkbnr/pppppppp/8/8/7P/8/PPPPPPP1/RNBQKBNR b KQkq h4 0 0");
  VerifySingleMove(&x,&y,"b1","a3","rnbqkbnr/pppppppp/8/8/8/N7/PPPPPPPP/R1BQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"b1","c3","rnbqkbnr/pppppppp/8/8/8/2N5/PPPPPPPP/R1BQKBNR b KQkq - 0 0");
  VerifySingleMove(&x,&y,"g1","f3","rnbqkbnr/pppppppp/8/8/8/5N2/PPPPPPPP/RNBQKB1R b KQkq - 0 0");
  VerifySingleMove(&x,&y,"g1","h3","rnbqkbnr/pppppppp/8/8/8/7N/PPPPPPPP/RNBQKB1R b KQkq - 0 0");
}
 
void TestReset::testReset_FischerSpassky1972_1() {
  Reset x, y;
  x.bInitToFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 0");
  VerifySingleMove(&x,&y,"d2","d4","rnbqkbnr/pppppppp/8/8/3P4/8/PPP1PPPP/RNBQKBNR b KQkq d4 0 0");
  VerifySingleMove(&y,&x,"g8","f6","rnbqkb1r/pppppppp/5n2/8/3P4/8/PPP1PPPP/RNBQKBNR w KQkq - 0 0");
  VerifySingleMove(&x,&y,"c2","c4","rnbqkb1r/pppppppp/5n2/8/2PP4/8/PP2PPPP/RNBQKBNR b KQkq c4 0 0");
  VerifySingleMove(&y,&x,"e7","e6","rnbqkb1r/pppp1ppp/4pn2/8/2PP4/8/PP2PPPP/RNBQKBNR w KQkq - 0 0");
  VerifySingleMove(&x,&y,"g1","f3","rnbqkb1r/pppp1ppp/4pn2/8/2PP4/5N2/PP2PPPP/RNBQKB1R b KQkq - 0 0");
  VerifySingleMove(&y,&x,"d7","d5","rnbqkb1r/ppp2ppp/4pn2/3p4/2PP4/5N2/PP2PPPP/RNBQKB1R w KQkq d5 0 0");
  VerifySingleMove(&x,&y,"b1","c3","rnbqkb1r/ppp2ppp/4pn2/3p4/2PP4/2N2N2/PP2PPPP/R1BQKB1R b KQkq - 0 0");
  VerifySingleMove(&y,&x,"f8","b4","rnbqk2r/ppp2ppp/4pn2/3p4/1bPP4/2N2N2/PP2PPPP/R1BQKB1R w KQkq - 0 0");
  VerifySingleMove(&x,&y,"e2","e3","rnbqk2r/ppp2ppp/4pn2/3p4/1bPP4/2N1PN2/PP3PPP/R1BQKB1R b KQkq - 0 0");
  VerifySingleMove(&y,&x,"e8","g8","rnbq1rk1/ppp2ppp/4pn2/3p4/1bPP4/2N1PN2/PP3PPP/R1BQKB1R w KQ - 0 0");
  VerifySingleMove(&x,&y,"f1","d3","rnbq1rk1/ppp2ppp/4pn2/3p4/1bPP4/2NBPN2/PP3PPP/R1BQK2R b KQ - 0 0");
  VerifySingleMove(&y,&x,"c7","c5","rnbq1rk1/pp3ppp/4pn2/2pp4/1bPP4/2NBPN2/PP3PPP/R1BQK2R w KQ c5 0 0");

}
