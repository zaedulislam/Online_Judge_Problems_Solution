// ID 25311 -  Candies.cpp
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
	int totalCandy;
	scanf("%d", &testCase);
	
	while (testCase--) {		
		scanf("%d", &totalCandy);
		
		if (totalCandy < 8) {
			printf("Case %d: %d\n", _case++, -1);
			continue;
		}

		int sami = 5;
		bool possible = false;
		
		while (totalCandy >= sami ) {
			int sara = totalCandy - sami;
			if (sara % 3 == 0) {
				printf("Case %d: %d\n", _case++, sara);
				possible = true;
				break;
			}
			sami += 5;
		}
		if(!possible)
			printf("Case %d: %d\n", _case++, -1);

	}
	return 0;
}