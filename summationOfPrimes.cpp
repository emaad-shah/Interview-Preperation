//------------------------------------------------------------
// Copyright: Syed Shah 2014
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
//------------------------------------------------------------

#include <iostream>
using namespace std;

int main(void)
{
	const int limit = 2000001;
	// Stores sum of all the primes below two million
	long long int sum = 0;
	// Bool array of 2 million
	bool *prime = new bool[limit];
	// Initialize the bool array
	for (int i = 0; i < limit; i++)
		prime[i] = false;
	
	// Initially, let p equal 2, the first prime number.
	int p = 2;
	int i;

	// Starting from p, enumerate its multiples by counting 
	// to n in increments of p, and mark them in the array
	// (these will be 2p, 3p, 4p, etc.; the p itself should 
	// not be marked).
	while (p < limit)
	{
		if (prime[p] == false)
		{
			i = 2;
			while (i*p < limit)
			{
				prime[i*p] = true;
				i++;
			}
			//cout << p << endl;
			sum = sum + p;
		}
		p++;
	}
	cout << "Sum of primes below 2 million: " << sum << endl;
	system("pause");
	return 0;
}

