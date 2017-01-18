// UVa 11827 - Maximum GCD.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
using namespace std;

int const _size = 1005;
int arr[_size];
char str[_size];

inline int gcd(int a, int b)
{
	int divident, divisor, remainder = -1;
	if (a > b) {
		divident = a;
		divisor = b;
	}
	else {
		divisor = a;
		divident = b;
	}
	while (remainder != 0) {
		remainder = divident % divisor;
		divident = divisor;
		divisor = remainder;
	}
	return divident;
}

int main()
{
	int testCase, N;
	char iFalse;
	scanf("%d%c", &testCase, &iFalse);
	while (testCase--) {

		fgets(str, _size, stdin);
		int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;

		int maxGCD = 0;
		int I, K, X = 0;

		stringstream ss(str);
		while (ss >> arr[X++]) {}

		for (I = 0; I < X - 1; I++) {
			for (K = I + 1; K < X - 1; K++) {
				int temp = gcd(arr[I], arr[K]);
				if (temp > maxGCD)
					maxGCD = temp;
			}
		}
		printf("%d\n", maxGCD);
	}
	return 0;
}

