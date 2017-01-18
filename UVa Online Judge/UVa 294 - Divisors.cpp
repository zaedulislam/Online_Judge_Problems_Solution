// UVa 294 - Divisors.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#define ll long long 
using namespace std;

void divisors(int lower,int upper)
{
	int temp, _count, max = 0, N, NOD;
	if (lower == 1 && upper == 0)
	{
		printf("Between 1 and 0, 0 has a maximum of 2 divisors.\n");
		return;
	}
	int n;
	for (n = lower; n <= upper; n++) {
		int sqrtN = int(sqrt((double)n));
		temp = n;
		NOD = 1;
		
		int p;
		for (p = 2; p <= sqrtN; ++p) {
			_count = 0;
			if (temp % p == 0) {
				while (temp % p == 0) {
					temp /= p;
					_count++;
				}
				NOD *= (_count + 1);   
			}
		}
		if (temp > 1)
			NOD *= 2;
		if (NOD > max) {
			max = NOD;
			N = n;
		}
	}
	printf("Between %d and %d, %d has a maximum of %d divisors.\n", lower, upper, N, max);
}

int main()
{
	int testCase,lower,upper;
	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%d%d", &lower, &upper);
		divisors(lower, upper);
	}

	return 0;
}