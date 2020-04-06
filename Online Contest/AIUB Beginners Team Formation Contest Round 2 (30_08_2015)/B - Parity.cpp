// B - Parity.cpp
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
	int num, divisor, remainder, i, count, c, testCase, _case = 1;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d", &num);
		i = 0;
		count = 0;
		c = num;
		while (num > 0) {
			divisor = num / 2;
			remainder = num % 2;

			if (remainder == 1)
				count++;
			i++;
			num = divisor;
		}
		if (count % 2 == 0)
			printf("Case %d: even\n", _case);
		else
			printf("Case %d: odd\n", _case);
		_case++;
	}
	return 0;
}

