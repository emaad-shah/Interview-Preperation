//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Check two anagrams
//------------------------------------------------------------

#include <iostream>

using namespace std;

// Hash Function
int hashFunction(char l, int p)
{
	return l % p;
}

// Checks if two words are anagrams
bool isAnagram(char* w1, char * w2, int size1, int size2)
{
	if (size1 != size2)
		return false;

	// Size of the hash table (a - z)
	int p = 26;
	// Hash Table
	int dictionary[26];
	// Index of the hash table
	int index = 0;

	// Initialize the dictionary
	for (int i = 0; i < 26; i++)
		dictionary[i] = 0;

	// Big O(N)
	for (int i = 0; i < size1; i++)
	{
		index = hashFunction(w1[i] - 97, p);
		dictionary[index] = dictionary[index] + 1;

		index = hashFunction(w2[i] - 97, p);
		dictionary[index] = dictionary[index] + 1;
	}

	// If anagrams, each table element should have 2 letters
	for (int i = 0; i < p; i++)
	{
		if (dictionary[i] % 2 != 0)
			return false;
	}

	return true;
}

// Displays anagrams
void display(bool cond, char *w1, char *w2)
{
	if (cond == true)
		cout << w1 << " and " << w2 << " are anagram of each other" << endl << endl;
	else
		cout << w1 << " and " << w2 << " are not anagram of each other" << endl << endl;
}

int main(void)
{
	// Test 1
	char w1[7] = "looped";
	char w2[7] = "poodle";
	int size1 = sizeof(w1) / sizeof(*w1) - 1;
	int size2 = sizeof(w2) / sizeof(*w2) - 1;
	bool cond = isAnagram(w1, w2, size1, size2);
	display(cond, w1, w2);
	// Test 2
	char w3[5] = "bats";
	char w4[5] = "stab";
	size1 = sizeof(w3) / sizeof(*w3) - 1;
	size2 = sizeof(w4) / sizeof(*w4) - 1;
	cond = isAnagram(w3, w4, size1, size2);
	display(cond, w3, w4);
	// Test 3
	char w5[7] = "banana";
	char w6[6] = "apple";
	size1 = sizeof(w5) / sizeof(*w5) - 1;
	size2 = sizeof(w6) / sizeof(*w6) - 1;
	cond = isAnagram(w5, w6, size1, size2);
	display(cond, w5, w6);


	system("pause");
	return 0;
}
