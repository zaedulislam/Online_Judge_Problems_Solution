// UVa 10179 - Irreducable Basic Fractions.cpp
// Direct application of Euler’s Phi function
// C++ program to calculate Euler's Totient Function
// using Euler's product formula

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int eulerPhi(int n)
{
	double result = n;   // Initialize result as n
	//int sqrtN = int(sqrt((double)n));
	// Consider all prime factors of n and for every prime
	// factor p, multiply result with (1 - 1/p)
	int p;
	// p * p <= n is almost 3 times faster than p <= sqrtN
	for (p = 2; p * p <= n; ++p){
		// Check if i is a prime factor.
		if (n % p == 0){
			// If yes, then update n and result
			while (n % p == 0)
				n /= p;
			result *= (1 - (1 / (double)p));
		}
	}

	// If n has a prime factor greater than sqrt(n)
	// (There can be at-most one such prime factor)
	if (n > 1)
		result *= (1 - (1 / (double)n));
	return (int)result;
}

// Driver program to test above function
int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0)
			break;
		printf("%d\n", eulerPhi(n));
	}
	return 0;
}
