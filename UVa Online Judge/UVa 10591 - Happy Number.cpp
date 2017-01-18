// UVa 10591 - Happy Number.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

inline long long int _pow(long long int base,long long int power)
{
	long long int i;
	long long int result = base;
	for (i = 0; i < power - 1; i++) {
		result = result * base;
	}
	return result;
}

int main()
{
	long long int N,digSum,temp;
	int testCase,_case = 1;
	scanf("%d", &testCase);

	while (testCase--) {
		scanf("%lld",&N);
		/*if (N % 2== 0) {
			printf("Case #%d: %d is an Unhappy number.\n", _case, N);
			_case++;
			continue;
		}*/
		temp = N;
		while (1) {
			digSum = 0;
			while (temp != 0) {
				digSum += _pow((temp % 10),2);
				temp /= 10;
			}
			temp = digSum;
			if (temp <= 9)
				break;
		}
		if (temp == 1 || temp == 7)
			printf("Case #%d: %d is a Happy number.\n", _case, N);
		else 
			printf("Case #%d: %d is an Unhappy number.\n", _case, N);
		
		_case++;
	}
	return 0;
}

