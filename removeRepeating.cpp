//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Given a string, remove repeating character's 
//------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	// Size of the hash table
	const int SIZE = 10000;
	// Hash Array of size 1000
	int dict[SIZE];
	// Initialize the hash table 
	for (int i = 0; i < SIZE; i++)
		dict[i] = 0;

	// Input string
	string input = "*helelloeoeo*";
	// Output string
	string output = "";
	// Length of input string
	int len = input.length();

	for (int i = 0; i < len; i++)
	{
		dict[input[i]] += 1;
		// Add each character once
		if (dict[input[i]] == 1)
			output += input[i];
	}

	cout << output << endl;


	system("pause");
	return 0;
}



