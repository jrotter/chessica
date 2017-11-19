#ifndef testchess_h__
#define testchess_h__

#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
 
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
 
    suiteOfTests->addTest(new CppUnit::TestCaller<TestReset>("Test1 - Something.", &TestReset::testReset_test1 ));
 
    suiteOfTests->addTest(new CppUnit::TestCaller<TestReset>("Test2 - Something Else.", &TestReset::testReset_test2 ));
 
    return suiteOfTests;
  }

 
  /// Setup method
  void setUp();
 
  /// Teardown method
  void tearDown();
 
protected:
  void testReset_test1();
  void testReset_test2();

};

#endif  //testchess_h__
