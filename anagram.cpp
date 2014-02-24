//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Find largest palindrome within that string
//------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

string palindrome(const char *input, const int size, int i, int j)
{
	string output = "";
	int l = i;
	int r = j;
	while (l <= j)
	{
		if (input[r] == input[l])
			output = output + input[r];
		else
			return "";
		r--;
		l++;
	}
	return output;
}

void findAndDisplay(const char *input, int size)
{
	string output = "";
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			string tmp = palindrome(input, size, i, j);
			if (tmp.length() > output.length())
				output = tmp;
		}
	}
	if (!output.empty())
		cout << "The longest palindrome in "
		<< input << " is " << output << endl;
	else
		cout << "The string " << input << " does not"
			    " contain a palindrome" << endl;
	cout << endl;
}

int main(void)
{
	// Test 1
	char input[] = "abbacheese";
	int size = strlen(input);
	findAndDisplay(input, size);
	// Test 2
	char input2[] = "adbacheese";
	size = strlen(input2);
	findAndDisplay(input2, size);
	// Test 3
	char input3[] = "abcdefghij";
	size = strlen(input3);
	findAndDisplay(input3, size);
	// Test 4
	char input4[] = "a";
	size = strlen(input4);
	findAndDisplay(input4, size);
	// Test 5
	char input5[] = "aabb";
	size = strlen(input5);
	findAndDisplay(input5, size);
	// Test 6
	char input6[] = "abba";
	size = strlen(input6);
	findAndDisplay(input6, size);

	system("pause");
	return 0;
}
