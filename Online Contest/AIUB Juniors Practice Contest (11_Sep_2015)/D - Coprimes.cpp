// D - Coprimes.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
typedef long long ll;
using namespace std;

inline int coprime(int N)
{
	double result = N;   // Initialize result as n
						 //int sqrtN = int(sqrt((double)n));
						 // Consider all prime factors of n and for every prime
						 // factor p, multiply result with (1 - 1/p)
	int p;
	// p * p <= n is almost 3 times faster than p <= sqrtN
	for (p = 2; p * p <= N; ++p) {
		// Check if i is a prime factor.
		if (N % p == 0) {
			// If yes, then update n and result
			while (N % p == 0)
				N /= p;
			result *= (1 - (1 / (double)p));
		}
	}
	// If n has a prime factor greater than sqrt(n)
	// (There can be at-most one such prime factor)
	if (N > 1)
		result *= (1 - (1 / (double)N));
	return (int)result;
}


int main()
{
	int N;
	while (scanf("%d", &N) != EOF) {
		printf("%d\n", coprime(N));
	}
	return 0;
}