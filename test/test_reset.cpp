#include "test_reset.h"


// Setup method
void TestReset::setUp() {
}
 
// Teardown method
void TestReset::tearDown() {
}

void TestReset::testReset_test1() {
  Reset x;
  Reset y;

  x.bInitToFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  x.GenerateNextMove(&y);
  x.PrintBoard();
  double a = 2, b = 8, e = 16, c = 4, d = -8, f = 2; // 2x + 8y = 16; 4x -8y = 2
  CPPUNIT_ASSERT( a==b );
}
 
void TestReset::testReset_test2() {
  Reset & a = *new Reset;
  Reset & b = *new Reset;
  double a2 = 8, b2 = 8, e2=16, c2=4, d2=16, f2=20; // 2x + 8y = 16; 4x + 16y = 20
  CPPUNIT_ASSERT( a2 == b2 );
}
