#include <iostream>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>
 
#include "test_reset.h"
 
using namespace std;
 
int main() {
	CppUnit::TextUi::TestRunner runner;
 
	cout << "Creating Test Suites:" << endl;
	runner.addTest(TestReset::suite());
	cout<< "Running the unit tests."<<endl;
	runner.run();
 
	return 0;
}
