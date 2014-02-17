//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Groups anagrams in an array of words
//------------------------------------------------------------

#include <iostream>

using namespace std;

// Hash Function
int hashFunction(char l, int p)
{
	return l % p;
}

// Hash value of specific word
int hashValue(int *dict, char * word, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum = sum + dict[hashFunction(word[i] - 97, 26)];
	return sum;
}


// Swap Function
template<class T>
void swap(T *&a, T *&b)
{
	T * tmp = a;
	a = b;
	b = tmp;
}

// Quick Sort
void qSort(int * value, char ** anagrams, int left, int right)
{
	int i = left, j = right;
	int pivot = value[(left + right) / 2];

	while (i <= j)
	{
		while (value[i] < pivot)
			i++;
		while (value[j] > pivot)
			j--;
		if (i <= j)
		{
			// Swap
			swap(value[i], value[j]);
			// Now swap the words
			swap(anagrams[i], anagrams[j]);
			j--;
			i++;
		}
	}
	// Recursion
	if (left < j)
		qSort(value, anagrams, left, j);
	if (i < right)
		qSort(value, anagrams, i, right);
}

// Displays the anagrams
void display(char **anagrams, int size)
{
	for (int i = 0; i < size; i++)
		cout << anagrams[i] << "  ";
}

int main(void)
{
	int dictionary[26];
	// Fill in the hash table with random numbers
	for (int i = 0; i < 26; i++)
		dictionary[i] = rand() % 100 + 1;

	char * anagrams[] = {"art", "rat","bats","banana","stab","tar"};
	// Size of the anagrams array
	const int size = sizeof(anagrams) / sizeof(*anagrams);
	// Second array will store the hash value of each word
	int value[size];
	for (int i = 0; i < size; i++)
		value[i] = hashValue(dictionary, anagrams[i], strlen(anagrams[i]));

	int left = 1, right = size - 1;
	// Quick Sort all the anagrams
	qSort(value,anagrams,left,right);

	display(anagrams, size);
	system("pause");
	return 0;
}
