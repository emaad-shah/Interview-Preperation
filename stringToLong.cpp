//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Given a string, write a routine that converts the string to 
// a long, without using the built in functions that would do 
// this. Describe what(if any) limitations the code has
//
// Limitations: Compiler may throw a warning/error for values
//		outside the range of -2147483647 to 2147483647
//
//
// Assumptions	If the first index of the string contains a 
//		'-' symbol, the program will assume that a 
//		string contains a negative number
//
//		All non-integers except a possible negative 
//		sign at the first index of the string will be
//		ignored
//------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// Converts a string to long and 
// returns it to the user
long stringToLong(const string & s)
{
	// Length of the string
	int len = s.length();
	long output = 0;
	// Ascii code
	int ascii_begin = 48;
	int ascii_end = 57;
	for (long i = 0; i < len; i++)
	{  
		// Ignore all non-integers
		if (s[i] >= ascii_begin && s[i] <= ascii_end)
		{
			output = output * 10 + (s[i] - '0');
		}
	}
	// Deal with negative numbers
	if (s[0] == '-')
		output = output * -1;
	return output;
}

void test(const string & s, long input)
{
	long output = stringToLong(s);
	if (input == output)
		cout << "Sucess" << endl;
	else
		cout << "Failiure" << endl;
}

int main(void)
{
	// Test Cases: Checking normal string
	test("123", 123);
	test("123456789", 123456789);
	// Test Cases: Checking string with spaces
	test("  123", 123);
	test("123  ", 123);
	// Test Cases: Checking string seperated by comma
	test("1,2,3", 123);
	// Test Cases: Checking empty string
	test("",0);
	test("", 1);
	// Test Cases: Checking string with different symbols
	test("123123,.++2~11", 123123211);
	// Test Cases: Checking limitations of long
	test("-2147483647", -2147483647);
	// Other Test Cases
	test("Hello World", 1234);
	test("+123", 123);

	system("pause");
	return 0;
}
