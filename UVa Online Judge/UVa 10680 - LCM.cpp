// UVa 10680 - LCM.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

const int arraySize = 1e6;
int status[arraySize];
int prime[arraySize];
int maxIndex;

void sieve()
{
	int sqrtN = int(sqrt((double)arraySize));
	for (int i = 3; i <= sqrtN; i += 2) {
		if (status[i] == 0) {
			for (int j = i * i; j <= arraySize; j += 2 * i)  // or j+=i+i
				status[j] = 1;
		}
	}
	int k = 0;
	prime[k++] = 2;
	for (int i = 3; i <= arraySize; i += 2) {
		if (status[i] == 0)
			prime[k++] = i;
	}
	maxIndex = k;
	int temp = prime[2];
	prime[2] =prime[1];
	prime[1] = temp;
}

int main()
{
	sieve();
	int N, res, _count2, _count5;
	while (scanf("%d", &N) != EOF) {
		if (N == 0)
			break;

		res = 1;
		_count2 = _count5 = 0;
		int i;
		for (i = 2; i <= N; i *= 2)
			_count2++;
		for (i = 5; i <= N; i *= 5)
			_count5++;

		for (i = 0; i < _count2 - _count5; ++i)
			res = (res * 2) % 10;

 		for (i = 2; i < maxIndex; ++i) {
			if (prime[i] > N)
				break;
			for (long long int p = prime[i]; p <= N; p *= prime[i])
				// (a * b) % m = {(a % m) * (b % m)} % m
				res = (res * prime[i]) % 10;
		}
		printf("%d\n", res);
	}
	return 0;
}