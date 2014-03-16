//------------------------------------------------------------
// Copyright:    Syed Shah 2014
//		 Find n missing numbers from a given file
//------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <math.h>
#include <bitset>

using namespace std;

// Maximum integers in a given file
const int size = 999999;

// Read a file and store the integers in a bit array
bool readFile(const string &fileName, bitset<size> & b, int & max)
{
	int num;
	ifstream file;
	file.open(fileName);
	if (!file)
	{
		cerr << "Failed to open the file";
		return false;
	}

	while (!file.eof())
	{
		file >> num;
		// Find maximum number in the file
		if (num > max)
			max = num;
		if (b[num] == 0)
			b[num] = 1;
	}
	file.close();
	return true;
}

// Initialize the bitset array
void initializeArray(bitset<size> & b)
{
	for (int i = 0; i < size; i++)
		b[i] = 0;
}

// Display all missing numbers
void missingNumber(bitset<size> & b, const int & max)
{
	for (int i = 0; i < max; i++)
	{
		if (b[i] == false)
			cout << i << endl;
	}
}

int main(void)
{
	int max = 0;
	string fileName = "missingNumber.txt";
	// Bitset array
	bitset<size> b;
	// Initialize the bitset array
	initializeArray(b);
	// Read the text file and store the integers 	
	readFile(fileName, b, max);
	// Display all missing numbers
	missingNumber(b, max);

	system("pause");
	return 0;
}
