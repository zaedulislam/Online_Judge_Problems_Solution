// LightOJ 1015 - Brush (I).cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
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
	int testCase,numStudents,unitDust,_case = 1;
	scanf("%d", &testCase);
	while (testCase--) {
		int totalDust = 0;
		
		scanf("%d", &numStudents);

		int I;
		for (I = 0; I < numStudents; I++) {
			scanf("%d", &unitDust);
			if (unitDust < 0)
				continue;
			totalDust += unitDust;
		}
		printf("Case %d: %d\n", _case++,totalDust);
	}
	return 0;
}
