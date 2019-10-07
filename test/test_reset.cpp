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

  printf("\nEvaluating move count (expecting %d):\n",MoveCount);
  parent->PrintSmallBoard();
  parent->InitializeMoveGeneration();
  parent->InitMyChild(&child);
  while (parent->GenerateNextMove(&child))
    count++;
  CPPUNIT_ASSERT(count == MoveCount);
}

void TestReset::VerifySingleMove(Reset *parent, Reset *child, const char *from, const char *to, const char *infen)
{
  char myfen[100];

  printf("\nEvaluating move %s to %s\n",from,to);
  printf("Parent:\n");
  parent->PrintSmallBoard();
  CPPUNIT_ASSERT(parent->GenerateSingleMove(child,from,to));
  printf("Child:\n");
  child->PrintSmallBoard();
  CPPUNIT_ASSERT(parent->GenerateSingleMove(child,from,to));
  child->ConvertToFEN(myfen);
  CPPUNIT_ASSERT(strcmp(myfen,infen) == 0);
  printf("\n");
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
  VerifySingleMove(&x,&y,"e1","g1","rnbq1rk1/pp3ppp/4pn2/2pp4/1bPP4/2NBPN2/PP3PPP/R1BQ1RK1 b - - 0 0");
  VerifySingleMove(&y,&x,"b8","c6","r1bq1rk1/pp3ppp/2n1pn2/2pp4/1bPP4/2NBPN2/PP3PPP/R1BQ1RK1 w - - 0 0");
  VerifySingleMove(&x,&y,"a2","a3","r1bq1rk1/pp3ppp/2n1pn2/2pp4/1bPP4/P1NBPN2/1P3PPP/R1BQ1RK1 b - - 0 0");
  VerifySingleMove(&y,&x,"b4","a5","r1bq1rk1/pp3ppp/2n1pn2/b1pp4/2PP4/P1NBPN2/1P3PPP/R1BQ1RK1 w - - 0 0");
  VerifySingleMove(&x,&y,"c3","e2","r1bq1rk1/pp3ppp/2n1pn2/b1pp4/2PP4/P2BPN2/1P2NPPP/R1BQ1RK1 b - - 0 0");
  VerifySingleMove(&y,&x,"d5","c4","r1bq1rk1/pp3ppp/2n1pn2/b1p5/2pP4/P2BPN2/1P2NPPP/R1BQ1RK1 w - - 0 0");
  VerifySingleMove(&x,&y,"d3","c4","r1bq1rk1/pp3ppp/2n1pn2/b1p5/2BP4/P3PN2/1P2NPPP/R1BQ1RK1 b - - 0 0");
  VerifySingleMove(&y,&x,"a5","b6","r1bq1rk1/pp3ppp/1bn1pn2/2p5/2BP4/P3PN2/1P2NPPP/R1BQ1RK1 w - - 0 0");
  VerifySingleMove(&x,&y,"d4","c5","r1bq1rk1/pp3ppp/1bn1pn2/2P5/2B5/P3PN2/1P2NPPP/R1BQ1RK1 b - - 0 0");
  VerifySingleMove(&y,&x,"d8","d1","r1b2rk1/pp3ppp/1bn1pn2/2P5/2B5/P3PN2/1P2NPPP/R1Bq1RK1 w - - 0 0");
  VerifySingleMove(&x,&y,"f1","d1","r1b2rk1/pp3ppp/1bn1pn2/2P5/2B5/P3PN2/1P2NPPP/R1BR2K1 b - - 0 0");
  VerifySingleMove(&y,&x,"b6","c5","r1b2rk1/pp3ppp/2n1pn2/2b5/2B5/P3PN2/1P2NPPP/R1BR2K1 w - - 0 0");
  VerifySingleMove(&x,&y,"b2","b4","r1b2rk1/pp3ppp/2n1pn2/2b5/1PB5/P3PN2/4NPPP/R1BR2K1 b - b4 0 0");
  VerifySingleMove(&y,&x,"c5","e7","r1b2rk1/pp2bppp/2n1pn2/8/1PB5/P3PN2/4NPPP/R1BR2K1 w - - 0 0");
  VerifySingleMove(&x,&y,"c1","b2","r1b2rk1/pp2bppp/2n1pn2/8/1PB5/P3PN2/1B2NPPP/R2R2K1 b - - 0 0");
  VerifySingleMove(&y,&x,"c8","d7","r4rk1/pp1bbppp/2n1pn2/8/1PB5/P3PN2/1B2NPPP/R2R2K1 w - - 0 0");
  VerifySingleMove(&x,&y,"a1","c1","r4rk1/pp1bbppp/2n1pn2/8/1PB5/P3PN2/1B2NPPP/2RR2K1 b - - 0 0");
  VerifySingleMove(&y,&x,"f8","d8","r2r2k1/pp1bbppp/2n1pn2/8/1PB5/P3PN2/1B2NPPP/2RR2K1 w - - 0 0");
  VerifySingleMove(&x,&y,"e2","d4","r2r2k1/pp1bbppp/2n1pn2/8/1PBN4/P3PN2/1B3PPP/2RR2K1 b - - 0 0");
  VerifySingleMove(&y,&x,"c6","d4","r2r2k1/pp1bbppp/4pn2/8/1PBn4/P3PN2/1B3PPP/2RR2K1 w - - 0 0");
  VerifySingleMove(&x,&y,"f3","d4","r2r2k1/pp1bbppp/4pn2/8/1PBN4/P3P3/1B3PPP/2RR2K1 b - - 0 0");
  VerifySingleMove(&y,&x,"d7","a4","r2r2k1/pp2bppp/4pn2/8/bPBN4/P3P3/1B3PPP/2RR2K1 w - - 0 0");
  VerifySingleMove(&x,&y,"c4","b3","r2r2k1/pp2bppp/4pn2/8/bP1N4/PB2P3/1B3PPP/2RR2K1 b - - 0 0");
  VerifySingleMove(&y,&x,"a4","b3","r2r2k1/pp2bppp/4pn2/8/1P1N4/Pb2P3/1B3PPP/2RR2K1 w - - 0 0");
  VerifySingleMove(&x,&y,"d4","b3","r2r2k1/pp2bppp/4pn2/8/1P6/PN2P3/1B3PPP/2RR2K1 b - - 0 0");
  VerifySingleMove(&y,&x,"d8","d1","r5k1/pp2bppp/4pn2/8/1P6/PN2P3/1B3PPP/2Rr2K1 w - - 0 0");
  VerifySingleMove(&x,&y,"c1","d1","r5k1/pp2bppp/4pn2/8/1P6/PN2P3/1B3PPP/3R2K1 b - - 0 0");
  VerifySingleMove(&y,&x,"a8","c8","2r3k1/pp2bppp/4pn2/8/1P6/PN2P3/1B3PPP/3R2K1 w - - 0 0");
  VerifySingleMove(&x,&y,"g1","f1","2r3k1/pp2bppp/4pn2/8/1P6/PN2P3/1B3PPP/3R1K2 b - - 0 0");
  VerifySingleMove(&y,&x,"g8","f8","2r2k2/pp2bppp/4pn2/8/1P6/PN2P3/1B3PPP/3R1K2 w - - 0 0");
  VerifySingleMove(&x,&y,"f1","e2","2r2k2/pp2bppp/4pn2/8/1P6/PN2P3/1B2KPPP/3R4 b - - 0 0");
  VerifySingleMove(&y,&x,"f6","e4","2r2k2/pp2bppp/4p3/8/1P2n3/PN2P3/1B2KPPP/3R4 w - - 0 0");
  VerifySingleMove(&x,&y,"d1","c1","2r2k2/pp2bppp/4p3/8/1P2n3/PN2P3/1B2KPPP/2R5 b - - 0 0");
  VerifySingleMove(&y,&x,"c8","c1","5k2/pp2bppp/4p3/8/1P2n3/PN2P3/1B2KPPP/2r5 w - - 0 0");
  VerifySingleMove(&x,&y,"b2","c1","5k2/pp2bppp/4p3/8/1P2n3/PN2P3/4KPPP/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"f7","f6","5k2/pp2b1pp/4pp2/8/1P2n3/PN2P3/4KPPP/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"b3","a5","5k2/pp2b1pp/4pp2/N7/1P2n3/P3P3/4KPPP/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"e4","d6","5k2/pp2b1pp/3npp2/N7/1P6/P3P3/4KPPP/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"e2","d3","5k2/pp2b1pp/3npp2/N7/1P6/P2KP3/5PPP/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"e7","d8","3b1k2/pp4pp/3npp2/N7/1P6/P2KP3/5PPP/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"a5","c4","3b1k2/pp4pp/3npp2/8/1PN5/P2KP3/5PPP/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"d8","c7","5k2/ppb3pp/3npp2/8/1PN5/P2KP3/5PPP/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"c4","d6","5k2/ppb3pp/3Npp2/8/1P6/P2KP3/5PPP/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"c7","d6","5k2/pp4pp/3bpp2/8/1P6/P2KP3/5PPP/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"b4","b5","5k2/pp4pp/3bpp2/1P6/8/P2KP3/5PPP/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"d6","h2","5k2/pp4pp/4pp2/1P6/8/P2KP3/5PPb/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"g2","g3","5k2/pp4pp/4pp2/1P6/8/P2KP1P1/5P1b/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"h7","h5","5k2/pp4p1/4pp2/1P5p/8/P2KP1P1/5P1b/2B5 w - h5 0 0");
  VerifySingleMove(&x,&y,"d3","e2","5k2/pp4p1/4pp2/1P5p/8/P3P1P1/4KP1b/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"h5","h4","5k2/pp4p1/4pp2/1P6/7p/P3P1P1/4KP1b/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"e2","f3","5k2/pp4p1/4pp2/1P6/7p/P3PKP1/5P1b/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"f8","e7","8/pp2k1p1/4pp2/1P6/7p/P3PKP1/5P1b/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"f3","g2","8/pp2k1p1/4pp2/1P6/7p/P3P1P1/5PKb/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"h4","g3","8/pp2k1p1/4pp2/1P6/8/P3P1p1/5PKb/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"f2","g3","8/pp2k1p1/4pp2/1P6/8/P3P1P1/6Kb/2B5 b - - 0 0");
  VerifySingleMove(&y,&x,"h2","g3","8/pp2k1p1/4pp2/1P6/8/P3P1b1/6K1/2B5 w - - 0 0");
  VerifySingleMove(&x,&y,"g2","g3","8/pp2k1p1/4pp2/1P6/8/P3P1K1/8/2B5 b - - 0 0");

}
