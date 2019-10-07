#ifndef test_reset_h__
#define test_reset_h__

#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
 
#include "common.h"
#include "reset.h"
 
using namespace std;
 
class TestReset : public CppUnit::TestFixture {
private:
  Reset *testReset;
public:
  TestReset() : testReset(NULL) {}
  virtual ~TestReset() {
    delete testReset;
  }
 
  static CppUnit::Test *suite() {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestReset");
 
    suiteOfTests->addTest(new CppUnit::TestCaller<TestReset>("White Opening Moves", &TestReset::testReset_WhiteOpeningMoves ));
 
    suiteOfTests->addTest(new CppUnit::TestCaller<TestReset>("Fischer-Spassky, 1972 World Championship Game 1", &TestReset::testReset_FischerSpassky1972_1 ));
 
    return suiteOfTests;
  }

 
  /// Setup method
  void setUp();
 
  /// Teardown method
  void tearDown();
 
protected:
  // Helpers
  void VerifySingleMove(Reset *parent, Reset *child, const char *from, const char *to, const char *fen);
  void VerifyMoveCount(Reset *parent, int MoveCount);

  // Tests
  void testReset_WhiteOpeningMoves();
  void testReset_FischerSpassky1972_1();

};

#endif  //test_reset_h__
