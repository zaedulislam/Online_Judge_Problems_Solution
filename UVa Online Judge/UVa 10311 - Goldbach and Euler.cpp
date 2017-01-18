// UVa 10311 - Goldbach and Euler.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef unsigned long long llu;

using namespace std;

const int arraySize = 1e8 + 10;
int status[arraySize];
int prime[arraySize];

void sieve()
{
	int sqrtN = int(sqrt((double)arraySize));
	status[0] = 1;
	status[1] = 1;
	int I,K ;
	for (I = 2; I <= sqrtN; I++ ) {
		if (!status[I]) {
			for (K = I * I; K <= arraySize; K += I)
				status[K] = 1;
		}
	}
}


int main()
{
	sieve();
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n < 3) {
			printf("%d is not the sum of two primes!\n", n);
			continue;
		}
		else if (n % 2 == 1) {
			if (!status[n - 2])
				printf("%d is the sum of %d and %d.\n",n, 2, n -2);
			else
				printf("%d is not the sum of two primes!\n", n);
		}
		else if (n % 2 == 0) {
			bool flag = false;
			int I, X = 0;
			for (I = n / 2; I < n ; I++) {
				if (!status[(n / 2) - X] && !status[I] && ((n / 2) - X !=I)) {
					printf("%d is the sum of %d and %d.\n", n, n - I, I);
					flag = true;
					break;
				}
				X++;
			}
			if(!flag)
				printf("%d is not the sum of two primes!\n", n);
		}
	}
	return 0;
}