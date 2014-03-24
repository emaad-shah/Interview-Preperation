//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Returns the nth fibonacci number recursively
//------------------------------------------------------------

public class fibonacci 
{
	// Recursively return the nth fibonacci number
	public static int fib(int n)
	{
		// Base Case
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		
		return fib(n-1) + fib(n-2);
	}
	
	public static void main(String args[])
	{
		// Return the first 10 fibonacci numbers
		for (int i = 0; i < 10; i++)
			System.out.println(fib(i));
	}

}
