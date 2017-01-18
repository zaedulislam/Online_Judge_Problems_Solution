// LightOJ 1182 - Parity.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef long long ll;
using namespace std;

int main()
{
	int num, quotient, remainder,_count,testCase, _case = 1;
	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%d", &num);
		_count = 0;

		while (num > 0) {
			remainder = num % 2;
			if (remainder == 1)
				_count++;
			num >>= 1;			
		}

		if (_count % 2 == 0)
			printf("Case %d: even\n", _case);
		else
			printf("Case %d: odd\n", _case);
		_case++;
	}
	return 0;
}

