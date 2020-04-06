// B. BatMobile.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
typedef unsigned long long llu;

using namespace std;

int main()
{
	int testCase,_case = 1;
	double u, v, time;
	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%lf%lf%lf", &u, &v, &time);
		double acceleration = (v - u) / time;
		printf("Case %d: %0.3lf\n", _case++, u * time + 0.5 * acceleration * time * time);
	}
	return 0;
}