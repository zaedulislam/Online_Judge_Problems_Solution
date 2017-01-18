// UVa 11064 - Number Theory.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int eulerPhi(int n)
{
	double result = n; // Initialize result as n
	int tmp = n;
	int numDiv = 1,power;
     //int sqrtN = int(sqrt((double)n));
	// Consider all prime factors of n and for every prime
	// factor p, multiply result with (1 - 1/p)
	
	int p;
	// p * p <= n is almost 3 times faster than p <= sqrtN
	// p * p < = n ??????? is slower
	for (p = 2; p <= n / p; ++p) {
		power = 0;
		// Check if p is a prime factor.
		if (n % p == 0) {                                                                                                                                                                                                                                                                                                                      
		// If  yes, then update n and result.
			while (n % p == 0) {
				n /= p;
				power++;
			}
			numDiv *= (power + 1);
			result *= (1 - (1 / (double)p));
		}
	}
	// If n has a prime factor greater than sqrt(n)
	// (There can be at-most one such prime factor)
	if (n > 1){
		numDiv *= 2;
		result *= (1 - (1 / (double)n));                       
	}
	 int coprime = (int)result;
	 int ans = tmp - coprime - numDiv + 1;
	 return ans;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 1 || n == 2) {
			printf("0\n");
			continue;
		}
		printf("%d\n",eulerPhi(n));
	}
	return 0;
}

