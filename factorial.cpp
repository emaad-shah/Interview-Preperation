//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Factorial: Iterative and recursive factorial function
//------------------------------------------------------------

#include <iostream>
using namespace std;

// Iterative factorial
int factorial(int f)
{
	// Check for negative numbers
	if (f < 1)
		return 0;
	int fac = 1;
	// Calculate factorial
	while (f > 0)
	{
		fac = fac * f--;
	}
	return fac;
}

// Recursive Factorial
int factorialR(int f)
{
	// Base Case
	if (f <= 0)
		return 0;
	else if (f == 1)
		return 1;
	// Recursive call 
	return f * factorialR(f - 1);
}

int main(void)
{
	// Test the iterative and the recursive factorial function
	for (int i = -2; i < 5; i++)
		cout << "Factorial of " << i << " (Iterative: " << factorial(i)
		<< " , Recursive: " << factorialR(i) << ")" << endl;

	system("pause");
	return 0;
}
