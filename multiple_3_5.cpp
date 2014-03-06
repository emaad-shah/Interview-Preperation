//------------------------------------------------------------
// Copyright: Syed Shah 2014
// If we list all the natural numbers below 10 that are 
// multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these 
// multiples is 23. Find the sum of all the multiples of 3 or 
// 5 below 1000.
//------------------------------------------------------------

#include <iostream>
using namespace std;

int main(void)
{
	// Multiple of 3 and 5 below 1000
	int limit = 1000;
	int sum = 0;
	for (int i = 1; i < limit; i++)
	{
		// Check of multiple of 3
		if (i % 3 == 0)
			sum += i;
		// Check for multiple of 5
		else if (i % 5 == 0)
			sum += i;
	}
	cout << "The sum of these multiples is " << sum << endl;

	system("pause");
	return 0;
}

