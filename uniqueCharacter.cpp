//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Determine if a string has all unique characters
//------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

// Determine unique characters using hash map
bool isUniqueHash(const string & str)
{
	// All posible ASCII characters
	int dict[128];
	// Initialize hash array
	for (int i = 0; i < 128; i++)
		dict[i] = 0;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		dict[str[i]] += 1;
		// Check if the character is already mapped
		if (dict[str[i]] == 2)
			return false;
	}
	return true;
}

// Determine unique characters using brute force
bool isUnique(const string & str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		for (unsigned int j = i + 1; j < str.length(); j++)
		{
			if (str[i] == str[j])
				return false;
		}
	}
	return true;
}

int main(void)
{
	string str = "*Ema*d";
	bool unique = isUniqueHash(str);

	// Test Hash Map method
	if (unique)
		cout << str << " is unique" << endl;
	else
		cout << str << " is not unique" << endl;

	// Test Brute Force method
	unique = isUnique(str);
	if (unique)
		cout << str << " is unique" << endl;
	else
		cout << str << " is not unique" << endl;

	system("pause");
	return 0;
}
