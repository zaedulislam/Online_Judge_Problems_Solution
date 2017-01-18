// UVa 11728 - Alternate Task.cpp
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

const int arraySize = 1010;

int status[arraySize];
int prime[arraySize];
int primeFactor[arraySize];
int primePower[arraySize];
int sumFact[arraySize];

void cachePrime()
{
	status[0] = status[1] = 1;
	int sqrtN = int(sqrt((double)arraySize));
	for (int i = 2; i <= sqrtN; i++) {
		if (status[i] == 0) {
			for (int j = i * i; j <= arraySize; j += i)  // or j+=i+i
				status[j] = 1;
		}
	} // Loop Ends
	int k = 0;
	prime[k++] = 2;
	for (int i = 3; i <= arraySize; i += 2) {
		if (status[i] == 0)
			prime[k++] = i;
	}
}

inline int _pow(int base, int power)
{
	int i;
	int result = base;
	for (i = 0; i < power - 1; i++) {
		result = result * base;
	}
	return result;
}

int  primeFactorize(int n)
{
	int sqrtN = int(sqrt((double)n));
	int i, index = 0;
	for (i = 0; prime[i] <= sqrtN; i++) {
		int countPower = 0;
		if (n % prime[i] == 0) {
			primeFactor[index] = prime[i];
			while (n % prime[i] == 0) {
				n /= prime[i];
				countPower++;
			}
			primePower[index++] = countPower;
		}
	}
	if (n > 1) {
		primeFactor[index] = n;
		primePower[index++] = 1;

	}
	int SOD = 1;
	int k;
	for (k = 0; k < index; k++)
		SOD = SOD * ((_pow(primeFactor[k], primePower[k] + 1) - 1) / (primeFactor[k] - 1));
	return SOD;
}


int main()
{
	cachePrime();
	int pos_integer, sum, _case,max;
	bool isExist;
	int i;
	for (i = 1; i <= 1000; i++) {
		if (status[i] == 0) {
			sumFact[i] = i + 1;
			continue;
		}
		sum = primeFactorize(i);
		sumFact[i] = sum;
	}
	_case = 1;
	while (true) {
		scanf("%d", &pos_integer);
		if (pos_integer == 0)
			break;
		printf("Case %d: ", _case);
		int k;
		isExist = false;
		for (k = 0; k < 1000; k++) {
			if (sumFact[k] == pos_integer) {
				max = k;
				isExist = true;
			}
		}
		if(isExist)
			printf("%d\n", max);
		else
			printf("-1\n");
		_case++;
	}

	return 0;
}



