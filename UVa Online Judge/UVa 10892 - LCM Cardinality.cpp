// UVa 10892 - LCM Cardinality.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

const int arraySize = 1005;
int divisors[arraySize];
int N;

inline int gcd(int a, int b)
{
	int quotient, remainder = -1;
	int divident, divisor;

	if (a > b) {
		divident = a;
		divisor = b;
	}
	else {
		divident = b;
		divisor = a;
	}
	while (remainder != 0) {
		quotient = divident / divisor;
		remainder = divident % divisor;
		divident = divisor;
		divisor = remainder;
	}
	return divident;
}

inline int lcm(int a, int b) 
{
	if ((a / gcd(a, b)) * b == N)
		return 1;
	else
		return 0;
}
 
int main()
{
	int p,i;
	while (1) {
		scanf("%d", &N);
		if (N == 0)
			break;
		else if (N == 1) {
			printf("%d %d\n", N, 1);
			continue;
		}
			
		int sqrtN = int(sqrt((double)N));
		int temp = N;
		p,i = 0;
		for (p = 1; p <= sqrtN; ++p) {
			if (temp % p == 0) {
				divisors[i++] = p;
				int div = temp / p;
				if (p != div)
					divisors[i++] = div;
			}
		}
		int k, _count = 0;
		for (k = 1; k < i - 1; k++) {
			for (p = k + 1; p < i; p++) {
				int result = lcm(divisors[k], divisors[p]);
				if (result)
					_count++;
			}
		}
		printf("%d %d\n", N, _count + 2);
	}
	return 0;
}

