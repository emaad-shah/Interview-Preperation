//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Find the sum of the nth fibonacci number
//------------------------------------------------------------

#include <iostream>

using namespace std;

// Return (n + 2)th integer in the sequence
int getN(const int & n1, const int & n2)
{
	return n1 + n2 + n2;
}

// Sum of nth fibonacci number is s(n) = f(n + 2) - 1
// f(n + 2) is always one number greater than the actual sum
void getFib(const int & n, const int * fib, const int & length)
{
	// Base Case, Only one element in the array
	if (n == 1)
		cout << fib[0] << endl;;
	// Nth number must exist in the array
	if (n <= length)
		cout << getN(fib[n-2], fib[n-1]) - 1 << endl;

	// Boundry Value Analyses
	if (n < 1 || n > length)
		cerr << "Invalid entry" << endl;
}

int main(void)
{
	int fib[] = {1,1,2,3,5,8};
	int length = sizeof(fib) / sizeof(*fib);
	int n = 4;

	// Test 1
	cout << "Sum of first " << n << " numbers in the fibonacci sequence: ";
	getFib(n, fib, length);

	system("pause");
	return 0;
}
