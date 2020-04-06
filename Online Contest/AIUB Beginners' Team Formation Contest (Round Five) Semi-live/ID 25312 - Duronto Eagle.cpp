// ID 25312 - Duronto Eagle.cpp
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
	
	scanf("%d", &testCase);
	int totalPlanet;
	double x2, y2;
	while (testCase--) {		
		scanf("%d", &totalPlanet);
		
		int I,K = 0;
		double max = 0;
		for (I = 0; I < totalPlanet; I++) {
			scanf("%lf%lf", &x2, &y2);
			x2 = x2 * x2;
			y2 = y2 * y2;
			if (max < sqrt(x2 + y2)) {
				max = sqrt(x2 + y2);
				K = I + 1;
			}

		}
		printf("Case %d: %d\n", _case++,K);
	}
	return 0;
}