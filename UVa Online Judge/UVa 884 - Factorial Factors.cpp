 // UVa 884 - Factorial Factors.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int arraySize = 1e6;
int factors[arraySize];


int factorialFactors(int num)
{
	int i,_count = 0;
	for (i = 2; i <= num / i; ++i) {
		if (num % i == 0) {
			while (num % i == 0) {
				num /= i;
				_count++;
			}
		}
	}
	if (num > 1)
		_count++;
	return _count;
}

int main()
{
	int i;
	for (i = 2; i <= arraySize; i++)
		factors[i] = factorialFactors(i) + factors[i - 1];
	int n;
	while (scanf("%d", &n) != EOF){
		printf("%d\n", factors[n]);
	}
	return 0;
}
