// LightOJ 1311	- Unlucky Bird.cpp
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	int testCase,_case = 1;
	double v1, v2, v3, a1, a2;
	double time1, time2, d, disCovered,t;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%lf%lf%lf%lf%lf", &v1, &v2, &v3, &a1, &a2);
		printf("Case %d: ", _case);
		time1 = v1 / a1;
		time2 = v2 / a2;
		d = ((v1 * time1) - .5 * a1 * time1 * time1) + ((v2 * time2) - .5 * a2 * time2 * time2);
		 
		if (time1>time2)
			t = time1;
		else
			t = time2;
		disCovered = t*v3;
		printf("%lf %lf\n", d,disCovered);
		_case++;
	}
	return 0;
}