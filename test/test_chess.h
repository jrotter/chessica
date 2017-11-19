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
 
		suiteOfTests->addTest(new CppUnit::TestCaller<TestReset>("Test1 - Something.",
				&TestReset::testReset_test1 ));
 
		suiteOfTests->addTest(new CppUnit::TestCaller<TestReset>("Test2 - Something Else.",
				&TestReset::testReset_test2 ));
 
		return suiteOfTests;
	}
 
	/// Setup method
	void setUp() {}
 
	/// Teardown method
	void tearDown() {}
 
protected:
	void testReset_test1() {
		// Should work since we can solve this easily by hand.
		double a = 2, b = 8, e = 16, c = 4, d = -8, f = 2; // 2x + 8y = 16; 4x -8y = 2
		CPPUNIT_ASSERT( a!=b );
	}
 
	void testReset_test2() {
		double a2 = 8, b2 = 8, e2=16, c2=4, d2=16, f2=20; // 2x + 8y = 16; 4x + 16y = 20
		CPPUNIT_ASSERT( a2 == b2 );
	}
};

#endif  //testchess_h__
