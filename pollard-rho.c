/*
 * Ported GeeksforGeeks Pollard-Rho to run with C90 compiler
 */

#include "rsa.h"

/* Function to calculate (base^exponent)%modulus */
long long unsigned int modular_pow(long long unsigned int base, int exponent,
				   long long unsigned int modulus)
{ 
	/* initialize result */
	long long unsigned int result = 1; 

	while (exponent > 0) 
	{ 
		/* if y is odd, multiply base with result */
		if (exponent & 1) 
			result = (result * base) % modulus; 

		/* exponent = exponent/2 */
		exponent = exponent >> 1; 

		/* base = base * base */
		base = (base * base) % modulus; 
	} 
	return result; 
} 

long long unsigned int __gcd(long long unsigned int a, long long unsigned int b)
{
	if (b == 0)
		return a;

	else
		return __gcd(b, a%b);
}

/* method to return prime divisor for n */
long long unsigned int PollardRho(long long unsigned int n) 
{ 
	/* initialize random seed */
	srand (time(NULL)); 

	/* no prime divisor for 1 */
	if (n==1)
		return n; 

	/* even number means one of the divisors is 2 */
	if (n % 2 == 0)
		return 2; 

	/* we will pick from the range [2, N) */
	long long unsigned int x = (rand()%(n-2))+2; 
	long long unsigned int y = x; 

	/* the constant in f(x). 
	* Algorithm can be re-run with a different c 
	* if it throws failure for a composite. */
	long long unsigned int c = (rand()%(n-1))+1; 

	/* Initialize candidate divisor (or result) */
	long long unsigned int d = 1; 

	/* until the prime factor isn't obtained. 
	If n is prime, return n */
	while (d==1) 
	{ 
		/* Tortoise Move: x(i+1) = f(x(i)) */
		x = (modular_pow(x, 2, n) + c + n)%n; 

		/* Hare Move: y(i+1) = f(f(y(i))) */
		y = (modular_pow(y, 2, n) + c + n)%n; 
		y = (modular_pow(y, 2, n) + c + n)%n; 

		/* check gcd of |x-y| and n */
		d = __gcd(abs(x-y), n); 

		/* retry if the algorithm fails to find prime factor 
		* with chosen x and c */
		if (d==n)
			return PollardRho(n); 
	} 

	return d; 
} 
