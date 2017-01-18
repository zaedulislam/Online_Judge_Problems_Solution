// UVa 11984 - A Change in Thermal Unit.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
using namespace std;


int main()
{
	int testCase,_case = 1;
	double celsius,fahrenheit;

	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%lf%lf",&celsius,&fahrenheit);
        fahrenheit = ( 9 * celsius) / 5 + 32 + fahrenheit;
		celsius = ((fahrenheit - 32) * 5) / 9;

		printf("Case %d: %0.2lf\n",_case++,celsius);

	}

	return 0;
}


