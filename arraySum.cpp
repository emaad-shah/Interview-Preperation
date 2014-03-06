//------------------------------------------------------------
// Copyright: Syed Shah 2013
// In this challenge, given an array of integers, the goal is 
// to efficiently find the subarray that has the greatest  
// value when all of its elements are summed together. Note 
// that  because some elements of the array may be negative,  
// the problem is not solved by simply picking the start and 
// end elements of the array to be the subarrray, and summing  
// the entire array.
//------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using namespace std;

int main(void)
{
	// Ensure the random numbers are unique
	srand(time(NULL));
	// Randomly generate size of the int array
	int size = rand() % 10 + 1;
	// Dynamic Integer array 
	int *arraySum = new int[size];
	cout << "Randomly Generated Array:";

	for (int i = 0; i < size; i++)
	{
		// Generate random number between -10 and 10
		arraySum[i] = rand() % 21 - 10;
		// Set width of 4 and display the array
		cout << fixed << setw(4) << arraySum[i];
	}
	cout << endl;
	
	int best = 0;
	int current = 0;
	for (int i = 0; i < size; i++)
	{
		current = current + arraySum[i];
		// Reset if negative number encountered
		if (current < 0)
			current = 0;
		if (best < current)
			best = current;
	}
	
	cout << "The value of the biggest sub array is " << best << endl;
	// Deallocate memory
	delete[] arraySum;
	system("pause");
	return 0;
}
