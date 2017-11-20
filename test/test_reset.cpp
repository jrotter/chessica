#include "test_reset.h"


// Setup method
void TestReset::setUp() {
}
 
// Teardown method
void TestReset::tearDown() {
}

void TestReset::testReset_WhiteOpeningMoves() {
  Reset x, y, z;
  int found;
  x.bInitToFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

  found = x.GenerateSingleMove(&y,"a2","a3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"a2","a4");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"b2","b3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"b2","b4");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"c2","c3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"c2","c4");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"d2","d3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"d2","d4");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"e2","e3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"e2","e4");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"f2","f3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"f2","f4");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"g2","g3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"g2","g4");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"h2","h3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"h2","h4");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"b1","a3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"b1","c3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"g1","f3");
  CPPUNIT_ASSERT(found);
  found = x.GenerateSingleMove(&y,"g1","h3");
  CPPUNIT_ASSERT(found);

}
 
void TestReset::testReset_test2() {
  Reset & a = *new Reset;
  Reset & b = *new Reset;
  double a2 = 8, b2 = 8, e2=16, c2=4, d2=16, f2=20; // 2x + 8y = 16; 4x + 16y = 20
  CPPUNIT_ASSERT( a2 == b2 );
}
