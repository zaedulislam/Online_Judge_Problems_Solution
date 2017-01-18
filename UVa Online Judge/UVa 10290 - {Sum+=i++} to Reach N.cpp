//UVa 10290 - {Sum+=i++} to Reach N.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

const int arraySize = 3000001;
int status[arraySize];
int prime[arraySize];
int maxIndex = 0;


void sieve()
{
	int sqrtN = int(sqrt((double)arraySize));
	for (int i = 3; i <= sqrtN; i += 2){
		if (status[i] == 0){
			for (int j = i * i; j <= arraySize; j += 2 * i)  // or j+=i+i
				status[j] = 1;
		}
	} // Loop Ends
	int k = 0;
	prime[k++] = 2;
	for (int i = 3; i <= arraySize; i += 2){
		if (status[i] == 0)
			prime[k++] = i;
	}
	 maxIndex = k ;
}

long long int sumConsecutive(long long int num)
{
	long long result = 1, _count;
	int sqrtN = int (sqrt((double)num));
	long long int p;
	for (p = 0;  p < maxIndex  && prime[p] <= sqrtN; ++p) {
		_count = 0;
		if (num % prime[p] == 0) {
			while (num % prime[p] == 0) {
				num /= prime[p];
				_count++;
			}
			sqrtN = int(sqrt((double)num));  // With this statement Run Time : 0.176    &&
			if (prime[p] % 2 == 1)                 // Without this statement Run Time : 0.596
				result *= (_count + 1);
		}
	}
	if (num > 1)
		result *= 2;
	return result;
}

int main()
{
	sieve();
	long long int num;
	while (scanf("%lld", &num) != EOF) {
		if (num == 0) {
			printf("0\n");
			continue;
		}
		else if (num == 1 || num == 2) {
			printf("1\n");
			continue;
		}
		else
			printf("%lld\n", sumConsecutive(num));
	}
	return 0;
}

