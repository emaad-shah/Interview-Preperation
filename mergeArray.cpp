//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Merge two sorted arrays
//------------------------------------------------------------


#include <iostream>

using namespace std;

// Merges two sorted array
int* merge(int* array1, int* array2, int sizeA1, int sizeA2)
{
	int size = sizeA1 + sizeA2;
	// Allocating memory for the new int array
	int *result = new int[size];
	// Iterator for array 1
	int i = 0;
	// Iterator for array 2
	int j = 0;
	int counter = 0;

	while (i < sizeA1 && j < sizeA2)
	{
		// Compare the elements in both array
		if (array1[i] <= array2[j])
		{
			result[counter++] = array1[i++];
		}
		else
		{
			result[counter++] = array2[j++];
		}
	}

	if (i < sizeA1)
	{
		for (int k = i; k < sizeA1; k++)
		{
			result[counter++] = array1[k];
			j++;
		}
	}
	else
	{
		for (int k = j; k < sizeA2; k++)
		{
			result[counter++] = array2[k];
			i++;
		}
	}

	return result;
}

int main(void)
{
	// First test
	int sizeA1 = 2;
	int sizeA2 = 3;
	int *a1 = new int[sizeA1];
	int *a2 = new int[sizeA2];
	int *a3 = new int[sizeA1 + sizeA2];
	a1[0] = 1;
	a1[1] = 5;
	a2[0] = 2;
	a2[1] = 10;
	a2[2] = 18;
	a3 = merge(a1, a2, sizeA1, sizeA2);

	for (int i = 0; i < (sizeA1 + sizeA2); i++)
	{
		cout << a3[i] << " ";
	}
	cout << endl << endl;

	// Second test
	sizeA1 = 4;
	sizeA2 = 3;
	int *a4 = new int[sizeA1];
	int *a5 = new int[sizeA2];
	int *a6 = new int[sizeA1 + sizeA2];
	a4[0] = 1;
	a4[1] = 10;
	a4[2] = 20;
	a4[3] = 40;
	a5[0] = 5;
	a5[1] = 15;
	a5[2] = 25;
	a6 = merge(a4, a5, sizeA1, sizeA2);

	cout << "Merging new array" << endl;
	for (int i = 0; i < (sizeA1 + sizeA2); i++)
	{
		cout << a6[i] << " ";
	}

	delete[]a1;
	delete[]a2;
	delete[]a3;
	delete[]a4;
	delete[]a5;
	delete[]a6;

	system("pause");
	return 0;
}
