// UVa 10407 - Simple division.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

const int arraySize = 1005;
int diff[arraySize];

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
	
	if (divident == 0) 
		return divisor;
	if (divisor == 0)
		return divident;

	while (remainder != 0) {
  		quotient = divident / divisor;
		remainder = divident % divisor;
		divident = divisor;
		divisor = remainder;
	}
	return divident;
}

int main()
{
	int N,temp,i;
	while (1) {
		i = 1;
		scanf("%d", &N);
		if (N == 0)
			break;

		while (1) {
			scanf("%d", &temp);
			if (temp == 0)
				break;

			diff[i] = N - temp;
			N = temp;
			if (diff[i] < 0)
				diff[i] = -1 * diff[i];
			i++;
		}
		diff[i] = -1;
		int res;
		for (i = 0; diff[i + 1] != -1; i++) {
			res = gcd(diff[i], diff[i + 1]);
			diff[i + 1] = res;
		}
		printf("%d\n", res);
	}
	memset(diff, 0, sizeof(diff));
	return 0;
}