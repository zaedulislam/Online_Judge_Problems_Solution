// UVa 11479 - Is this the easiest problem?.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
typedef long long ll;
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;


int main()
{
	int testCase,_case = 1;
	ll s1,s2,s3;
	scanf("%lld",&testCase);

	while(testCase--){
		int _count = 0;
		scanf("%lld%lld%lld",&s1,&s2,&s3);

		if((s1 + s2 > s3) && (s2 + s3 > s1) && (s1 + s3 > s2)){
			if(s1 == s2 && s2 == s3 && s3 == s1)
				printf("Case %d: Equilateral\n",_case++);
			if(s1 == s2)
				_count++;
			if(s2 == s3)
				_count++;
			if(s1 == s3)
				_count++;
			if(_count == 1)
				printf("Case %d: Isosceles\n",_case++);

			if(_count == 0)
				printf("Case %d: Scalene\n",_case++);
				}
		else
			printf("Case %d: Invalid\n",_case++);
		}
	return 0;
	}

