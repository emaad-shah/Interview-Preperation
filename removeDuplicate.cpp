//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Remove duplicates from string
//------------------------------------------------------------

#include <iostream>
using namespace std;

// Shift all the letters to the left
void shiftLetters(char * szStr, int i, int len)
{
	for (int j = i + 1; j < len; j++)
		szStr[j] = szStr[j + 1];
}

// Remove duplicate lettes from string
void RemoveDups(char* szStr)
{
	// Length of string
	int len = strlen(szStr);

	for (int i = len - 1; i >= 0; i--)
	{
		if (szStr[i] == szStr[i + 1])
		{
			// Mark duplicate letter by white space
			szStr[i+1] = ' ';
			// Shift all the letters to the left
			shiftLetters(szStr, i, len);
		}
	}
}

int main(void)
{
	// Test 1
	char s[] = "Howw arre youu";
	cout << s << endl;
	RemoveDups(s);
	cout << s << endl << endl;

	// Test 2
	char s2[] = "I Loveee CCC";
	cout << s2 << endl;
	RemoveDups(s2);
	cout << s2 << endl << endl;

	// Test 3
	char s3[] = "IIs tthhhis aa dupliccate tooo?";
	cout << s3 << endl;
	RemoveDups(s3);
	cout << s3 << endl;
	system("pause");
	return 0;
}
