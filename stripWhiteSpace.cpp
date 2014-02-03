//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Strip whitespace from a string in-place
//------------------------------------------------------------

#include <iostream>
#include <string.h>

using namespace std;

// Strip all white spaces
void stripWhiteSpace(char *word)
{
	int len = strlen(word);
	int find;
	for (int i = 0; i < len - 1; i++)
	{
		// Locate white space
		if (word[i] == ' ')
		{
			find = i;
			// Find the next letter
			while (word[find] == ' '&& find < len)
			{
				find++;
			}
			// Swap
			word[i] = word[find];
			word[find] = ' ';
		}
	}
}

int main(void)
{
	// Test Cases
	char word[] = "I s";
	char word2[] = "Th e r e";
	char word3[] = "a";
	char word4[] = "s pac e?";

	cout << word << endl;
	stripWhiteSpace(word);
	cout << word << endl << endl;

	cout << word2 << endl;
	stripWhiteSpace(word2);
	cout << word2 << endl << endl;

	cout << word3 << endl;
	stripWhiteSpace(word3);
	cout << word3 << endl << endl;

	cout << word4 << endl;
	stripWhiteSpace(word4);
	cout << word4 << endl << endl;

	system("pause");
	return 0;
}
