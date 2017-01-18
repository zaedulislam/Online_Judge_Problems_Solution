// UVa 10783 - Odd Sum.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;


int main()
{
	int testCase,a,b,sum,_case = 1;
	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%d%d", &a, &b);
		sum = 0;
		int i;
		for (i = a; i <= b; i++) {
			if (i % 2 != 0)
				sum += i;
		}
		printf("Case %d: %d\n",_case,sum);
		_case++;
	}
	return 0;
}

