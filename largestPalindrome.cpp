// Work currently in progress
/*
string -> f -> largest palindrome within that string

f("abbacheese") -> "abba"
f("adbacheese") -> "ese"
f("abcdefghij") -> "a" OR "b" OR "c" OR ... OR "j"
f("a") -> "a"
f("aabb") -> "aa" OR "bb"
*/

//f("abba") -> "abba"
#include <iostream>
#include <string>

using namespace std;

string palindrome(const char *input, const int size, int i, int j)
{
	string output = "";
	int l = i;
	int r = j;
	int stop = r - l;
	while (r >= stop)
	{
		if (input[r] == input[l])
			output = output + input[r];
		r--;
		l++;
	}
	return output;
}

int main()
{
	char input[] = "abbacheeseabbaasrttrsa";
	int size = strlen(input);
	string output = "";
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			string tmp = palindrome(input, size, i, j);
			if (tmp.length() > output.length())
				output = tmp;
		}
	}
	cout << "The longest palindrome is " << output << endl;
	
	system("pause");
	return 0;
}
