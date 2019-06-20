#include "Header.h"

int Gcd(int a, int b)
{
	if (a == 0)
		return b;

	return Gcd(b%a, a);
}

int Lcm(int a, int b)
{
	return (a*b) / Gcd(a, b);
}

void primeFactors(int n)
{
	// Print the number of 2s that divide n  
	while (n % 2 == 0)
	{
		cout << 2 << " ";
		n = n / 2;
	}

	// n must be odd at this point. So we can skip  
	// one element (Note i = i +2)  
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		//cout << "i: " << i << endl;
		// While i divides n, print i and divide n  
		while (n % i == 0)
		{
			cout << i << " ";
			n = n / i;
		}
	}

	// This condition is to handle the case when n  
	// is a prime number greater than 2  
	if (n > 2)
		cout << n << " ";
}
