// UVa 10018 -  Reverse and Add.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	long long int num,temp,numReverse,_countIt;

	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%lld", &num);
		temp = num;
		
		_countIt = 0;
		while (1) {
			numReverse = 0;
			while (temp != 0) {
				numReverse = numReverse * 10 + temp % 10;
				temp /= 10;
			}
			if (num == numReverse)
				break;
			else {
				temp = numReverse + num;
				num = numReverse + num;
				_countIt++;
			}
		}
		printf("%lld %lld\n", _countIt,num);
	}
	return 0;
}


