//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Checks if a word or a sentence is palindrome
//------------------------------------------------------------

#include <iostream>
using namespace std;

// Change to lower case
void toLower(char *s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] = tolower(s[i]);
	}
}

// Checks if a word is palindrome
bool palindrome(char *s)
{
	toLower(s);
	int size = strlen(s) - 1;
	int l = 0;
	int r = size;
	while (r > (size / 2))
	{
		// Ignore capitals, punctuation, and spaces
		while (!((s[l] > 64 && s[l] < 91) || (s[l] > 96 && s[l] < 123)))
			l++;
		while (!((s[r] > 64 && s[r] < 91) || (s[r] > 96 && s[r] < 123)))
			r--;
		if (s[l] == s[r])
		{
			l++;
			r--;
		}
		else
			return false;

	}
	return true;
}

// Displays palindromes
void display(char *s, bool cond)
{
	for (int i = 0; i < strlen(s); i++)
		cout << s[i];
	if (cond == true)
		cout << ", is a palindrome" << endl << endl;
	else
		cout << ", is not a palindrome" << endl << endl;
}

int main(void)
{
	// Test 1
	char s[] = "Air an aria";
	bool cond =  palindrome(s);
	display(s, cond);

	// Test 2
	char s2[] = "Acrobats stab orca";
	cond = palindrome(s2);
	display(s2, cond);
	
	// Test 3
	char s3[] = "Are Mac ‘n’ Oliver ever evil on camera?";
	cond = palindrome(s3);
	display(s3, cond);

	// Test 4
	char s4[] = "Dont I just love programming?";
	cond = palindrome(s4);
	display(s4, cond);

	// Test 5
	char s5[] = "Tide net safe soon; a noose fastened it";
	cond = palindrome(s5);
	display(s5, cond);

	system("pause");
	return 0;
}
